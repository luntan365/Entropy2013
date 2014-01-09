#ifndef ELEVATEDOWN_H
#define ELEVATEDOWN_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class ElevateDown: public Command {
public:
	ElevateDown();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

