#ifndef STOPAZIMUTH_H
#define STOPAZIMUTH_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class StopAzimuth: public Command {
public:
	StopAzimuth();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif



