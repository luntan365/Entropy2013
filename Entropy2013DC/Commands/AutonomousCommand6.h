
#ifndef AUTONOMOUS_COMMAND6_H
#define AUTONOMOUS_COMMAND6_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousCommand6: public Command {
public:
	AutonomousCommand6();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
