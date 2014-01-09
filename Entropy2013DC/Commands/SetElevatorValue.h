#ifndef SETELEVATORVALUE_H
#define SETELEVATORVALUE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class SetElevatorValue: public Command {
public:
	SetElevatorValue();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

