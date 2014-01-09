#include "OI.h"
#include "Commands/Move.h"
#include "Commands/ElevateDown.h"
#include "Commands/ElevateUp.h"
#include "Commands/TurnLeft.h"
#include "Commands/TurnRight.h"
#include "Commands/FireDisk.h"
#include "Commands/PickupSysOn.h"
#include "Commands/PickupSysOff.h"

#include "Commands/TimedElevationDown.h"
#include "Commands/SetElevationPosition.h"
#include "Commands/SetAzimuthPosition.h"
#include "Commands/FeederHomePos.h"




#include "Subsystems/Shooter.h"
#include <math.h>

#define DRIVERSTICKPORT     1
#define GAMEPADPORT		2
#define EPSILON_AZ .01
#define EPSILON_EL .01

#define LOWSPEED    0.90
#define MEDIUMSPEED 0.95
#define HIGHSPEED	1.00
#define OFFSET_SPEED	0.05 



OI::OI() {
	joystick = new Joystick(DRIVERSTICKPORT);
	m_pNykoGmPad = new Joystick(GAMEPADPORT);
	m_pNykoGPbutton1 = new JoystickButton(m_pNykoGmPad, 1);
	m_pNykoGPbutton2 = new JoystickButton(m_pNykoGmPad, 2);
	m_pNykoGPbutton3 = new JoystickButton(m_pNykoGmPad, 3);
	m_pNykoGPbutton4 = new JoystickButton(m_pNykoGmPad, 4);
	m_pNykoGPbutton5 = new JoystickButton(m_pNykoGmPad, 5);
	m_pNykoGPbutton6 = new JoystickButton(m_pNykoGmPad, 6);
	m_pNykoGPbutton7 = new JoystickButton(m_pNykoGmPad, 7);
	m_pNykoGPbutton8 = new JoystickButton(m_pNykoGmPad, 8);
	m_pNykoGPbutton9 = new JoystickButton(m_pNykoGmPad, 9);
	m_pNykoGPbutton10 = new JoystickButton(m_pNykoGmPad, 10);
	m_pNykoGPbutton11 = new JoystickButton(m_pNykoGmPad, 11);

	// button event handlers ...
	
	// as of 3/17/13 these buttons are unused .... 1,2,3,4,7,8
	
	
	// I'm putting these defines here during debug because it speeds up build time - upon
	// completion they belong in robot.h
	

	
	// Button 1 - sets elevation at feeder station feed elevation
	
	m_pNykoGPbutton1->WhenPressed(new SetElevationPosition(SETPT_EL_WHEN_FEEDING));

	// Button 2 -  sets elevation at elevation for shooting at feeder station
	
	m_pNykoGPbutton2->WhenPressed(new SetElevationPosition(SETPT_EL_SHOOT_AT_FEEDER));
	
	// Button 3 -  sets elevation for opponents pyramid
	
	m_pNykoGPbutton3->WhenPressed(new SetElevationPosition(SETPT_EL_OPPONENT_PYRAMID));
	
	// Button 4 -  for midfield
	
	m_pNykoGPbutton4->WhenPressed(new SetElevationPosition(SETPT_EL_MIDFIELD));
	

	
	// TODO - make but 1 and 2 a cmd grp that is fired on 1 press of but
	
	// Button 1 - set azimuth at feeder station feed azimuth
	
	// don't enable until you have sensor input min.max values known
	
	//m_pNykoGPbutton3->WhenPressed(new SetAzimuthPosition());
	
	// when debugged try this cmd grp
	//m_pNykoGPbutton1->WhenPressed(new FeederHomePos());
	

	

	
	
	
	
	



	m_pNykoGPbutton6->WhenPressed(new FireDisk(m_pNykoGPbutton5));
	m_pNykoGPbutton7->WhenPressed(new PickupSysOff());
	m_pNykoGPbutton8->WhenPressed(new PickupSysOn());

	lastspeed = HIGHSPEED;
	
	// start off with "undefined" last readings
	m_LastAzimuthReading = 12345.0f;
	m_LastElevationReading = 12345.0f;
	
	// TODO: move usage inside an ifdef clause
    m_oldButtonsState = 12345.0f;
    m_oldRighty = 12345.0f;
    m_oldGetDPadx = 12345.0f;
    m_oldGetDPady = 12345.0f;
    m_tmpButval = 0;
    tmp1 = 12345.0f;
    tmp2 = 12345.0f;
    tmp3 = 12345.0f;
    tmp4 = 12345.0f;
    tmp5 = 12345.0f;
}

Joystick* OI::getJoystick() {
	return joystick;
}

void OI::ProcessGamePadInput() 
{
	float NewAzimuthReading;
	float NewElevationReading;
	
	// remove if you don't want PID value dispalyed

	DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line4, 1, "AzPos %4.2f - %4.2f", RobotMap::m_pAzimuthPosition->GetVoltage(), RobotMap::m_pAzimuthPosition->PIDGet());
	DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line5, 1, "ElPos %4.2f - %4.2f", RobotMap::m_pAccelerometerElPos->GetVoltage(), RobotMap::m_pAccelerometerElPos->PIDGet());
	
	// original code

	//DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line4, 1, "AzPos %4.2f", RobotMap::m_pAzimuthPosition->GetVoltage());
	//DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line5, 1, "ElPos %4.2f", RobotMap::m_pAccelerometerElPos->GetVoltage());

			
	if (m_pNykoGPbutton8->Get() == 1) {
		printf("picking up");
	}
	
	// Process azimuth
	NewAzimuthReading = m_pNykoGmPad->GetAxis(Joystick::kTwistAxis);
	if (fabs(NewAzimuthReading - m_LastAzimuthReading) > EPSILON_AZ)
	{
		if(NewAzimuthReading > .2)  {
			Robot::m_pTurnleftCommand->Start();
		}
		else if(NewAzimuthReading < -.2)  {
			Robot::m_pTurnrightCommand->Start();
		}
		else {
			Robot::m_pStopAzimCommand->Start();
		}
		m_LastAzimuthReading = NewAzimuthReading;
	}

	// Process elevation 
	NewElevationReading = m_pNykoGmPad->GetAxis(Joystick::kYAxis);
	if (fabs(NewElevationReading - m_LastElevationReading) > EPSILON_EL)
	{
		// currently flipped vs competition robot
		if(NewElevationReading > .2)  
		{
			Robot::m_pElevatedownCommand->Start();
		}
		else if(NewElevationReading < -.2)  
		{
			Robot::m_pElevateupCommand->Start();
		}
		else 
		{
			Robot::m_pStopElevCommand->Start();
		}
		m_LastElevationReading = NewElevationReading;
	}
	
	// Game pad button 9 = LOW	
	if(m_pNykoGPbutton9->Get() == 1)
		lastspeed = LOWSPEED;
	
	// Game pad button 10 = HIGH
	if(m_pNykoGPbutton11->Get() == 1)
		lastspeed = HIGHSPEED;
	
	// Game pad button 11 = MEDIUM
	if(m_pNykoGPbutton10->Get() == 1)
		lastspeed = MEDIUMSPEED;


	// button 5 - when pressed => shooter motors on
	if(m_pNykoGPbutton5->Get() == 1)
	{		
		Robot::shooter->Shoot( lastspeed, 1 );
		Robot::shooter->Shoot( lastspeed - OFFSET_SPEED, 2 );
	}
	else
	{	
		Robot::shooter->Stop();
	}
}
