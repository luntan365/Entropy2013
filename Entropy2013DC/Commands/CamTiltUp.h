#ifndef CAMTILTUP_H
#define CAMTILTUP_H

#include "Commands/Subsystem.h"
#include "../Robot.h"


class CamTiltUp: public Command {
public:
	CamTiltUp();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
