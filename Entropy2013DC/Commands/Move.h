
#ifndef MOVE_H
#define MOVE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Move: public Command {
public:
	Move();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	Joystick *joystick;
};

#endif
