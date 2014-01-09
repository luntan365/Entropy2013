#include "CamTiltUp.h"
#include "../Subsystems/CameraTilt.h"

CamTiltUp::CamTiltUp() {
	wpi_assert(Robot::m_pCamTiltSys != NULL);
	Requires(Robot::m_pCamTiltSys);
}

// Called just before this Command runs the first time
void CamTiltUp::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void CamTiltUp::Execute() {
	printf("*****TILTING CAMERA UP******");
		Robot::m_pCamTiltSys->TiltItUp();
}

// Make this return true when this Command no longer needs to run execute()
bool CamTiltUp::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void CamTiltUp::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CamTiltUp::Interrupted() {
	printf("Command Interupted !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	End();	
}
