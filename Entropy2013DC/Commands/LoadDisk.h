


#include "Commands/Subsystem.h"
#include "../Robot.h"


class LoadDisk: public Command {
public:
	LoadDisk(JoystickButton *button);
	LoadDisk();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	JoystickButton *m_button;
	
};



