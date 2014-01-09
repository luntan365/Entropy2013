#include "SetElevationPosition.h"
#include "../Subsystems/ElControl.h"
#include <math.h>

SetElevationPosition::SetElevationPosition() {
	
	// if you are here there is a problem because there is no such thing as a default set point
	
	// set it to the min value so we don't blow up
	
	SetElevationPosition(float (ELAVMINVALUE));
}

SetElevationPosition::SetElevationPosition(float theSetPoint) {
	wpi_assert(Robot::elcontrol != NULL);
	Requires(Robot::elcontrol);
	
	m_fTheSetPoint = theSetPoint;
}



// Called just before this Command runs the first time
void SetElevationPosition::Initialize() {
	
	// tell PID to go to set point
	
	printf("SetElevationPosition::Initialize SetPoint being set to: %4.2f", m_fTheSetPoint);

	
	Robot::m_pElevationPIDcontroller->SetSetpoint(m_fTheSetPoint);
	
	// start controller ...

	Robot::m_pElevationPIDcontroller->Enable();
}

// Called repeatedly when this Command is scheduled to run
void SetElevationPosition::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool SetElevationPosition::IsFinished() {
	return Robot::m_pElevationPIDcontroller->OnTarget();
}

// Called once after isFinished returns true
void SetElevationPosition::End() {
	
	// stop controller ...
	
	Robot::m_pElevationPIDcontroller->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetElevationPosition::Interrupted() {
	
	printf("Command Interupted !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	End();
}
