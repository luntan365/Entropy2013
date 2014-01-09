#ifndef CAMERATILT_H
#define CAMERATILT_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class CameraTilt: public Subsystem {
private:

public:
	CameraTilt();
	void InitDefaultCommand();
	void TiltItUp();
	void TiltItDown();
};

#endif
