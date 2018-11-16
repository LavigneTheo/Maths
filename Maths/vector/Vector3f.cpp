#include "Vector3f.h"
#include "Vector3f.h"


Vector3f::Vector3f() :
	m_x(0), m_y(0), m_z(0) {
	
}

Vector3f::Vector3f(const float x, const float y, const float z) : 
	m_x(x), m_y(y), m_z(z) {

}

void Vector3f::set(const float& x, const float& y, const float& z) {
	m_x = x;
	m_y = y;
	m_z = z;
}

void Vector3f::add(const float& x, const float& y, const float& z) {
	m_x += x;
	m_y += y;
	m_z += z;
}

void Vector3f::sub(const float& x, const float& y, const float& z) {
	m_x -= x;
	m_y -= y;
	m_z -= z;
}

void Vector3f::set(const Vector3f& vec) {
	m_x = vec.getX();
	m_y = vec.getY();
	m_z = vec.getZ();
}

Vector3f* Vector3f::add(const Vector3f& vec) {
	m_x += vec.getX();
	m_y += vec.getY();
	m_z += vec.getZ();
	return this;
}

void Vector3f::sub(const Vector3f& vec) {
	m_x -= vec.getX();
	m_y -= vec.getY();
	m_z -= vec.getZ();
}

float Vector3f::getX() const {
	return m_x;
}
float Vector3f::getY() const {
	return m_y;
}
float Vector3f::getZ() const {
	return m_z;
}

void Vector3f::setX(const float& x) {
	m_x = x;
}
void Vector3f::setY(const float& y) {
	m_y = y;
}
void Vector3f::setZ(const float& z) {
	m_z = z;
}


float Vector3f::length() const {
	return sqrtf(power(m_x) + power(m_y) + power(m_z));
}

Vector3f Vector3f::cross(const Vector3f& vec) const {
	float  x = m_y * vec.getZ() - m_z * vec.getY();
	float y = m_z * vec.getX() - m_x * vec.getZ();
	float z = m_x * vec.getY() - m_y * vec.getX();
	return Vector3f(x, y, z);
}

float Vector3f::dot_product(const Vector3f& v) const {
	return m_x * v.getX() + m_y * v.getY() + m_z * v.getZ();
}

Vector3f Vector3f::mul(const Vector3f& v, Vector3f& result) const {
	result.set(
		m_x * v.getX(),
		m_y * v.getY(),
		m_z * v.getZ()
	);
	return result;
}
void Vector3f::mul(const Vector3f& v) {
	m_x *= v.getX();
	m_y *= v.getY();
	m_z *= v.getZ();
}
void Vector3f::mul(const float& scalar) {
	m_x *= scalar;
	m_y *= scalar;
	m_z *= scalar;
}
Vector3f Vector3f::mul(const float& v, Vector3f& result) const {
	result.set(
		m_x * v,
		m_y * v,
		m_z * v
	);
	return result;
}

Vector3f* Vector3f::divide(const float& scalar) {
	m_x /= scalar;
	m_y /= scalar;
	m_z /= scalar;
	return this;
}

Vector3f* Vector3f::normalize() {
	float length = this->length();
	m_x /= length;
	m_y /= length;
	m_z /= length;
	return this;
}

void Vector3f::print() {
	std::cout << '[' << m_x << ", " << m_y << ", " << m_z << ']' << std::endl;
}

bool Vector3f::intersect(const Vector3f& n, const Vector3f& l, Vector3f& p0, Vector3f& l0, float& t) {

	float denom = l.dot_product(n);
	if (denom > 0.00001) {
		p0.sub(l0);
		t = p0.dot_product(n) / denom;
		return (t >= 0);
	}
	return false;
}