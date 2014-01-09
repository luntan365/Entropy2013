#include "ElControl.h"
#include "../Robotmap.h"

#define ELSPEED .4f
#define AUTOELSPEED .4f

ElControl::ElControl() : Subsystem("ElControl") {
	
}
    
void ElControl::InitDefaultCommand() {

}

void ElControl::MoveUp() {
	RobotMap::El_Jaguar->Set(ELSPEED);
}

void ElControl::AutoMoveDown() {
	RobotMap::El_Jaguar->Set(-(AUTOELSPEED));
}


void ElControl::MoveDown() {
	RobotMap::El_Jaguar->Set(-(ELSPEED));
}

void ElControl::StopEl() {
    RobotMap::El_Jaguar->Set(0);
}

