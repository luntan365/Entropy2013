#if 0
#ifndef __AUTONOMOUS__
#define __AUTONOMOUS__
#include "../Subsystems/Drive.h"

void EntropyAutonomousInit(Drive *drive);

void EntropyAutonomousPeriodic();

void EntropyAutonomousContinuous();

bool EntropyAnonymousFinished();
#endif
#endif
