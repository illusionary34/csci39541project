#include "Unit.h"
#include "Hunter.h"

Unit::Unit(const std::string& spritePath, int newSpeed) :
	mImage(spritePath),
	mSpeed(newSpeed)
{
}

void Unit::setXCoord(int newX)
{
	mXcoord = newX;
}

void Unit::setYCoord(int newY)
{
	mYcoord = newY;
}

int Unit::getXCoord() const
{
	return mXcoord;
}

int Unit::getYCoord() const
{
	return mYcoord;
}

void Unit::updateXCoord(int change)
{
	mXcoord += change;
}

void Unit::updateYCoord(int change)
{
	mYcoord += change;
}

int Unit::getWidth() const
{
	return mImage.GetWidth();
}

int Unit::getHeight() const
{
	return mImage.GetHeight();
}

int Unit::getSpeed() const
{
	return mSpeed;
}

void Unit::draw() const
{
	Hunter::Renderer::draw(mImage, mXcoord, mYcoord, mImage.GetWidth(), mImage.GetHeight());
}

bool Unit::overlapsWith(const Unit& other) const
{
	if ((mXcoord <= other.mXcoord && other.mXcoord <= mXcoord + getWidth()) ||
		(mXcoord <= other.mXcoord + other.getWidth() && other.mXcoord + other.getWidth() <= mXcoord + getWidth())
		) {
		if ((mYcoord <= other.mYcoord && other.mYcoord <= mYcoord + getHeight()) ||
			(mYcoord <= other.mYcoord + other.getHeight() && other.mYcoord + other.getHeight() <= mYcoord + getHeight())
			)
			return true;
	}

	return false;
}
