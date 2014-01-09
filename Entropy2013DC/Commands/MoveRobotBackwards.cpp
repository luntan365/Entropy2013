#include "MoveRobotBackwards.h"
#include "../OI.h"
#include "../WPILib/RobotDrive.h"
#include "../RobotMap.h"
#include "../WPILib/DriverStationLCD.h"

MoveRobotBackwards::MoveRobotBackwards() 
{
	wpi_assert(Robot::drive != NULL);
	Requires(Robot::drive);
}

// Called just before this Command runs the first time
void MoveRobotBackwards::Initialize() {
	Robot::drive->auto_drive_straight(4.0,-0.3);
}

// Called repeatedly when this Command is scheduled to run
void MoveRobotBackwards::Execute()
{ 
}
// Make this return true when this Command no longer needs to run execute()
bool MoveRobotBackwards::IsFinished() {
	return true;
}
// Called once after isFinished returns true
void MoveRobotBackwards::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveRobotBackwards::Interrupted() {
	End();
}
