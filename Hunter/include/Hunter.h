#pragma once
#include "HunterApp.h"
#include "Sprite.h"
#include "Renderer.h"
#include "HunterCentral.h"
#include "HunterKeys.h"
#include "KeyboardEvents.h"

#define START_GAME(classname)\
	int main() {\
		classname * gameptr = new classname;\
		gameptr->getInstance()->run();\
		delete gameptr;\
	}