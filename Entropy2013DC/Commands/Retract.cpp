#include "Retract.h"
#include "../Subsystems/ShootSolenoid.h"

Retract::Retract() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	wpi_assert(Robot::shootsolenoid != NULL);
	Requires(Robot::shootsolenoid);

	SetTimeout(double (.45f));
}


// Called just before this Command runs the first time
void Retract::Initialize() {
	
	// Turn solenoid off then wait a second

	printf("Retract::Initialize\n");
	Robot::shootsolenoid->Retract();	
}

// Called repeatedly when this Command is scheduled to run
void Retract::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Retract::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Retract::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Retract::Interrupted() {
	
	printf("Retract::Interrupted - Timer failed!!!\n");

	End();
}
