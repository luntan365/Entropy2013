#include "ElevateUp.h"
#include "../Subsystems/ElControl.h"

ElevateUp::ElevateUp() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	wpi_assert(Robot::elcontrol != NULL);
	Requires(Robot::elcontrol);
}

// Called just before this Command runs the first time
void ElevateUp::Initialize() {
	Robot::elcontrol->MoveUp();	
}

// Called repeatedly when this Command is scheduled to run
void ElevateUp::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ElevateUp::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ElevateUp::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevateUp::Interrupted() {
	printf("Command Interupted !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	End();
}
