#include "TestGame.h"

TestGame::TestGame() :
	mSpaceship("assets/player.png", 10),
	gameOverSprite("assets/game_over.png"),
	background("assets/background.png"),
	playerAction(Action::Standing),
	isGameOver(false)
{
	HLOG("RoBoxed INIT");
	mSpaceship.setXCoord(GetWindowWidth() / 2 - mSpaceship.getWidth() / 2);

	srand(time(0));
}

void TestGame::onUpdate()
{
	Hunter::Renderer::draw(background, 0, 0, 800, 600);
	if (isGameOver) {
		Hunter::Renderer::draw(gameOverSprite, 350, 250, 400, 200);
		return;
	}

	ticks++;
	if (ticks % 120 == 0) {
		char numberBuff[4];
		int boxNumber = (rand() % 4) + 1;
		_itoa_s(boxNumber, numberBuff, 10);
		std::string name("assets/box");
		name += numberBuff;
		name += ".png";
		int position = (rand() % 5);
		boxes.emplace_front(name, 5);
		boxes.front().setYCoord(GetWindowHeight());
		boxes.front().setXCoord(160 * position);
	}

	//if the player glitches out of the window put him back
	if (mSpaceship.getXCoord() <= 0)
		mSpaceship.setXCoord(0);
	else if (mSpaceship.getXCoord() + mSpaceship.getWidth() >= GetWindowWidth())
		mSpaceship.setXCoord(GetWindowWidth() - mSpaceship.getWidth());

	if (playerAction == Action::LeftMove && mSpaceship.getXCoord() > 0) {
		mSpaceship.updateXCoord(-mSpaceship.getSpeed());
	}
	else if (playerAction == Action::RightMove && mSpaceship.getXCoord() + mSpaceship.getWidth() < GetWindowWidth()) {
		mSpaceship.updateXCoord(mSpaceship.getSpeed());
	}
	mSpaceship.draw();

	while (!boxes.empty() && boxes.back().getYCoord() + boxes.back().getHeight() < 0)
		boxes.pop_back();

	for (auto& box : boxes)
		box.updateYCoord(-box.getSpeed());

	for (const auto& box : boxes) {
		box.draw();
		if (box.overlapsWith(mSpaceship))
			isGameOver = true;
	}
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
	if (event.GetKeyCode() == HUNTER_KEY_LEFT || event.GetKeyCode() == HUNTER_KEY_RIGHT)
		playerAction = Action::Standing;
}
