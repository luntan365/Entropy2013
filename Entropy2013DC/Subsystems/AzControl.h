#ifndef AZCONTROL_H
#define AZCONTROL_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class AzControl: public Subsystem {
private:

public:
	AzControl();
	void InitDefaultCommand();
	void MoveLeft();
	void MoveRight();
	void StopAz();
};

#endif
