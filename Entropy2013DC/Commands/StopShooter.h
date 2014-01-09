#ifndef StopShooter_H
#define StopShooter_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class StopShooter: public Command {
public:
	StopShooter();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif

