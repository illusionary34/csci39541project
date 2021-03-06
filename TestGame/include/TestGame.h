#pragma once

#include "Hunter.h"
#include "Unit.h"
#include <deque>

class TestGame : public Hunter::HunterApp {

public:
	TestGame();

	virtual void onUpdate() override;

	virtual void onKeyPressed(Hunter::KeyPressedEvent& event) override;
	virtual void onKeyReleased(Hunter::KeyReleasedEvent& event) override;

private:
	Unit mSpaceship;
	std::deque<Unit> boxes;

	Hunter::Sprite gameOverSprite;
	Hunter::Sprite background;

	enum class Action {
		LeftMove,
		RightMove,
		Standing
	} playerAction;

	bool isGameOver;

	long long ticks;
};