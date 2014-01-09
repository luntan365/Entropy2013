#ifndef Shooter_H
#define Shooter_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


class Shooter: public Subsystem {
private:

public:
	Shooter();
	void InitDefaultCommand();
	
	/**
	 * sets the speed for the shooter
	 * @param speed	the speed of the motor
	 * @param device which device you wish to change the speed for. 
	 *        device = 0 sets both wheel speeds
	 *        device = 1 sets the first wheel speed
	 *        device = 2 sets the second wheel speed
	 */
	void Shoot(float speed, int device = 0 );
	void Stop();
	void Start();
};

#endif
