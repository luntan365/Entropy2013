#ifndef TIMEDELEVATIONDOWN_H
#define TIMEDELEVATIONDOWN_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class TimedElevationDown: public Command {
public:
	TimedElevationDown();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

