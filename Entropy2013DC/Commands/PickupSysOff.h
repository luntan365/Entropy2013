#ifndef PICKUPSYSOFF_H
#define PICKUPSYSOFF_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class PickupSysOff: public Command {
public:
	PickupSysOff();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
