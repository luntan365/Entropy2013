#include "FeederHomePos.h"
#include "SetElevationPosition.h"
#include "SetAzimuthPosition.h"

FeederHomePos::FeederHomePos() {
	
	// these command can be run in parallel
	
	AddParallel(new SetElevationPosition(SETPT_EL_WHEN_FEEDING));
	//AddParallel(new SetAzimuthPosition());

}
