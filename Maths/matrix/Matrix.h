#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

namespace mtl {

	template<typename N>
	class Matrix {
	protected:
		unsigned int mX, mY;

	public:
		N* mData;

		Matrix(unsigned int x, unsigned int y);
		Matrix(N arr[], unsigned int x, unsigned int y);
		Matrix(std::vector<N>& v, unsigned int x, unsigned int y);

		~Matrix() { free(mData); }

		static Matrix<N> mul(Matrix<N>& m1, Matrix<N>& m2);
		static Matrix<N> mul(Matrix<N>& m1, N scalar);

		void print() const;

		Matrix<N>& operator=(const Matrix<N>& m);

		void identity();
	};
}
