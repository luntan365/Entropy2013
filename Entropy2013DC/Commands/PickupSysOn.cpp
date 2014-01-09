#include "PickupSysOn.h"
#include "../Subsystems/PickupSystem.h"

PickupSysOn::PickupSysOn() {
	wpi_assert(Robot::m_pickupSystem != NULL);
	Requires(Robot::m_pickupSystem);
}

// Called just before this Command runs the first time
void PickupSysOn::Initialize() {
	Robot::m_pickupSystem->Enable();
}

// Called repeatedly when this Command is scheduled to run
void PickupSysOn::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool PickupSysOn::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void PickupSysOn::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PickupSysOn::Interrupted() {
	printf("Command Interupted !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	End();
}
