#pragma once
#include <iostream>
#include <array>
#include "../Utils.h"
#include "Matrix.h"

namespace mtl {

	
	class Matrix4x4f : public Matrix<float>
	{
	private:

	protected:

	public:
		Matrix4x4f(float arr[]);
		Matrix4x4f();
		Matrix4x4f(const Matrix<float>& m) : Matrix<float>::Matrix(m.mData, 4, 4) {}

		static Matrix4x4f mul(Matrix4x4f& m1, Matrix4x4f& m2);
		static Matrix4x4f mul(Matrix4x4f& m1, float scalar);

		void setData(float arr[]);
	};



}
