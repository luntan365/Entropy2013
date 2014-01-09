#include "CameraTilt.h"
#include "../Robotmap.h"

CameraTilt::CameraTilt() : Subsystem("CameraTilt") {
	
}
    
void CameraTilt::InitDefaultCommand() {

}

void CameraTilt::TiltItUp() {
	RobotMap::m_pCamTiltControl->Set(1.0f);
}

void CameraTilt::TiltItDown() {
	RobotMap::m_pCamTiltControl->Set(0.375f);
}
