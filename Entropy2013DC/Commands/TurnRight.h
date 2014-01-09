#ifndef TURNRIGHT_H
#define TURNRIGHT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class TurnRight: public Command {
public:
	TurnRight();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

