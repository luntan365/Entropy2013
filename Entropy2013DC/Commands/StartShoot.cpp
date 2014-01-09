#include "StartShooter.h"
#include "../Subsystems/Shooter.h"

StartShooter::StartShooter() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	wpi_assert(Robot::shooter != NULL);
	Requires(Robot::shooter);
}

// Called just before this Command runs the first time
void StartShooter::Initialize() {
	Robot::shooter->Start();
	Wait(2.0);	
}

// Called repeatedly when this Command is scheduled to run
void StartShooter::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool StartShooter::IsFinished() {
	//Robot::m_motors_spinning = false;
	return true;
}

// Called once after isFinished returns true
void StartShooter::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StartShooter::Interrupted() {
	End();
}
