#ifndef StartShooter_H
#define StartShooter_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class StartShooter: public Command {
public:
	StartShooter();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

