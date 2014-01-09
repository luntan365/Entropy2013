#ifndef ELCONTROL_H
#define ELCONTROL_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class ElControl: public Subsystem {
private:

public:
	ElControl();
	void InitDefaultCommand();
	void MoveUp();
	void MoveDown();
	void AutoMoveDown();
	void StopEl();
};

#endif
