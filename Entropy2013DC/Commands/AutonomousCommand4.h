
#ifndef AUTONOMOUS_COMMAND4_H
#define AUTONOMOUS_COMMAND4_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousCommand4: public Command {
public:
	AutonomousCommand4();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
