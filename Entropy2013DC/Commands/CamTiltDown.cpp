#include "CamTiltDown.h"
#include "../Subsystems/CameraTilt.h"


CamTiltDown::CamTiltDown() {
	wpi_assert(Robot::m_pCamTiltSys != NULL);
	Requires(Robot::m_pCamTiltSys);
}

// Called just before this Command runs the first time
void CamTiltDown::Initialize() {
	Robot::m_pCamTiltSys->TiltItDown();
	
}

// Called repeatedly when this Command is scheduled to run
void CamTiltDown::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool CamTiltDown::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void CamTiltDown::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CamTiltDown::Interrupted() {
	
	printf("Command Interupted !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	End();
}
