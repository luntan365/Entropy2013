#ifndef FIREDISK_H
#define FIREDISK_H

#include "Commands/CommandGroup.h"
#include "Buttons/JoystickButton.h"


class FireDisk: public CommandGroup {
public:	
	FireDisk(JoystickButton *button);
};

#endif
