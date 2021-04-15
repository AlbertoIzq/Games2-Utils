#pragma once

// Needed for static library functionality
#include "pch.h"
#include "framework.h"

#include "Vec2D.h"

namespace Game2DUtils
{
	bool isEqual(float x, float y);
	bool isGreaterThanOrEqual(float x, float y);
	bool isLessThanOrEqual(float x, float y);
}