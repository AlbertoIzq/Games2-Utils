#include "pch.h"
#include "framework.h"

#include "Vec2D.h"
#include "Utils.h"
#include <cassert> // Used for assert
#include <cmath> // Used for epsilon value and sqrt

namespace Game2DUtils
{
	const Vec2D Vec2D::Zero;

	// Friend functions
	std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec)
	{
		std::cout << "X: " << vec.mX << ", Y: " << vec.mY << std::endl;
		return consoleOut;
	}

	Vec2D operator*(float scalar, const Vec2D& vec)
	{
		return vec * scalar;
	}

	// Operator overloading
	bool Vec2D::operator==(const Vec2D& vec2) const
	{
		return isEqual(mX, vec2.mX) && isEqual(mY, vec2.mY);
	}
	bool Vec2D::operator!=(const Vec2D& vec2) const
	{
		return !(*this == vec2);
	}

	Vec2D Vec2D::operator-() const
	{
		return Vec2D(-mX, -mY);
	}

	Vec2D Vec2D::operator*(float scale) const
	{
		return Vec2D(scale * mX, scale * mY);
	}

	Vec2D Vec2D::operator/(float scale) const
	{
		assert(fabs(scale) > EPSILON); // Used to make sure that this condition is true. If not, program crashes

		return Vec2D(mX / scale, mY / scale);
	}

	Vec2D& Vec2D::operator*=(float scale)
	{
		*this = *this * scale;
		return *this;
	}

	Vec2D& Vec2D::operator/=(float scale)
	{
		assert(fabs(scale) > EPSILON);
		*this = *this / scale;
		return *this;
	}

	Vec2D Vec2D::operator+(const Vec2D& vec) const
	{
		return Vec2D(mX + vec.mX, mY + vec.mY);
	}

	Vec2D Vec2D::operator-(const Vec2D& vec) const
	{
		return Vec2D(mX - vec.mX, mY - vec.mY);
	}
	Vec2D& Vec2D::operator+=(const Vec2D& vec)
	{
		*this = *this + vec;
		return *this;
	}

	Vec2D& Vec2D::operator-=(const Vec2D& vec)
	{
		*this = *this - vec;
		return *this;
	}

	// Magnitude
	float Vec2D::mag2() const
	{
		return mX * mX + mY * mY;
	}

	float Vec2D::mag() const
	{
		return sqrt(mag2());
	}

	Vec2D Vec2D::getUnitVec() const
	{
		float mag_value = mag();

		if (mag_value > EPSILON)
		{
			return *this / mag_value;
		}

		return Vec2D::Zero;
	}

	Vec2D& Vec2D::normalize()
	{
		float mag_value = mag();

		if (mag_value > EPSILON)
		{
			*this /= mag_value;
		}

		return *this;
	}

	float Vec2D::distance(const Vec2D& vec) const
	{
		return (vec - *this).mag();
	}
}