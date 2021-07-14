#include "TestGame.h"

TestGame::TestGame() :
	mSpaceship("assets/player.png", 5), playerAction(Action::Standing)
{
	HLOG("RoBoxed INIT")
}

void TestGame::onUpdate()
{
	if (playerAction == Action::LeftMove)
		mSpaceship.updateXCoord(-mSpaceship.getSpeed());
	else if (playerAction == Action::RightMove)
		mSpaceship.updateXCoord(mSpaceship.getSpeed());

	mSpaceship.draw();
}

void TestGame::onKeyPressed(Hunter::KeyPressedEvent& event)
{
	switch (event.GetKeyCode()) {
	case HUNTER_KEY_LEFT:
		playerAction = Action::LeftMove;
		break;
	case HUNTER_KEY_RIGHT:
		playerAction = Action::RightMove;
		break;
	}
}

void TestGame::onKeyReleased(Hunter::KeyReleasedEvent& event)
{
	HLOG("test game's key released handler");
	if (event.GetKeyCode() == HUNTER_KEY_LEFT || event.GetKeyCode() == HUNTER_KEY_RIGHT)
		playerAction = Action::Standing;
}
