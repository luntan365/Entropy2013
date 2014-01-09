#include "StopShooter.h"
#include "../Subsystems/Shooter.h"

StopShooter::StopShooter() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	wpi_assert(Robot::shooter != NULL);
	Requires(Robot::shooter);
}

// Called just before this Command runs the first time
void StopShooter::Initialize() {
	Robot::shooter->Stop();
}

// Called repeatedly when this Command is scheduled to run
void StopShooter::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool StopShooter::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void StopShooter::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopShooter::Interrupted() {
	End();
}
