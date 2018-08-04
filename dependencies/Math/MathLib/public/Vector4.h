#pragma once
#include <iostream>

class Vector4
{
public:
	float x, y, z, w;

public:
	Vector4() = default;
	Vector4(float x, float y, float z, float w);

	Vector4      operator +(const Vector4 & rhs) const;
	Vector4 &    operator +=(const Vector4 &rhs);
	Vector4      operator -(const Vector4 & rhs) const;
	Vector4 &    operator -=(const Vector4 &rhs);
	Vector4      operator *(const float &   rhs) const;
	Vector4 &    operator *=(const Vector4 &rhs);
	Vector4      operator /(const Vector4 & rhs) const;
	Vector4 &    operator /=(const Vector4 &rhs);
	bool         operator ==(const Vector4 &rhs) const;
	bool         operator !=(const Vector4 &rhs) const;
	float &      operator [](const int &    index);
	const float &operator [](const int &    index) const;

	float GetLengthed() const;

	Vector4 &Normalise();
	Vector4  GetNormalised() const;

	float Rotation() const;

	float Dot(const Vector4 &rhs) const;

	friend std::ostream &operator <<(std::ostream &stream, Vector4 vector);
};

Vector4 operator*(float lhs, const Vector4 &rhs);
