#pragma once
#include <iostream>
#include <array>
#include "../Utils.h"

class Matrix4x4
{
private:
	float* m_data;
	bool m_data_dynamicly_allodated = false;
public:
	Matrix4x4(float* data);
	Matrix4x4();
	float* get_data() const;

	float get(const int& index) const;
	void set(const int& index, const float& value);
	void set_data(float* data);

	void identity();
	static void get_projection_matrix(Matrix4x4& projection, const int& WIDRH, const int& HEIGHT);
	
	void mul(const Matrix4x4& mat);
	void mul(const float& scalar);

	void print() const;
	
	void translate(const float x, const float y, const float z);

	~Matrix4x4();
};


