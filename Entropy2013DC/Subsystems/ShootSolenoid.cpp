#include "ShootSolenoid.h"
#include "../Robotmap.h"

#define AZSPEED .2f

ShootSolenoid::ShootSolenoid() : Subsystem("ShootSolenoid") {
	
}
    
void ShootSolenoid::InitDefaultCommand() {

}

void ShootSolenoid::PushDisk() {
	RobotMap::Shooter_Solenoid->Set(1);
}

void ShootSolenoid::Retract() {
	RobotMap::Shooter_Solenoid->Set(0);
}


