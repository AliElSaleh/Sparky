#include "Matrix3.h"
#include <math.h>

Matrix3::Matrix3() : m0(1), m1(0), m2(0), m3(0), m4(1), m5(0), m6(0), m7(0), m8(1)
{

}

Matrix3::Matrix3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8) : m0(m0), m1(m1), m2(m2), m3(m3), m4(m4), m5(m5), m6(m6), m7(m7), m8(m8)
{

}

Matrix3 Matrix3::MakeIdentity()
{
	return Matrix3();
}

Matrix3 Matrix3::MakeTranslation(float x, float y)
{
	return Matrix3
	(
		1, 0, 0, 
		0, 1, 0, 
		x, y, 1
	);
}

Matrix3 Matrix3::MakeScale(float sx, float sy)
{
	return Matrix3
	(
		sx, 0, 0, 
		0, sy, 0, 
		0, 0, 1
	);
}

Matrix3 Matrix3::MakeRotation(float radians)
{
	return Matrix3
	(
		cos(radians), sin(radians), 0, 
		-sin(radians), cos(radians), 0, 
		0, 0, 1
	);
}

Matrix3 Matrix3::operator * (const Matrix3 &rhs) const
{
	return Matrix3
	(
		m0 * rhs.m0 + m1 * rhs.m3 + m2 * rhs.m6, // r1 . c1
		m0 * rhs.m1 + m1 * rhs.m4 + m2 * rhs.m7, // r1 . c2
		m0 * rhs.m2 + m1 * rhs.m5 + m2 * rhs.m8, // r1 . c3
		m3 * rhs.m0 + m4 * rhs.m3 + m5 * rhs.m6, // r2 . c1
		m3 * rhs.m1 + m4 * rhs.m4 + m5 * rhs.m7, // r2 . c2
		m3 * rhs.m2 + m4 * rhs.m5 + m5 * rhs.m8, // r2 . c3
		m6 * rhs.m0 + m7 * rhs.m3 + m8 * rhs.m6, // r3 . c1 
		m6 * rhs.m1 + m7 * rhs.m4 + m8 * rhs.m7, // r3 . c2 
		m6 * rhs.m2 + m7 * rhs.m5 + m8 * rhs.m8  // r3 . c3
	); 
}

Vector3 operator*(const Matrix3 &lhs, const Vector3 &rhs)
{
	Vector3 vector;
	vector.x = lhs.m0 * rhs.x + lhs.m1 * rhs.y + lhs.m2 * rhs.z;
	vector.y = lhs.m3 * rhs.x + lhs.m4 * rhs.y + lhs.m5 * rhs.z;
	vector.z = lhs.m6 * rhs.x + lhs.m7 * rhs.y + lhs.m8 * rhs.z;

	return Vector3(vector.x, vector.y, vector.z);
}

Vector2 Matrix3::GetScale()
{
	Matrix3 matrix;
	return Vector2(matrix.m0, matrix.m4);
}

Matrix3 &Matrix3::operator *= (const Matrix3 &rhs)
{
	*this = *this * rhs;
	return *this;
}

bool Matrix3::operator==(const Matrix3 & rhs) const
{
	return
		m0 == rhs.m0 && m1 == rhs.m1 && m2 == rhs.m2 && 
		m3 == rhs.m3 && m4 == rhs.m4 && m5 == rhs.m5 && 
		m6 == rhs.m6 && m7 == rhs.m7 && m8 == rhs.m8;
}

