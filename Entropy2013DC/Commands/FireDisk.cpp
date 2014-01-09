#include "FireDisk.h"
#include "LoadDisk.h"
#include "Retract.h"

FireDisk::FireDisk(JoystickButton *button) 
{
	AddSequential(new LoadDisk(button));
	AddSequential(new Retract());
}


