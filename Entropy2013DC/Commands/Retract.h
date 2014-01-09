#ifndef Retract_H
#define Retract_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class Retract: public Command {
public:
	Retract();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
};

#endif

