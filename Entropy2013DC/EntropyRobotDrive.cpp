#include "EntropyRobotDrive.h"
#include "NetworkCommunication/UsageReporting.h"
#include <math.h>
/**
 * Constructor for RobotDrive with 4 motors specified as SpeedController objects.
 * Speed controller input version of RobotDrive (see previous comments).
 * @param rearLeftMotor The back left SpeedController object used to drive the robot.
 * @param frontLeftMotor The front left SpeedController object used to drive the robot
 * @param rearRightMotor The back right SpeedController object used to drive the robot.
 * @param frontRightMotor The front right SpeedController object used to drive the robot.
 */
EntropyRobotDrive::EntropyRobotDrive(SpeedController *frontLeftMotor, SpeedController *rearLeftMotor,
						SpeedController *frontRightMotor, SpeedController *rearRightMotor) : 
						RobotDrive(frontLeftMotor, rearLeftMotor, frontRightMotor, rearRightMotor)
{

}

float EntropyRobotDrive::absolutevalue(float x)
{
	if (x < 0.0) 
	{
		x = x*-1.0;
	}
	return x;
}

bool EntropyRobotDrive::range(float x, float y, float z) 
{  
   return (((y <= x) && (x <= z)) || ((y >= x) && (x >= z)));
}

float EntropyRobotDrive::drive_table_limit(float x, float max, float min)
{
	if(x > max)
	{
		return max;
	}
	else if(x < min)
	{
		return min;
	}
	else
	{
		return x;
	}
}


void EntropyRobotDrive::get_index(int &x_index, int &y_index, float moveValue, float rotateValue, DriveMode mode)
{
	float rotate = 0;
	float move = 0;
	float minRotate = 0;
	float maxRotate = 0;
	const float *arrayPtr = 0;
	unsigned int arrayLength = 0;
	float diff1 = 0;
	float diff2 = 0;
	
	if(mode == Radius)
	{
		arrayPtr = left_lookup_radius;
		arrayLength = 18;//sizeof(left_lookup_radius)/sizeof(float);
		minRotate = arrayPtr[16];
		maxRotate = arrayPtr[15];
	}
	else /*Rotate*/
	{
		arrayPtr = left_lookupx;
		arrayLength = sizeof(left_lookupx)/sizeof(float);
		minRotate = arrayPtr[0];
		maxRotate = arrayPtr[arrayLength-1];
	}
	
	rotate = drive_table_limit(rotateValue, maxRotate, minRotate);

	for(unsigned int i = 0; i < arrayLength; i++) 
	{
		if(i+1 >= arrayLength || range(rotate, arrayPtr[i], arrayPtr[i+1]))
		{
			//Assume match found
			if((i + 1) >= arrayLength)
			{
			   x_index = i;	
			}
			else
			{
				diff1 = fabs(rotate - arrayPtr[i]);
				diff2 = fabs(rotate - arrayPtr[i+1]);
				
				if(diff1 < diff2)
				{
					x_index = i;
				}
				else
				{
					x_index = i + 1;
				}
			}
			break;
		}
	}

    arrayLength = (sizeof(left_lookupy)/sizeof(float));
	move = drive_table_limit(moveValue, left_lookupy[32], left_lookupy[0]);
	
	for(unsigned int i = 0; i < arrayLength; i++) 
	{
		if(i+1 >= arrayLength || range(move, left_lookupy[i], left_lookupy[i+1]))
		{
			//Assume match found
			if((i + 1) >= arrayLength)
			{
			   y_index = i;	
			}
			else
			{
				diff1 = fabs(move - left_lookupy[i]);
				diff2 = fabs(move - left_lookupy[i+1]);
				
				if(diff1 < diff2)
				{
					y_index = i;
				}
				else
				{
					y_index = i + 1;
				}
			}
			break;
		}
	}
}

/* search left drive table using binary search */
/* Input:   x_value  (rotate)*/
/*          y_value  (move -forward/backward)*/
/*          slow_mo  if true, scale output - not being done */
/* return: left scale_value */
float EntropyRobotDrive::left_scale(float rotateValue, float moveValue, DriveMode mode)
{
	int x_index = 0;
	int y_index = 0;
	float temp_drive = 0;
	int x_idx = 0;
	float absRotate = rotateValue;
	
	if(mode == Radius)
	{
		absRotate = fabs(rotateValue);
	}	
	
	get_index(x_index, y_index, moveValue, absRotate, mode);
	
	if(mode == Rotate)
	{
		x_idx = x_index;
	}
	else
	{
		if(rotateValue < 0)
		{
			x_idx = 32-x_index;
		}
		else
		{
			x_idx = x_index;
		}
		
	}
	
	temp_drive = left_fast_njxy[y_index][x_idx];
    

	return temp_drive;
}

/* search right drive table using binary search if axis index tables */
/* Input:   x_value  (rotate)*/
/*          y_value  (move -forward/backward)*/
/*          slow_mo  if true, scale output - not being done */
/* return: left scale_value */
float EntropyRobotDrive::right_scale(float rotateValue, float moveValue, DriveMode mode)
{
	int x_index = 0;
	int y_index = 0;
	float temp_drive = 0;
	int x_idx = 0;
	float absRotate = rotateValue;
	
	if(mode == Radius)
	{
		absRotate = fabs(rotateValue);
	}

	get_index(x_index, y_index, moveValue, absRotate, mode);
	
	temp_drive = left_fast_njxy[y_index][32-x_index];

	if(mode == Rotate)
	{
		x_idx = 32-x_index;
	}
	else
	{
		if(rotateValue < 0)
		{
			x_idx = x_index;
		}
		else
		{
			x_idx = 32-x_index;
		}
	}
	
	temp_drive = left_fast_njxy[y_index][x_idx];
	
  
	return temp_drive;
}


/**
 * Arcade drive implements single stick driving.
 * Given a single Joystick, the class assumes the Y axis for the move value and the X axis
 * for the rotate value.
 * (Should add more information here regarding the way that arcade drive works.)
 * @param stick The joystick to use for Arcade single-stick driving. The Y-axis will be selected
 * for forwards/backwards and the X-axis will be selected for rotation rate.
 * @param slow_mo If true, the sensitivity will be increased for small values
 */
void EntropyRobotDrive::ArcadeDrive(GenericHID *stick)
{
	// simply call the full-featured ArcadeDrive with the appropriate values
	ArcadeDrive(stick->GetY(), stick->GetX(), Rotate);
}

void EntropyRobotDrive::ArcadeDrive(float speed, float radius)
{
	// simply call the full-featured ArcadeDrive with the appropriate values
	ArcadeDrive(speed, radius, Radius);
}

/**
 * Arcade drive implements single stick driving.
 * This function lets you directly provide joystick values from any source.
 * @param moveValue The value to use for fowards/backwards
 * @param rotateValue The value to use for the rotate right/left
 * @param slow_mo If set, increases the sensitivity at low speeds
 */
void EntropyRobotDrive::ArcadeDrive(float moveValue, float rotateValue, DriveMode mode)
{
	static bool reported = false;

	if (!reported)
	{
		nUsageReporting::report(nUsageReporting::kResourceType_RobotDrive, 4, nUsageReporting::kRobotDrive_ArcadeStandard);
		reported = true;
	}

	// local variables to hold the computed PWM values for the motors
	float leftMotorOutput;
	float rightMotorOutput;
    float left_pwm, right_pwm;
	
    if(mode != Radius)
    {
    	moveValue = Limit(moveValue);     // y value
    	rotateValue = Limit(rotateValue); // x value
    }
	

    /* do tablelook ups here */
    left_pwm = left_scale(rotateValue, moveValue, mode);
    leftMotorOutput = left_pwm;

    right_pwm = right_scale(rotateValue, moveValue, mode);
    rightMotorOutput = right_pwm;
	SetLeftRightMotorOutputs(leftMotorOutput, rightMotorOutput);
	
#if 0
    DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line1, 1, "MV %f", moveValue);
    DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line2, 1, "RV %f", rotateValue);
    DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line3, 1, "LM %f", leftMotorOutput);
    DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line4, 1, "RM %f", rightMotorOutput);
#endif
    DriverStationLCD::GetInstance()->UpdateLCD();
}
