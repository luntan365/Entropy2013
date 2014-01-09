#ifndef MOVE_ROBOT_BACKWARDS_H
#define MOVE_ROBOT_BACKWARDS_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class MoveRobotBackwards: public Command {
public:
	MoveRobotBackwards();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
