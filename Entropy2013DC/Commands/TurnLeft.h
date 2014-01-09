#ifndef TURNLEFT_H
#define TURNLEFT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class TurnLeft: public Command {
public:
	TurnLeft();
	virtual void Initialize(); 
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

