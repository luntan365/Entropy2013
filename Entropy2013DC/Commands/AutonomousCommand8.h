
#ifndef AUTONOMOUS_COMMAND8_H
#define AUTONOMOUS_COMMAND8_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousCommand8: public Command {
public:
	AutonomousCommand8();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
