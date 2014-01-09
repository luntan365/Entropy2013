#include "AutoFireDisk.h"
#include "LoadDisk.h"
#include "Retract.h"
#include "StartShooter.h"
#include "StopShooter.h"
#include "TimedElevationDown.h"
#include "MoveRobotBackwards.h"

AutoFireDisk::AutoFireDisk() {
	
	// These two can be run in parallel
	
	AddSequential(new TimedElevationDown());
	AddSequential(new StartShooter());
	
	// TODO: now that motor safety is off remove extra startshooters and test
	
	AddSequential(new LoadDisk());
	AddSequential(new Retract());
	//AddSequential(new StartShooter());
	AddSequential(new LoadDisk());
	AddSequential(new Retract());
	//AddSequential(new StartShooter());
	AddSequential(new LoadDisk());
	AddSequential(new Retract());
	AddSequential(new LoadDisk());
	AddSequential(new Retract());
	AddSequential(new StopShooter());
}
