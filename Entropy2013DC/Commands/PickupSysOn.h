#ifndef PICKUPSYSON_H
#define PICKUPSYSON_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class PickupSysOn: public Command {
public:
	PickupSysOn();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
