#include "TurnLeft.h"
#include "../Subsystems/AzControl.h"

TurnLeft::TurnLeft() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	wpi_assert(Robot::azcontrol != NULL);
	Requires(Robot::azcontrol);
}

// Called just before this Command runs the first time
void TurnLeft::Initialize() {
	Robot::azcontrol->MoveLeft();
}

// Called repeatedly when this Command is scheduled to run
void TurnLeft::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool TurnLeft::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void TurnLeft::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnLeft::Interrupted() {
	End();
}
