#ifndef PICKUPSYSTEM_H
#define PICKUPSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class PickupSystem: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	PickupSystem();
	void InitDefaultCommand();
	void Enable();
	void Disable();

};

#endif
