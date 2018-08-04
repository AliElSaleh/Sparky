#pragma once
#include "Vector2.h"
#include "Vector3.h"

class Matrix3
{
public:

	union
	{
		struct
		{
			// 3x3 matrix - 9 floats
			float         m0, m1, m2,
			          m3, m4, m5,
			          m6, m7, m8;
		};

		struct
		{
			Vector3 xAxis;
			Vector3 yAxis;
			Vector3 zAxis;
		};

		struct
		{
			struct
			{
				Vector2 right;
				unsigned int : 32;
			};

			struct
			{
				Vector2 up;
				unsigned int : 32;
			};

			struct
			{
				Vector2 position;
				unsigned int : 32;
			};
		};
	};

public:
	// Static Factory helper functions
	//==================================================
	// usage: Matrix3::MakeTranslate(10, 10)
	//==================================================
	static Matrix3 MakeIdentity();
	static Matrix3 MakeTranslation(float x, float  y);
	static Matrix3 MakeScale(float       sx, float sy);
	static Matrix3 MakeRotation(float    radians);
	static Vector2 GetScale();

public:

	// Default Contructor
	Matrix3();

	// Overloaded Contructor
	Matrix3(float m0, float m1, float m2,
	        float m3, float m4, float m5,
	        float m6, float m7, float m8);

	// Operator overloads
	Matrix3  operator*(const Matrix3 &  rhs) const;
	Matrix3 &operator *=(const Matrix3 &rhs);
	bool     operator ==(const Matrix3 &rhs) const;
};

Vector3 operator*(const Matrix3 &lhs, const Vector3 &rhs);
