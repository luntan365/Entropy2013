#include "AzControl.h"
#include "../Robotmap.h"

#define AZSPEED .2f

AzControl::AzControl() : Subsystem("AzControl") {
	
}
    
void AzControl::InitDefaultCommand() {

}

void AzControl::MoveLeft() {
	RobotMap::Az_Jaguar->Set(AZSPEED);
}

void AzControl::MoveRight() {
	RobotMap::Az_Jaguar->Set(-(AZSPEED));
}

void AzControl::StopAz() {
	RobotMap::Az_Jaguar->Set(0);
}
