#include "pch.h"
#include "..\include\Sprite.h"
#include "stb_image.h"

namespace Hunter {
	Sprite::Sprite(const std::string& spriteFile)
	{
		if (!Load(spriteFile)) 
			HLOG("ERROR LOADING SPRITE FILE " + spriteFile)
	}
	bool Sprite::Load(const std::string& spriteFile)
	{
		//make sure we have 4 channels regardless (so that non-transparent images can also load)
		mImage = stbi_load(spriteFile.c_str(), &mWidth, &mHeight, &mNumChannels, 4);

		if (mImage)
			return true;
		else
			return false;
	}
	int Sprite::GetWidth() const
	{
		return mWidth;
	}
	int Sprite::GetHeight() const
	{
		return mHeight;
	}
	const unsigned char* Sprite::GetImagePtr() const
	{
		return mImage;
	}
	Sprite::~Sprite()
	{
		stbi_image_free(mImage);
	}
}