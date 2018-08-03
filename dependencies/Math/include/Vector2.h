#pragma once

class Vector2
{
public:
	float x, y;

public:
	Vector2();
	Vector2(float x, float y);
	Vector2(const float &x, const float &y);

	Vector2 operator + (const Vector2 &rhs) const;
	Vector2 operator + (const float &rhs) const;
	Vector2 &operator += (const Vector2 &rhs);
	Vector2 &operator += (const float &rhs);
	Vector2 operator - (const Vector2 &rhs) const;
	Vector2 &operator -= (const Vector2 &rhs);
	Vector2 operator * (const Vector2 &rhs) const;
	Vector2 operator * (const float &rhs) const;
	Vector2 &operator *= (const Vector2 &rhs);
	Vector2 operator / (const Vector2 &rhs) const;
	Vector2 &operator /= (const Vector2 &rhs);
	bool operator == (const Vector2 &rhs) const;
	bool operator != (const Vector2 &rhs) const;
	float &operator [] (const int &index);
	const float &operator [] (const int &index) const;
	
	float GetLengthed() const;

	Vector2 &Normalise();
	Vector2 GetNormalised() const;

	float Rotation() const;

	Vector2 PerpendicularLeft() const;
	Vector2 PerpendicularRight() const;

	static Vector2 Lerp(float t, Vector2 a, Vector2 b);

	float AngleBetween(const Vector2 &other) const;
	
	float Dot(const Vector2 &rhs) const;

};

Vector2 operator*(const float lhs, const Vector2 &rhs);