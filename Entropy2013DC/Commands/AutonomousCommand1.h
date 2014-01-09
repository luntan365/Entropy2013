
#ifndef AUTONOMOUS_COMMAND1_H
#define AUTONOMOUS_COMMAND1_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousCommand1: public Command {
public:
	AutonomousCommand1();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
