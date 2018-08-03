#include "Vector4.h"
#include <math.h>

Vector4::Vector4() : x(0), y(0), z(0), w(0)
{

}

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{

}

Vector4 Vector4::operator + (const Vector4 & rhs) const
{
	return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

Vector4 &Vector4::operator += (const Vector4 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;
	return *this;
}

Vector4 Vector4::operator-(const Vector4 & rhs) const
{
	return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

Vector4 &Vector4::operator-=(const Vector4 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;
	return *this;
}

Vector4 Vector4::operator*(const float & rhs) const
{
	return Vector4(rhs * x, rhs * y, rhs * z, rhs * w);
}

Vector4 operator*(const float lhs, const Vector4 & rhs)
{
	return Vector4(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
}

Vector4 &Vector4::operator*=(const Vector4 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	w *= rhs.w;
	return *this;
}

Vector4 Vector4::operator / (const Vector4 & rhs) const
{
	return Vector4(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
}

Vector4 &Vector4::operator/=(const Vector4 & rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
	w /= rhs.w;
	return *this;
}

bool Vector4::operator==(const Vector4 & rhs) const
{
	return x == rhs.x ? true : false, y == rhs.y ? true : false, z == rhs.z ? true : false, w == rhs.w ? true : false;
}

bool Vector4::operator!=(const Vector4 & rhs) const
{
	if (x != rhs.x && y != rhs.y && z != rhs.z && w != rhs.w)
	{
		return true;
	}
}

float & Vector4::operator[](const int & index)
{
	return (&x)[index];
}

const float & Vector4::operator[](const int & index) const
{
	return (&x)[index];
}

float Vector4::GetLengthed() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}

Vector4 &Vector4::Normalise()
{
	float len = GetLengthed();

	if (len != 0)
	{
		x /= len;
		y /= len;
		z /= len;
		w /= len;
	}

	return *this;
}

Vector4 Vector4::GetNormalised() const
{
	Vector4 vec = *this;
	vec.Normalise();
	return vec;
}

float Vector4::Rotation() const
{
	return atan2(y, x);
}

float Vector4::Dot(const Vector4 &rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
}

