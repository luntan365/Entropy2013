#include "PickupSysOff.h"
#include "../Subsystems/PickupSystem.h"

PickupSysOff::PickupSysOff() {
	wpi_assert(Robot::m_pickupSystem != NULL);
	Requires(Robot::m_pickupSystem);
}

// Called just before this Command runs the first time
void PickupSysOff::Initialize() {
	Robot::m_pickupSystem->Disable();	
}

// Called repeatedly when this Command is scheduled to run
void PickupSysOff::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool PickupSysOff::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void PickupSysOff::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PickupSysOff::Interrupted() {
	printf("Command Interupted !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	End();
}
