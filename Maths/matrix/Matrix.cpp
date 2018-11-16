#include "Matrix.h"

using namespace mtl;

template<typename N>
Matrix<N>::Matrix(unsigned int x, unsigned int y) : mX(x), mY(y) {
	mData = (N*)malloc(sizeof(N) * x * y);
};

template<typename N>
Matrix<N>::Matrix(N arr[], unsigned int x, unsigned int y) : mX(x), mY(y) {
	mData = (N*)malloc(sizeof(N) * x * y);
	for (int i = 0; i < mY; i++)
		for (int j = 0; j < mX; j++)
			*(mData + i * mX + j) = (N)arr[i * mX + j];
};

template<typename N>
Matrix<N>::Matrix(std::vector<N>& v, unsigned int x, unsigned int y) : mX(x), mY(y) {
	mData = (N*)malloc(sizeof(N) * x * y);
	for (int i = 0; i < mY; i++)
		for (int j = 0; j < mX; j++)
			*(mData + i * mX + j) = v.at(i * mX + j);
};

template<typename N>
Matrix<N> Matrix<N>::mul(Matrix<N>& m1, Matrix<N>& m2) {

	if (m1.mX != m2.mY)
		throw std::invalid_argument("These matrix rank can't be multiplied.");

	std::vector<N> v;

	for (int y = 0; y < m1.mY; y++) {
		for (int x = 0; x < m2.mX; x++) {
			float sum = 0;
			for (int index = 0; index < m1.mX; index++) {
				N v1 = m1.mData[y * m1.mX + index];
				N v2 = m2.mData[index * m2.mX + x];
				sum += v1 * v2;
			}
			v.push_back(sum);
		}
	}

	return Matrix<N>(v, m2.mX, m1.mY);
}

template<typename N>
Matrix<N> Matrix<N>::mul(Matrix<N>& m1, N scalar) {
	std::vector<N> values;

	for (unsigned int y = 0; y < m1.mY; y++)
		for (unsigned int x = 0; x < m1.mX; x++)
			values.push_back(m1.mData[y * m1.mX + x] * scalar);

	return Matrix<N>(values, m1.mX, m1.mY);
}

template<typename N>
void Matrix<N>::print() const {
	std::cout << "[";
	for (int y = 0; y < mY; y++) {
		for (int x = 0; x < mX; x++) {
			if (x == mX - 1 && y == mY -1)
				std::cout << mData[y * mX + x] << "]" << std::endl;
			else
				std::cout << mData[y * mX + x] << ", ";
		}
		std::cout << "\n";
	}
}

template<typename N>
void Matrix<N>::identity() {
	if (mX != mY)
		throw std::invalid_argument("Can't set identity on non-square matrix");

	for (int y = 0; y < mY; y++)
		for (int x = 0; x < mX; x++)
			if (x == y)
				mData[y * mX + x] = 1;
			else
				mData[y * mX + x] = 0;
}

template<typename N>
Matrix<N>& Matrix<N>::operator=(const Matrix<N>& m) {
	free(mData);
	mX = m.mX;
	mY = m.mY;
	mData = (N*)malloc(sizeof(N) * m.mX * m.mY);
	for (int y = 0; y < mY; y++)
		for (int x = 0; x < mX; x++)
			mData[y * mX + x] = m.mData[y * mX + x];
	return *this;
}

template Matrix<int>;
template Matrix<float>;
template Matrix<double>;
