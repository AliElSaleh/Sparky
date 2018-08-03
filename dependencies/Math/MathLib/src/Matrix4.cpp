#include "Matrix4.h"
#include <math.h>

Matrix4::Matrix4() : m0(1), m1(0), m2(0), m3(0), 
					 m4(0), m5(1), m6(0), m7(0), 
					 m8(0), m9(0), m10(1), m11(0),
					 m12(0), m13(0), m14(0), m15(1)
{
}

Matrix4::Matrix4(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15) : m0(m0), m1(m1), m2(m2), m3(m3), m4(m4), m5(m5), m6(m6), m7(m7), m8(m8), m9(m9), m10(m10), m11(m11), m12(m12), m13(m13), m14(m14), m15(m15)
{

}

Matrix4 Matrix4::MakeIdentity()
{
	return Matrix4();
}

Matrix4 Matrix4::MakeTranslation(float x, float y, float z)
{
	return Matrix4
	(
		1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1
	);
}

Matrix4 Matrix4::MakeScale(float sx, float sy, float sz)
{
	return Matrix4
	(
		sx, 0, 0, 0, 
		0, sy, 0, 0, 
		0, 0, sz, 0, 
		0, 0, 0, 1
	);
}

Matrix4 Matrix4::MakeRotationX(double radians)
{
	float s = sinf(radians);
	float c = cosf(radians);

	return Matrix4
	(
		1, 0, 0,  0,
		0, c, -s, 0,
		0, s, c,  0,
		0, 0, 0,  1
	);
}

Matrix4 Matrix4::MakeRotationY(double radians)
{
	float s = sinf(radians);
	float c = cosf(radians);

	return Matrix4
	(
		c,  0, s, 0,
		0,  1, 0, 0,
		-s, 0, c, 0,
		0,  0, 0, 1
	);
}

Matrix4 Matrix4::MakeRotationZ(double radians)
{
	float s = sinf(radians);
	float c = cosf(radians);

	return Matrix4
	(
		c,-s, 0, 0,
		s, c, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
}

Matrix4 Matrix4::MakeRotation()
{
	return Matrix4();
}

Matrix4 Matrix4::LookAt(Vector3 eye, Vector3 target, Vector3 up)
{
	// The look-at vector
	Vector3 zAxis = Vector3::Normalise(target - eye);

	// The right vector
	Vector3 xAxis = Vector3::Normalise(Vector3::Cross(up, zAxis));

	// The up vector
	Vector3 yAxis = Vector3::Cross(zAxis, xAxis);

	// Create a 4x4 orientation matrix from the right, up and at vectors
	Matrix4 orientation =
	{
		xAxis.x, yAxis.x, zAxis.z, 0,
		xAxis.y, yAxis.y, zAxis.y, 0,
		xAxis.z, yAxis.z, zAxis.z, 0,
			0,		0,		0,	   1
	};

	// Create a 4x4 translation matrix by negating the eye position
	Matrix4 translation =
	{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		-eye.x, -eye.y, -eye.z, 1
	};

	return (translation * orientation);
}

Matrix4 Matrix4::Perspective(float fovY, float aspect, float zNear, float zFar)
{
	Matrix4 matrix;
	matrix[0] = 2 * fovY / (aspect);
	matrix[5] = 2 * fovY / (aspect);
	matrix[8] = -(zNear) / (aspect);
	matrix[9] = -(zNear) / (aspect);
	matrix[10] = (zNear) / (aspect);
	matrix[11] = 1;
	matrix[14] = -(2 * zFar) / (aspect);
	matrix[15] = 0;
	return matrix;
}

Matrix4 Matrix4::operator * (const Matrix4 &rhs) const
{
	return Matrix4
	(
		(m0 * rhs.m0)  + (m1 * rhs.m4) + (m2 * rhs.m8)  + (m3 * rhs.m12),    // r1 . c1
		(m0 * rhs.m1)  + (m1 * rhs.m5) + (m2 * rhs.m9)  + (m3 * rhs.m13),    // r1 . c2
		(m0 * rhs.m2)  + (m1 * rhs.m6) + (m2 * rhs.m10) + (m3 * rhs.m14),    // r1 . c3
		(m0 * rhs.m3)  + (m1 * rhs.m7) + (m2 * rhs.m11) + (m3 * rhs.m15),    // r1 . c4
		(m4 * rhs.m0)  + (m5 * rhs.m4) + (m6 * rhs.m8)  + (m7 * rhs.m12),    // r2 . c1
		(m4 * rhs.m1)  + (m5 * rhs.m5) + (m6 * rhs.m9)  + (m7 * rhs.m13),    // r2 . c2
		(m4 * rhs.m2)  + (m5 * rhs.m6) + (m6 * rhs.m10) + (m7 * rhs.m14),    // r2 . c3 
		(m4 * rhs.m3)  + (m5 * rhs.m7) + (m6 * rhs.m11) + (m7 * rhs.m15),    // r2 . c4 
		(m8 * rhs.m0)  + (m9 * rhs.m4) + (m10 * rhs.m8)  + (m11 * rhs.m12),  // r3 . c1
		(m8 * rhs.m1)  + (m9 * rhs.m5) + (m10 * rhs.m9)  + (m11 * rhs.m13),  // r3 . c2 
		(m8 * rhs.m2)  + (m9 * rhs.m6) + (m10 * rhs.m10) + (m11 * rhs.m14),  // r3 . c3 
		(m8 * rhs.m3)  + (m9 * rhs.m7) + (m10 * rhs.m11) + (m11 * rhs.m15),  // r3 . c4
		(m12 * rhs.m0) + (m13 * rhs.m4) + (m14 * rhs.m8)  + (m15 * rhs.m12), // r4 . c2
		(m12 * rhs.m1) + (m13 * rhs.m5) + (m14 * rhs.m9)  + (m15 * rhs.m13), // r4 . c3
		(m12 * rhs.m2) + (m13 * rhs.m6) + (m14 * rhs.m10) + (m15 * rhs.m14), // r4 . c4
		(m12 * rhs.m3) + (m13 * rhs.m7) + (m14 * rhs.m11) + (m15 * rhs.m15)  // r4 . c4
	);
}

Vector4 operator*(const Matrix4 & lhs, const Vector4 & rhs)
{
	Vector4 vector;
	vector.x = lhs.m0 * rhs.x + lhs.m1 * rhs.y + lhs.m2 * rhs.z + lhs.m3 * rhs.w;
	vector.y = lhs.m4 * rhs.x + lhs.m5 * rhs.y + lhs.m6 * rhs.z + lhs.m7 * rhs.w;
	vector.z = lhs.m8 * rhs.x + lhs.m9 * rhs.y + lhs.m10 * rhs.z + lhs.m11 * rhs.w;
	vector.w = lhs.m12 * rhs.x + lhs.m13 * rhs.y + lhs.m14 * rhs.z + lhs.m15 * rhs.w;

	return Vector4(vector.x, vector.y, vector.z, vector.w);
}

Matrix4 &Matrix4::operator *= (const Matrix4 &rhs)
{
	*this = *this * rhs;
	return *this;
}

bool Matrix4::operator==(const Matrix4 & rhs) const
{
	return
		m0 == rhs.m0 && m1 == rhs.m1 && m2 == rhs.m2 && m3 == rhs.m3 &&
		m4 == rhs.m4 && m5 == rhs.m5 && m6 == rhs.m6 && m7 == rhs.m7 &&
		m8 == rhs.m8 && m9 == rhs.m9 && m10 == rhs.m10 && m11 == rhs.m11 &&
		m12 == rhs.m12 && m13 == rhs.m13 && m14 == rhs.m14 && m15 == rhs.m15;
}

float & Matrix4::operator[](const int & index)
{
	return (&m0)[index];
}

const float & Matrix4::operator[](const int & index) const
{
	return (&m0)[index];
}
