#include "StopElevate.h"
#include "../Subsystems/ElControl.h"

StopElevate::StopElevate() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	wpi_assert(Robot::elcontrol != NULL);
	Requires(Robot::elcontrol);
}

// Called just before this Command runs the first time
void StopElevate::Initialize() {
	Robot::elcontrol->StopEl();
	
}

// Called repeatedly when this Command is scheduled to run
void StopElevate::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool StopElevate::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void StopElevate::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopElevate::Interrupted() {
	End();
}
