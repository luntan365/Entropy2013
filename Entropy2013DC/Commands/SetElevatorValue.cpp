#include "SetElevatorValue.h"
#include "../Subsystems/ElControl.h"

SetElevatorValue::SetElevatorValue() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	wpi_assert(Robot::elcontrol != NULL);
	Requires(Robot::elcontrol);
}

// Called just before this Command runs the first time
void SetElevatorValue::Initialize() {
	Robot::elcontrol->MoveUp();
}

// Called repeatedly when this Command is scheduled to run
void SetElevatorValue::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SetElevatorValue::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void SetElevatorValue::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetElevatorValue::Interrupted() {
	End();
}
