#ifndef CAMTILTDOWN_H
#define CAMTILTDOWN_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


class CamTiltDown: public Command {
public:
	CamTiltDown();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
