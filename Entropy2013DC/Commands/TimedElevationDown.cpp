#include "TimedElevationDown.h"
#include "../Subsystems/ElControl.h"

TimedElevationDown::TimedElevationDown() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	wpi_assert(Robot::elcontrol != NULL);
	Requires(Robot::elcontrol);

	// start timer

	SetTimeout(double(2.58f));
}

// Called just before this Command runs the first time
void TimedElevationDown::Initialize() {
	Robot::elcontrol->AutoMoveDown();
}

// Called repeatedly when this Command is scheduled to run
void TimedElevationDown::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool TimedElevationDown::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void TimedElevationDown::End() {
	Robot::elcontrol->StopEl();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimedElevationDown::Interrupted() {
	End();
}
