#include "Robot.h"
#include "Commands/Autonomous.h"
#include "Commands/StopElevate.h"
#include "Commands/StopAzimuth.h"
#include "Commands/ElevateDown.h"
#include "Commands/ElevateUp.h"
#include "Commands/TurnLeft.h"
#include "Commands/TurnRight.h"
#include "Commands/Auto1.h"
#include "Commands/AutoFireDisk.h"
#include "Commands/AutoFireDiskDrive.h"

Drive*              Robot::drive = 0;
OI* 				Robot::m_pOperatorInterface	= 0;
ElControl*          Robot::elcontrol = 0;
AzControl*          Robot::azcontrol = 0;
PIDController*		Robot::m_pElevationPIDcontroller = 0;
PIDController*		Robot::m_pAzimuthPIDcontroller = 0;
ShootSolenoid*      Robot::shootsolenoid = 0;
Shooter*            Robot::shooter = 0;
PickupSystem*		Robot::m_pickupSystem = 0;
CameraTilt*			Robot::m_pCamTiltSys = 0;
Command*			Robot::m_pStopElevCommand = 0;
Command*			Robot::m_pStopAzimCommand = 0;	
Command*			Robot::m_pTurnrightCommand = 0;
Command*			Robot::m_pTurnleftCommand = 0;
Command*			Robot::m_pElevateupCommand = 0;
Command*			Robot::m_pElevatedownCommand = 0;
Command*            Robot::m_pStopShooterCommand = 0;
Command*            Robot::m_pAutonomousCommand1 = 0;
Command*            Robot::m_pAutonomousCommand2 = 0;
Command*            Robot::m_pAutonomousCommand3 = 0;
Command*            Robot::m_pAutonomousCommand4 = 0;
Command*            Robot::m_pAutonomousCommand5 = 0;
Command*            Robot::m_pAutonomousCommand6 = 0;
Command*            Robot::m_pAutonomousCommand7 = 0;
Command*            Robot::m_pAutonomousCommand8 = 0;
Command*            Robot::m_pAutonomousCommand9 = 0;
Command*            Robot::m_pAutonomousCommand = 0;
CommandGroup*		Robot::m_pAuto1 = 0;
bool                Robot::m_motors_spinning = false;

// Most important file: robot.cpp
// Most important method(function) - robotinit

// Our robot code starts here with roboinit 

	
void Robot::RobotInit() {
	RobotMap::init();
	
	m_motors_spinning = false;
	
	printf("Creating subsystems\n");
	drive			= new Drive();
	elcontrol		= new ElControl();
	azcontrol		= new AzControl();
	shooter			= new Shooter();
	shootsolenoid	= new ShootSolenoid();
	m_pickupSystem	= new PickupSystem();
	m_pCamTiltSys	= new CameraTilt();
	
	// create PID controllers
	
	ConstructElevatorPID();
	ConstructAzimuthPID();
	
	// create OI after all subsystems have been created ...

	// Cmds usually "require" a certain subsystem(s). Make sure all subsystems are 
	// created before any cmds are created (if you don't you'll have null ptrs in the "requires" operation)
	
	// Typically, the operator interface creates commands which are to be scheduled when
	// an operator interaction occurs - more details in the constructor

	m_pOperatorInterface = new OI();
		
	// Instantiate commands we will use
	
	m_pStopElevCommand = new StopElevate();
	m_pStopAzimCommand = new StopAzimuth();
	m_pTurnrightCommand = new TurnRight();
	m_pTurnleftCommand = new TurnLeft();
	m_pElevateupCommand = new ElevateUp();
	m_pElevatedownCommand = new ElevateDown();
	m_pAutonomousCommand1 = new AutonomousCommand1();
	m_pAutonomousCommand2 = new AutoFireDisk();
	m_pAutonomousCommand3 = new AutoFireDiskDrive();
	m_pAutonomousCommand4 = new AutonomousCommand4();
	m_pAutonomousCommand5 = new AutonomousCommand5();
	m_pAutonomousCommand6 = new AutonomousCommand6();
	m_pAutonomousCommand7 = new AutonomousCommand7();
	m_pAutonomousCommand8 = new AutonomousCommand8();
	m_pAutonomousCommand9 = new AutonomousCommand9();
	m_pAuto1 = new Auto1();

	// debug code to display a SUBSYSTEM ... on the very Smartdashboard

	// not currently working corectly
	
	//SmartDashboard::PutData(m_pSubSysLED1);
	//SmartDashboard::PutData(m_pSubSysServo);

	// debug ...
	
	m_pLiveWnd = LiveWindow::GetInstance();

	printf("Leaving RobotInit\n");
  }
	
void Robot::AutonomousInit() {
	printf("Init Atonomus Mode %f\n", RobotMap::Auto_Switch->GetVoltage());
	printf("Accelerometer Value: %4.2f", RobotMap::m_pAccelerometerElPos->GetVoltage());

	if (m_pAutonomousCommand != NULL)
	{
		m_pAutonomousCommand->Cancel();
	}
	
	if (RobotMap::Auto_Switch->GetVoltage() < 0.4) {
		printf("running 1\n");
		m_pAuto1->Start();
		m_pAutonomousCommand = m_pAuto1;
	}
	else if (RobotMap::Auto_Switch->GetVoltage() < 0.8) {
		printf("running 2\n");
		m_pAutonomousCommand2->Start();
		m_pAutonomousCommand = m_pAutonomousCommand2;
	}
	else if (RobotMap::Auto_Switch->GetVoltage() < 1.2) {
		printf("running 3\n");
		m_pAutonomousCommand3->Start();
		m_pAutonomousCommand = m_pAutonomousCommand3;
	}
	else if (RobotMap::Auto_Switch->GetVoltage() < 1.6) {
		printf("running 4\n");
		m_pAutonomousCommand4->Start();
		m_pAutonomousCommand = m_pAutonomousCommand4;
	}	
	else if (RobotMap::Auto_Switch->GetVoltage() < 2.0) {
		printf("running 5\n");
		m_pAutonomousCommand5->Start();
		m_pAutonomousCommand = m_pAutonomousCommand5;
	}
	else if (RobotMap::Auto_Switch->GetVoltage() < 2.4) {
		printf("running 6\n");
		m_pAutonomousCommand6->Start();
		m_pAutonomousCommand = m_pAutonomousCommand6;
	}
	
	else if (RobotMap::Auto_Switch->GetVoltage() < 2.8) {
		printf("running 7\n");
		m_pAutonomousCommand7->Start();
		m_pAutonomousCommand = m_pAutonomousCommand7;
	}
	
	else /*if (RobotMap::Auto_Switch->GetVoltage() > 2.873)*/ {
		printf("running 8\n");
		m_pAutonomousCommand8->Start();
		m_pAutonomousCommand = m_pAutonomousCommand8;
	}

}
	
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	
	if (m_pAutonomousCommand != NULL)
	{
		m_pAutonomousCommand->Cancel();
	}
}
	
void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	m_pOperatorInterface->ProcessGamePadInput();
}

// TestInit,  called once ... testinit noop (NO OPeration) at this point

// Users should override this method (TestInit) for initialization code which will be called each time the robot enters test mode.

// The "virtual void TestInit();" method can be overridden for your coding pleasure ...

// called repeatedly ... during Test Mode - Live Window mode

void Robot::TestPeriodic() {
	// very important - as above - must "run" to ensure test loop runs ad infinitum	
	
	m_pLiveWnd->Run();
}

void Robot::ConstructAzimuthPID() {
	
	wpi_assert(m_pAzimuthPIDcontroller == NULL);
	
	m_pAzimuthPIDcontroller = new PIDController( 1, 0.0, 0.0, RobotMap::m_pAzimuthPosition, RobotMap::Az_Jaguar);

	// tolerance is only used by OnTarget method
	
	m_pAzimuthPIDcontroller->SetAbsoluteTolerance(AZPIDTOLERANCE);
	
	// set to false unless your input sensor is like a compass where it goes from 359,360,0,1,...
	
	m_pAzimuthPIDcontroller->SetContinuous(false);
	
	// The setpoint will be clamped to these max, min
	
	m_pAzimuthPIDcontroller->SetInputRange(AZIMUTHMINVALUE, AZIMUTHMAXVALUE);
	
	// The min,max speed of the motor will be ...
	
	m_pAzimuthPIDcontroller->SetOutputRange(-(AZSPEEDPID), AZSPEEDPID);
	
	// The contoller starts off in disabled state
}


void Robot::ConstructElevatorPID() {
	
	wpi_assert(m_pElevationPIDcontroller == NULL);
	
	m_pElevationPIDcontroller = new PIDController( 1, 0.0, 0.0, RobotMap::m_pAccelerometerElPos, RobotMap::El_Jaguar);

	// tolerance is only used by OnTarget method
	
	m_pElevationPIDcontroller->SetAbsoluteTolerance(ELPIDTOLERANCE);
	
	// set to false unless your input sensor is like a compass where it goes from 359,360,0,1,...
	
	m_pElevationPIDcontroller->SetContinuous(false);
	
	// The setpoint will be clamped to these max, min
	
	m_pElevationPIDcontroller->SetInputRange(ELAVMINVALUE, ELAVMAXVALUE);
	
	// The min,max speed of the motor will be ...
	
	m_pElevationPIDcontroller->SetOutputRange(-(ELSPEEDPID), ELSPEEDPID);
	
	// The contoller starts off in disabled state
}

// the magic starts here with this macro, but our code really starts at the RobotInit call

// int main (int argc, char ** argv)


START_ROBOT_CLASS(Robot);
