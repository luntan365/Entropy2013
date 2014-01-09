/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef ENTROPYROBOTDRIVE_H_
#define ENTROPYROBOTDRIVE_H_

#include "drivetable_fast_lookup.h"
#include "WPILib.h"
#include "NetworkCommunication/UsageReporting.h"

/**
 * Utility class for handling Robot drive based on a definition of the motor configuration.
 * The robot drive class handles basic driving for a robot. Currently, 2 and 4 motor standard
 * drive trains are supported. In the future other drive types like swerve and meccanum might
 * be implemented. Motor channel numbers are passed supplied on creation of the class. Those are
 * used for either the Drive function (intended for hand created drive code, such as autonomous)
 * or with the Tank/Arcade functions intended to be used for Operator Control driving.
 */
class EntropyRobotDrive: public RobotDrive
{
public:

	EntropyRobotDrive(SpeedController *frontLeftMotor, SpeedController *rearLeftMotor,
				SpeedController *frontRightMotor, SpeedController *rearRightMotor);
	virtual ~EntropyRobotDrive(){};
	void EntropyRobotDrive::ArcadeDrive(GenericHID *stick);
	void EntropyRobotDrive::ArcadeDrive(float speed, float radius);
	
	
private:	
	
	typedef enum
	{
		Radius = 0,
		Rotate
	}DriveMode;
	
	void ArcadeDrive(float moveValue,  float rotateValue, DriveMode mode);
	float absolutevalue(float x);
	bool range(float x, float y, float maxthreshold);
	float drive_table_limit(float x, float max, float min);
	void get_index(int &x_index, int &y_index, float moveValue, float rotateValue, DriveMode mode);
	float left_scale(float rotateValue, float moveValue, DriveMode mode);
	float right_scale(float rotateValue, float moveValue, DriveMode mode);
};

#endif

