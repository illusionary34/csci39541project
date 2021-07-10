#pragma once

#include "Hunter.h"

class Unit
{
public:
	Unit(const std::string& spritePath, int newSpeed);
	void setXCoord(int newX);
	void setYCoord(int newY);
	int getXCoord() const;
	int getYCoord() const;
	void updateXCoord(int change);
	void updateYCoord(int change);
	int getWidth() const;
	int getHeight() const;
	int getSpeed() const;

	void draw() const;
	bool overlapsWith(const Unit& other) const;

private:
	Hunter::Sprite mImage;
	int mXcoord;
	int mYcoord;
	int mSpeed;
};