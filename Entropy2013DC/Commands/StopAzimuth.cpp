#include "StopAzimuth.h"
#include "../Subsystems/AzControl.h"

StopAzimuth::StopAzimuth() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	wpi_assert(Robot::azcontrol != NULL);
	Requires(Robot::azcontrol);
}

// Called just before this Command runs the first time
void StopAzimuth::Initialize() {
	Robot::azcontrol->StopAz();
}

// Called repeatedly when this Command is scheduled to run
void StopAzimuth::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool StopAzimuth::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void StopAzimuth::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopAzimuth::Interrupted() {
	End();
}
