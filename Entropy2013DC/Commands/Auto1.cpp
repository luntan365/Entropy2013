#include "Auto1.h"
#include "TurnLeft.h"
#include "TurnRight.h"

Auto1::Auto1() {
	AddSequential(new TurnLeft());
	AddSequential(new TurnRight());
}
