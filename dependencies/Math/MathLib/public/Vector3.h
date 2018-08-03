#pragma once

#include <iostream>

class Vector3
{
public:
	float x, y, z;

	static Vector3 Right;
	static Vector3 Up;
	static Vector3 Forward;

public:
	Vector3();
	Vector3(float x, float y, float z);

	Vector3 operator + (const Vector3 &rhs) const;
	Vector3 &operator += (const Vector3 &rhs);
	Vector3 &operator += (const float &rhs);
	Vector3 operator - (const Vector3 &rhs) const;
	Vector3 operator - () const;
	Vector3 &operator -= (const Vector3 &rhs);
	Vector3 operator * (const float &rhs) const;
	Vector3 &operator *= (const Vector3 &rhs);
	Vector3 operator / (const Vector3 &rhs) const;
	Vector3 &operator /= (const Vector3 &rhs);
	bool operator == (const Vector3 &rhs) const;
	bool operator != (const Vector3 &rhs) const;
	float &operator [] (const int &index);
	const float &operator [] (const int &index) const;

	float GetLengthed() const;

	Vector3 &Normalise();
	static Vector3 &Normalise(Vector3 vector);
	Vector3 GetNormalised() const;

	float Rotation() const;

	float Dot(const Vector3 &rhs) const;
	Vector3 Cross(const Vector3 &rhs) const;
	static Vector3 Cross(const Vector3 &upVector, const Vector3 &zAxis);

	friend std::ostream &operator <<(std::ostream &stream, const Vector3 vector);
};

Vector3 operator*(const float lhs, const Vector3 &rhs);
