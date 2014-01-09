
#ifndef AUTONOMOUS_COMMAND3_H
#define AUTONOMOUS_COMMAND3_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousCommand3: public Command {
public:
	AutonomousCommand3();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
