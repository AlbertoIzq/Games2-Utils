#include "pch.h"
#include "framework.h"

#include "Vec2D.h"
#include "Utils.h"

namespace Game2DUtils
{
	std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec)
	{
		std::cout << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
		return consoleOut;
	}

	bool Vec2D::operator==(const Vec2D& vec2) const
	{
		return isEqual(mX, vec2.mX) && isEqual(mY, vec2.mY);
	}
	bool Vec2D::operator!=(const Vec2D& vec2) const
	{
		return !(*this == vec2);
	}
}