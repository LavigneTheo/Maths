#pragma once
#include "Matrix.h"

template<typename N>
class Matrix3x3 : Matrix
{
private:
	bool m_data_dynamicly_allodated = false;
public:
	Matrix3x3(N* data);
	Matrix3x3();
	N* get_data() const;

	float get(const int& index) const;
	void set(const int& index, const N& value);
	void set_data(N* data);

	


	void print() const;

	void translate(const float x, const float y, const float z);

	~Matrix3x3f();
};
