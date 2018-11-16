#include <iostream>
#include "LavMaths.h"

using namespace mtl;

int main() {
	float arr1[] = { 1, 2, 3, 4 };
	float arr2[] = { 1, 2, 3, 4, 5, 6 };

	Matrix<float> m1(arr1, 2, 2);
	Matrix<float> m2(arr2, 3, 2);

	m1.print();
	m2.print();

	Matrix<float> m3 = Matrix<float>::mul(m1, m2);

	m3.print();
	std::cout << *(m3.mData + 1) << std::endl;

	m1.~Matrix();
	std::getchar();
}