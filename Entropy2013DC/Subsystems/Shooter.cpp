#include "Shooter.h"
#include "../Robotmap.h"
#include <math.h>

Shooter::Shooter() : Subsystem("Shooter") {
	
}
    
void Shooter::InitDefaultCommand() {

}

void Shooter::Shoot( float speed, int motor )
{
	//
	// Bound between -1 .. 1
	//
	if ( speed > 1 ) { speed = 1; }
	if ( speed < -1 ) { speed = -1; } 
	
	if ( motor == 0 )
	{
		RobotMap::Shooter_Motor1->Set(-speed);
		RobotMap::Shooter_Motor2->Set(speed);
	}
	else if ( motor == 1 )
	{
		RobotMap::Shooter_Motor1->Set( -speed );
	}
	else if ( motor == 2 )
	{
		RobotMap::Shooter_Motor2->Set( speed );		
	}
}

void Shooter::Stop() {
// mq - why not set(0)?
	RobotMap::Shooter_Motor1->SetRaw(0);
	RobotMap::Shooter_Motor2->SetRaw(0);
}

void Shooter::Start() {
	RobotMap::Shooter_Motor1->Set(-0.90);
	RobotMap::Shooter_Motor2->Set(0.85);
}


