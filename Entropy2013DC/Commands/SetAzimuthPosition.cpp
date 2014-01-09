#include "SetAzimuthPosition.h"
#include "../Subsystems/AzControl.h"
#include <math.h>

SetAzimuthPosition::SetAzimuthPosition() {
	printf("SetAzimuthPosition::start contructor \n");
	wpi_assert(Robot::azcontrol != NULL);
	Requires(Robot::azcontrol);
	m_bWhichPosition = false;
}

// Called just before this Command runs the first time
void SetAzimuthPosition::Initialize() {
	printf("start of SetAzimuthPosition::Initialize\n");
	
	// for testing purposes - fix - setpoints are hardcoded
	
	
	// switch between up and down
	
	if (m_bWhichPosition) {
		m_bWhichPosition = false;
		printf("SetAzimuthPosition::Initialize - setting set point to: %4.2f\n", AZIMUTHMAXVALUE);

		Robot::m_pAzimuthPIDcontroller->SetSetpoint(AZIMUTHMAXVALUE);
	} else {
		m_bWhichPosition = true;
		printf("SetAzimuthPosition::Initialize - setting set point to: %4.2f\n", AZIMUTHMINVALUE);
		Robot::m_pAzimuthPIDcontroller->SetSetpoint(AZIMUTHMINVALUE);
	}
	
	//m_fSetPoint = Robot::m_pAzimuthPIDcontroller->GetSetpoint();
	//printf("SetAzimuthPosition::Initialize - SetPoint: %4.2f \n", m_fSetPoint);
	
	// start controller ...
		
	printf("SetAzimuthPosition::Initialize .. enabling\n");
	Robot::m_pAzimuthPIDcontroller->Enable();
	
	printf("leaving SetAzimuthPosition::Initialize\n");

}

// Called repeatedly when this Command is scheduled to run
void SetAzimuthPosition::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool SetAzimuthPosition::IsFinished() {
	bool tmpbool;

	// print out setpoint only if it has changed
	
	//if (fabs(Robot::m_pAzimuthPIDcontroller->GetSetpoint() - m_fSetPoint) < .01f) {
		//printf("SetAzimuthPosition::IsFinished - SetPoint CHANGED ***************: %4.2f \n", Robot::m_pAzimuthPIDcontroller->GetSetpoint());
	//}

	// current error is ...
	
	printf("SetAzimuthPosition::IsFinished - CurrentError: %4.2f \n", Robot::m_pAzimuthPIDcontroller->GetError());

	// are we done ...

	tmpbool = Robot::m_pAzimuthPIDcontroller->OnTarget();
	if (tmpbool) {
		printf("SetAzimuthPosition::IsFinished - OnTarget returned TRUE - YAHOO!!!!!!!!!!!\n");
	} else {
		printf("SetAzimuthPosition::IsFinished - OnTarget returned FALSE FALSE FALSE\n");

	}
	
	printf("SetAzimuthPosition::IsFinished - Waiting ... returning bool: %d\n", tmpbool);
	Wait(1.5f);
	
	
	return tmpbool;
	
	// when debugged use - return Robot::m_pAzimuthPIDcontroller->OnTarget();
}

// Called once after isFinished returns true
void SetAzimuthPosition::End() {
	
	// stop controller ...
	
	printf("SetAzimuthPosition::End disabling  \n");
	Robot::m_pAzimuthPIDcontroller->Disable();
	Wait(1.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetAzimuthPosition::Interrupted() {
	
	printf("Command Interupted !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	End();
}
