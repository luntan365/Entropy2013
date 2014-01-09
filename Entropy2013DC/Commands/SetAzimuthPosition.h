#ifndef SETAZIMUTHPOSITION_H
#define SETAZIMUTHPOSITION_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class SetAzimuthPosition: public Command {
	
private:
	// debug  - remove before event
	
	bool m_bWhichPosition;
	float m_fSetPoint;

public:
	SetAzimuthPosition();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
