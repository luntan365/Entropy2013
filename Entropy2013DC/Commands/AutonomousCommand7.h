
#ifndef AUTONOMOUS_COMMAND7_H
#define AUTONOMOUS_COMMAND7_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousCommand7: public Command {
public:
	AutonomousCommand7();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
