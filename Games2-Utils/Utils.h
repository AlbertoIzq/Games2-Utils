#pragma once

// Needed for static library functionality
#include "pch.h"
#include "framework.h"

#include <iostream>

namespace Game2DUtils {
	class Vec2D	{
		private:
			float mX, mY;

		public:
			Vec2D() : Vec2D(0, 0) {}
			Vec2D(float x, float y) : mX{ x }, mY{ y } {}

			inline void setX(float x) { mX = x; }
			inline void setY(float x) { mX = x; }
			inline float getX() const { return mX; }
			inline float getY() const { return mY; }

			friend std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec);
	};
}