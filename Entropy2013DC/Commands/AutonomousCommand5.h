
#ifndef AUTONOMOUS_COMMAND5_H
#define AUTONOMOUS_COMMAND5_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousCommand5: public Command {
public:
	AutonomousCommand5();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
