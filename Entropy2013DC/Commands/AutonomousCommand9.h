
#ifndef AUTONOMOUS_COMMAND9_H
#define AUTONOMOUS_COMMAND9_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousCommand9: public Command {
public:
	AutonomousCommand9();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
