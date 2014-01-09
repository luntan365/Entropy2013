#include "PickupSystem.h"
#include "../Robotmap.h"

#define PICKUPSPEED 205.0f

PickupSystem::PickupSystem() : Subsystem("PickupSystem") {
	
}
    
void PickupSystem::InitDefaultCommand() {

}

void PickupSystem::Enable() {
	RobotMap::m_pDiscFloorVac->Set(PICKUPSPEED);
	RobotMap::m_pDiscElevate->Set(PICKUPSPEED);
	RobotMap::m_pDiscFeed->Set(PICKUPSPEED);
}


void PickupSystem::Disable(){
	RobotMap::m_pDiscFloorVac->Set(0.0f);
	RobotMap::m_pDiscElevate->Set(0.0f);
	RobotMap::m_pDiscFeed->Set(0.0f);
	
}
