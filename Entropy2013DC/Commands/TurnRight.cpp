#include "TurnRight.h"
#include "../Subsystems/AzControl.h"

TurnRight::TurnRight() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	wpi_assert(Robot::azcontrol != NULL);
	Requires(Robot::azcontrol);
}

// Called just before this Command runs the first time
void TurnRight::Initialize() {
	Robot::azcontrol->MoveRight();
}

// Called repeatedly when this Command is scheduled to run
void TurnRight::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool TurnRight::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void TurnRight::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnRight::Interrupted() {
	End();
}
