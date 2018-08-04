#pragma once
#include "MyMath.h"
#include "MyMathsFunc.h"

class Matrix4
{
public:

	union
	{
		struct
		{
			// 4x4 matrix - 16 floats
			float	m0, m1, m2, m3,
					m4, m5, m6, m7,
					m8, m9, m10, m11,
					m12, m13, m14, m15;
		};

		struct
		{
			float elements[4 * 4];
		};

		struct
		{
			Vector4 xAxis;
			Vector4 yAxis;
			Vector4 zAxis;
			Vector4 wAxis;
		};

		struct
		{
			Vector4 columns[4];
		};

		struct
		{
			Vector2 right;		unsigned int : 32;
			Vector2 up;			unsigned int : 32;
			Vector2 position;	unsigned int : 32;
		};

	};

public:
	// Static Factory helper functions
	//==================================================
	// usage: Matrix4::MakeTranslate(10, 10, 10)
	//==================================================
	static Matrix4 MakeIdentity();
	static Matrix4 MakeTranslation(float x, float y, float z);
	static Matrix4 MakeTranslation(const Vector3 &translation);
	static Matrix4 MakeScale(float sx, float sy, float sz);
	static Matrix4 MakeScale(const Vector3 &scale);
	static Matrix4 MakeRotation(float angle, const Vector3 &axis);
	static Matrix4 MakeRotationX(double radians);
	static Matrix4 MakeRotationY(double radians);
	static Matrix4 MakeRotationZ(double radians);
	static Matrix4 MakeRotation();
	static Matrix4 LookAt(Vector3 eye, Vector3 target, Vector3 up);
	static Matrix4 Perspective(float fov, float aspectRatio, float near, float far);
	static Matrix4 Orthographic(float left, float right, float bottom, float top, float near, float far);

public:

	// Default Contructor
	Matrix4();

	// Overloaded Contructor
	Matrix4(float m0, float m1, float m2, float m3,
			float m4, float m5, float m6, float m7,
			float m8, float m9, float m10, float m11,
			float m12, float m13, float m14, float m15);

	Matrix4(float diagonal);

	// Operator overloads
	Matrix4 operator * (const Matrix4 &rhs) const;
	Matrix4 operator * (const Matrix4 &rhs);
	Matrix4 &operator *= (const Matrix4 &rhs);
	bool operator == (const Matrix4 &rhs) const;

	float &operator [] (const int &index);
	const float &operator [] (const int &index) const;

	// Functions
	Matrix4 &Multiply(const Matrix4 &rhs);

private:
	bool arrayUsed = false;
	bool floatUsed = false;
};

Vector4 operator*(const Matrix4 &lhs, const Vector4 &rhs);