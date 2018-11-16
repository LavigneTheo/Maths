#include "Quaternion.h"


Quaternion::Quaternion() {
	m_w = 0;
	m_v = Vector3f(0, 0, 0);
}
Quaternion::Quaternion(const float& w, const float& x, const float& y, const float& z) :
	m_w(w) {
	m_v = Vector3f(x, y, z);
}
Quaternion::Quaternion(const float& w, const Vector3f& v) : m_w(w), m_v(v) {
}

Vector3f Quaternion::getV() const {
	return m_v;
}
float Quaternion::getW() const {
	return m_w;
}

void Quaternion::setV(const Vector3f& v) {
	m_v.set(v);
}
void Quaternion::setV(const float& x, const float& y, const float& z) {
	m_v.set(Vector3f(x, y, z));
}
void Quaternion::setW(const float& w) {
	m_w = w;
}

void Quaternion::add(const Quaternion& q) {
	m_v.add(q.getV());
	m_w += q.getW();
}
void Quaternion::sub(const Quaternion& q) {
	m_v.sub(q.getV());
	m_w -= q.getW();
}


Quaternion* Quaternion::mul(const Quaternion& q) {
	
	Vector3f w1xv2 = q.getV().mul(m_w, w1xv2);
	Vector3f w2xv1 = m_v.mul(q.getW(), w2xv1);
	Vector3f cross = m_v.cross(q.getV());

	//w = w1*w2 - v1.v2
	m_w = m_w * q.getW() - m_v.dot_product(q.getV());
	//w1*v2 + w2*v1 + v1xv2
	m_v.set(*(w1xv2.add(w2xv1)->add(cross)));
	
	return this;
}

Quaternion Quaternion::mul(Quaternion& q1, const Quaternion& q2) {

	Vector3f w1xv2 = q2.getV().mul(q1.getW(), w1xv2);
	Vector3f w2xv1 = q1.getV().mul(q2.getW(), w2xv1);
	Vector3f cross = q1.getV().cross(q2.getV());

	return Quaternion(
		q1.getW() * q2.getW() - q1.getV().dot_product(q2.getV()), 
		*(w1xv2.add(w2xv1)->add(cross))
	);
}

float Quaternion::norm() const {
	return sqrtf(
		m_w * m_w +
		m_v.getX() * m_v.getX() +
		m_v.getY() * m_v.getY() +
		m_v.getZ() * m_v.getZ()
	);
}

Quaternion* Quaternion::normalize() {
	float norm = this->norm();
	m_w /= norm;
	m_v.divide(norm);
	return this;
}

Quaternion Quaternion::conjugate(Quaternion& result) const {
	return Quaternion(
		m_w, 
		m_v.getX() * -1,
		m_v.getY() * -1,
		m_v.getZ() * -1
	);
}

Quaternion Quaternion::inverse() const {
	float norm_square = powf(this->norm(), 2);
	return Quaternion(
		m_w / norm_square,
		m_v.getX() * - 1 / norm_square, 
		m_v.getY() * - 1 / norm_square, 
		m_v.getZ() * - 1 / norm_square 
	);
}


Quaternion* Quaternion::rotate(const Vector3f& angle, float theta) {
	theta /= 2.f;
	Quaternion q_rotation(
		cosf(deg_to_rad(theta)),
		angle.getX() * sinf(deg_to_rad(theta)),
		angle.getY() * sinf(deg_to_rad(theta)),
		angle.getZ() * sinf(deg_to_rad(theta))
	);
	q_rotation.normalize();
	
	Quaternion q_rotation_inverse = q_rotation.inverse();
	*this = q_rotation.mul(q_rotation, *this);
	*this->mul(q_rotation_inverse);
	return this;
}

void Quaternion::rotation_quaternion_to_matrix(Matrix4x4& mat) const {
	float w2 = m_w * m_w;
	float x2 = m_v.getX() * m_v.getX();
	float y2 = m_v.getY() * m_v.getY();
	float z2 = m_v.getZ() * m_v.getZ();
	  
	//1 - 2y² - 2z²  
	mat.set(0, 1 - 2  * y2 -  2 * z2);
	//2xy - 2wz
	mat.set(1, 2 * m_v.getX() * m_v.getY() - 2 * m_w * m_v.getZ());
	//2xz + 2wy 
	mat.set(2, 2 * m_v.getX() * m_v.getZ() + 2 * m_w * m_v.getY());
	//0
	mat.set(3, 0);

	//2xy + 2wz   
	mat.set(4, 2 * m_v.getX() * m_v.getY() + 2 * m_w * m_v.getZ());
	//1 - 2x² - 2z² 
	mat.set(5, 1 - 2 * x2 - 2 * z2);
	//2yz - 2wx 
	mat.set(6, 2 * m_v.getY() * m_v.getZ() - 2 * m_w * m_v.getX());
	//0
	mat.set(7, 0);

	//2xz - 2wy   
	mat.set(8, 2 * m_v.getX() * m_v.getZ() - 2 * m_w * m_v.getY());
	//2yz + 2wx  
	mat.set(9, 2 * m_v.getY() * m_v.getZ() + 2 * m_w * m_v.getX());
	//1 - 2x² - 2y² 
	mat.set(10, 1 - 2 * x2 - 2 * y2);
	//0
	mat.set(11, 0);

	//0
	mat.set(12, 0);
	//0
	mat.set(13, 0);
	//0
	mat.set(14, 0);
	//0
	mat.set(15, 1);
}

Quaternion Quaternion::get_rotation_quaternion(Vector3f& axis, float theta) {
	theta /= 2.f;
	axis.normalize();
	Quaternion q(
		cosf(deg_to_rad(theta)),
		axis.getX() * sinf(deg_to_rad(theta)),
		axis.getY() * sinf(deg_to_rad(theta)),
		axis.getZ() * sinf(deg_to_rad(theta))
	);
	return q;
}

Quaternion Quaternion::get_rotation_quaternion(const float& x_axis, const float& y_axis, const float& z_axis, float theta) {
	theta /= 2.f;
	Vector3f axis(x_axis, y_axis, z_axis);
	axis.normalize();
	Quaternion q(
		cosf(deg_to_rad(theta)),
		axis.getX() * sinf(deg_to_rad(theta)),
		axis.getY() * sinf(deg_to_rad(theta)),
		axis.getZ() * sinf(deg_to_rad(theta))
	);
	return q;
}