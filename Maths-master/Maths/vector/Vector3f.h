#pragma once

#include <math.h>
#include <iostream>

#define power(X) X * X

class Vector3f {
private:
	float m_x, m_y, m_z;
public:
	Vector3f();
	Vector3f(const float x, const float y, const float z);

	void set(const float& x, const float& y, const float& z);
	void add(const float& x, const float& y, const float& z);
	void sub(const float& x, const float& y, const float& z);
	void set(const Vector3f& vec);
	Vector3f* add(const Vector3f& vec);
	void sub(const Vector3f& vec);

	float length() const;
	Vector3f cross(const Vector3f& vec) const;

	float getX() const;
	float getY() const;
	float getZ() const;

	void setX(const float& x);
	void setY(const float& y);
	void setZ(const float& z);

	float dot_product(const Vector3f& v) const;

	Vector3f mul(const Vector3f& v, Vector3f& result) const;
	void mul(const Vector3f& v);
	void mul(const float& v);
	Vector3f mul(const float& v, Vector3f& result) const;

	Vector3f* divide(const float& scalar);
	Vector3f* normalize();

	void print();
};


