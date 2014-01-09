#include "LoadDisk.h"
#include "../Subsystems/ShootSolenoid.h"

LoadDisk::LoadDisk() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	wpi_assert(Robot::shootsolenoid != NULL);
	Requires(Robot::shootsolenoid);
	
	m_button = 0;
	
	SetTimeout(double (.45f));
}

LoadDisk::LoadDisk(JoystickButton *button) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	wpi_assert(Robot::shootsolenoid != NULL);
	Requires(Robot::shootsolenoid);
	
	m_button = button;
	
	SetTimeout(double (.8f));
}

// Called just before this Command runs the first time
void LoadDisk::Initialize() {
	
	// Turn solenoid on then wait a second
	
	printf("LoadDisk::Initialize\n");
	if(m_button != 0 && m_button->Get())
	{
		Robot::shootsolenoid->PushDisk();
	}
	else if (m_button == 0)
	{
		Robot::shootsolenoid->PushDisk();
	}
}

// Called repeatedly when this Command is scheduled to run
void LoadDisk::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool LoadDisk::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void LoadDisk::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoadDisk::Interrupted() {
	
	printf("LoadDisk::Interrupted - Timer failed!!!\n");

	End();
}
