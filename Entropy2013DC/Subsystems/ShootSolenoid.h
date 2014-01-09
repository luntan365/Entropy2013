#ifndef ShootSolenoid_H
#define ShootSolenoid_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class ShootSolenoid: public Subsystem {
private:

public:
	ShootSolenoid();
	void InitDefaultCommand();
	void PushDisk();
	void Retract();
};

#endif
