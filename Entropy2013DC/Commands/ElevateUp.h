#ifndef ELEVATEUP_H
#define ELEVATEUP_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class ElevateUp: public Command {
public:
	ElevateUp();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

