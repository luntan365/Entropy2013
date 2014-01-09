#include "ElevateDown.h"
#include "../Subsystems/ElControl.h"

ElevateDown::ElevateDown() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	
	wpi_assert(Robot::elcontrol != NULL);
	Requires(Robot::elcontrol);
}

// Called just before this Command runs the first time
void ElevateDown::Initialize() {
	Robot::elcontrol->MoveDown();
}

// Called repeatedly when this Command is scheduled to run
void ElevateDown::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ElevateDown::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ElevateDown::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevateDown::Interrupted() {
	printf("Command Interupted !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	End();
}
