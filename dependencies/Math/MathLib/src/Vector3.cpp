#include "Vector3.h"
#include <math.h>

Vector3::Vector3() : x(0), y(0), z(0)
{
}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{

}

Vector3 Vector3::Right(1, 0, 0);
Vector3 Vector3::Up(0, 1, 0);
Vector3 Vector3::Forward(0, 0, 1);

Vector3 Vector3::operator + (const Vector3 & rhs) const
{
	return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector3 &Vector3::operator += (const Vector3 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

Vector3 &Vector3::operator+=(const float &rhs)
{
	x += rhs;
	y += rhs;
	z += rhs;
	return *this;
}

Vector3 Vector3::operator - (const Vector3 & rhs) const
{
	return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3 Vector3::operator - () const
{
	return Vector3(0 - x, 0 - y, 0 - z);
}

Vector3 &Vector3::operator -= (const Vector3 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

Vector3 Vector3::operator * (const float & rhs) const
{
	return Vector3(rhs * x, rhs * y, rhs * z);
}

std::ostream & operator<<(std::ostream &stream, const Vector3 vector)
{
	stream << "Vector3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	return stream;
}

Vector3 operator*(const float lhs, const Vector3 &rhs)
{
	return Vector3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

Vector3 &Vector3::operator*=(const Vector3 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}

Vector3 Vector3::operator / (const Vector3 & rhs) const
{
	return Vector3(x / rhs.x, y / rhs.y, z / rhs.z);
}

Vector3 &Vector3::operator/=(const Vector3 & rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
	return *this;
}

bool Vector3::operator == (const Vector3 &rhs) const
{
	return x == rhs.x ? true : false, y == rhs.y ? true : false, z == rhs.z ? true : false;
}

bool Vector3::operator != (const Vector3 &rhs) const
{
	if (x != rhs.x && y != rhs.y && z != rhs.z)
	{
		return true;
	}
}

float &Vector3::operator[](const int & index)
{
	return (&x)[index];
}

const float &Vector3::operator[](const int & index) const
{
	return (&x)[index];
}

float Vector3::GetLengthed() const
{
	return sqrt(x * x + y * y + z * z);
}

Vector3 &Vector3::Normalise()
{
	float len = GetLengthed();
	
	if (len != 0)
	{
		x /= len;
		y /= len;
		z /= len;
	}

	return *this;
}

Vector3 &Vector3::Normalise(Vector3 vector)
{
	float len = vector.GetLengthed();

	if (len != 0)
	{
		vector.x /= len;
		vector.y /= len;
		vector.z /= len;
	}

	return vector;
}

Vector3 Vector3::GetNormalised() const
{
	Vector3 vec = *this;
	vec.Normalise();
	return vec;
}

float Vector3::Rotation() const
{
	return atan2(y, x);
}

float Vector3::Dot(const Vector3 &rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

Vector3 Vector3::Cross(const Vector3 &rhs) const
{
	return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - rhs.x * z, x * rhs.y - y * rhs.x);
}

Vector3 Vector3::Cross(const Vector3 & upVector, const Vector3 & zAxis)
{
	return Vector3((upVector * zAxis.z - upVector * zAxis.y).x, (upVector * zAxis.x - zAxis.x * upVector).y, (upVector * zAxis.y - upVector * zAxis.x).z);
}

std::ostream &operator <<(std::ostream stream, const Vector3 vector)
{
	stream << "Vector3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
	return stream;
}