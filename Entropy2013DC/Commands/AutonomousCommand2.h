
#ifndef AUTONOMOUS_COMMAND2_H
#define AUTONOMOUS_COMMAND2_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousCommand2: public Command {
public:
	AutonomousCommand2();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
