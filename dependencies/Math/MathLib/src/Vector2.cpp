#include "Vector2.h"
#include <math.h>

Vector2::Vector2() : x(0), y(0)
{

}

Vector2::Vector2(float x, float y) : x(x), y(y)
{
	
}

Vector2 Vector2::operator + (const Vector2 & rhs) const
{
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator+(const float & rhs) const
{
	return Vector2(x + rhs, y + rhs);
}

Vector2 &Vector2::operator += (const Vector2 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2 &Vector2::operator += (const float &rhs)
{
	x += rhs;
	y += rhs;
	return *this;
}

Vector2 Vector2::operator-(const Vector2 & rhs) const
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 &Vector2::operator-=(const Vector2 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Vector2 Vector2::operator*(const Vector2 &rhs) const
{
	return Vector2(x * rhs.x, y * rhs.y);
}

Vector2 Vector2::operator*(const float & rhs) const
{
	return Vector2(x * rhs, y * rhs);
}

std::ostream & operator<<(std::ostream &stream, const Vector2 vector)
{
	std::cout << "Vector2: (" << vector.x << ", " << vector.y << ")";
	return stream;
}

Vector2 operator*(const float lhs, const Vector2 & rhs)
{
	return Vector2(lhs * rhs.x, lhs * rhs.y);
}

Vector2 &Vector2::operator*=(const Vector2 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}

Vector2 Vector2::operator / (const Vector2 & rhs) const
{
	return Vector2(x / rhs.x, y / rhs.y);
}

Vector2 &Vector2::operator/=(const Vector2 & rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	return *this;
}

bool Vector2::operator==(const Vector2 & rhs) const
{
	return x == rhs.x ? true : false, y == rhs.y ? true : false;
}

bool Vector2::operator!=(const Vector2 & rhs) const
{
	if (x != rhs.x && y != rhs.y)
	{
		return true;
	}
}

float & Vector2::operator[](const int & index)
{
	return (&x)[index];
}

const float & Vector2::operator[](const int & index) const
{
	return (&x)[index];
}

Vector2 &Vector2::Normalise()
{
	float len = GetLengthed();

	if (len != 0)
	{
		x /= len;
		y /= len;
	}

	return *this;
}

Vector2 Vector2::GetNormalised() const
{
	Vector2 vec = *this;
	vec.Normalise();
	return vec;

}

float Vector2::Dot(const Vector2 &rhs) const
{
	return x * rhs.x + y * rhs.y;
}

float Vector2::GetLengthed() const
{
	return sqrt(x * x + y * y);
}

float Vector2::Rotation() const
{
	return atan2(y, x);
}

Vector2 Vector2::PerpendicularLeft() const
{
	return Vector2();
}

Vector2 Vector2::PerpendicularRight() const
{
	return Vector2();
}

Vector2 Vector2::Lerp(float t, Vector2 a, Vector2 b)
{
	return (1-t)*a + t*b;
}

float Vector2::AngleBetween(const Vector2 & other) const
{
	return 0.0f;
}
