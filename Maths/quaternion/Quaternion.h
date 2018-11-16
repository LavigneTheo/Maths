#pragma once
#include "../vector/Vector3f.h"
#include "../matrix/Matrix4x4.h"
#include "../Utils.h"

class Quaternion {
private:
	float m_w;
	Vector3f m_v;
public:
	Quaternion();
	Quaternion(const float& w, const float& x, const float& y, const float& z);
	Quaternion(const float& w, const Vector3f& v);

	Vector3f getV() const;
	float getW() const;

	void setV(const Vector3f& v);
	void setV(const float& x, const float& y, const float& z);
	void setW(const float& w);

	void add(const Quaternion& q);
	void sub(const Quaternion& q);

	Quaternion* mul(const Quaternion& q);
	Quaternion mul(Quaternion& q1, const Quaternion& q2);

	float norm() const;

	Quaternion* normalize();
	Quaternion conjugate(Quaternion& result) const;
	Quaternion inverse() const;

	Quaternion* rotate(const Vector3f& axis, float theta);
	void rotation_quaternion_to_matrix(Matrix4x4& mat) const;

	static Quaternion get_rotation_quaternion(Vector3f& axis, float theta);
	static Quaternion get_rotation_quaternion(const float& x_axis, const float& y_axis, const float& z_axis, float theta);
};


