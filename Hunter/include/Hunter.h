#pragma once
#include "HunterApp.h"
#include "HunterCentral.h"

#define START_GAME(classname)\
	int main() {\
		classname::init();\
		Hunter::HunterApp * gameptr = classname::getInstance();\
		gameptr->run();\
	}