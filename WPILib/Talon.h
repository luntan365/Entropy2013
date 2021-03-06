/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef Talon_H
#define Talon_H

#include "SafePWM.h"
#include "SpeedController.h"
#include "PIDOutput.h"

/**
 * CTRE Talon Speed Controller
 */
class Talon : public SafePWM, public SpeedController
{
public:
	explicit Talon(UINT32 channel);
	Talon(UINT8 moduleNumber, UINT32 channel);
	virtual ~Talon();
	virtual void Set(float value, UINT8 syncGroup=0);
	virtual float Get();
	virtual void Disable();

	virtual void PIDWrite(float output);

private:
	void InitTalon();
};

#endif

