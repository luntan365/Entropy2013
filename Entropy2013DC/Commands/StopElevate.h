
#include "Commands/Subsystem.h"
#include "../Robot.h"


class StopElevate: public Command {
public:
	StopElevate();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};



