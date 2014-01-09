#ifndef SETELEVATIONPOSITION_H
#define SETELEVATIONPOSITION_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class SetElevationPosition: public Command {
	
public:

	SetElevationPosition();
	SetElevationPosition(float theSetPoint);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	float m_fTheSetPoint;
	
	
};

#endif
