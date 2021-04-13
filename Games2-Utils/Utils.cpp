// Needed for static library functionality
#include "pch.h"
#include "framework.h"

#include "Utils.h"

namespace Game2DUtils {
	std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec) {
		std::cout << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
		return consoleOut;
	}
}