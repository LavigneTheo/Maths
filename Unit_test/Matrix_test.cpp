#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Maths/matrix/Matrix4x4.h"
#include "../Maths/matrix/Matrix.h"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mtl;

namespace Unit_test
{		
	TEST_CLASS(Matrix4x4fTest)
	{
	public:

		TEST_METHOD(setData) {
			float data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
			Matrix4x4f m1;

			for (int i = 0; i < 16; i++)
				Assert::AreEqual(0.f, m1.mData[i]);

			m1.setData(data1);

			for (int i = 0; i < 16; i++)
				Assert::AreEqual(*(data1 + i), m1.mData[i]);

			float data2[] = { 1, 10.01, 3, 4.865, -5.098, 6, -7.0987, 8, 9.09876, 10, 11, 20, 13, 12, 15, 16 };
			 m1.setData(data2);

			 for (int i = 0; i < 16; i++)
				 Assert::AreEqual(*(data2 + i), m1.mData[i]);

		}
		
		TEST_METHOD(mul)
		{
			float data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
			Matrix4x4f m1(data1);

			m1 = Matrix4x4f::mul(m1, 5.f);

			Assert::AreEqual(5.f,  m1.mData[0]);
			Assert::AreEqual(10.f, m1.mData[1]);
			Assert::AreEqual(15.f, m1.mData[2]);
			Assert::AreEqual(20.f, m1.mData[3]);

			Assert::AreEqual(25.f, m1.mData[4]);
			Assert::AreEqual(30.f, m1.mData[5]);
			Assert::AreEqual(35.f, m1.mData[6]);
			Assert::AreEqual(40.f, m1.mData[7]);

			Assert::AreEqual(45.f, m1.mData[8]);
			Assert::AreEqual(50.f, m1.mData[9]);
			Assert::AreEqual(55.f, m1.mData[10]);
			Assert::AreEqual(60.f, m1.mData[11]);

			Assert::AreEqual(65.f, m1.mData[12]);
			Assert::AreEqual(70.f, m1.mData[13]);
			Assert::AreEqual(75.f, m1.mData[14]);
			Assert::AreEqual(80.f, m1.mData[15]);

			float data3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
			m1.setData(data3);

			float data2[] = { 7.9, 1.02, 98, 6.09, 5, 2.9, 7, 8.71, 9, 8.1, 11, 3.98, 9.1, 14, 6.46, 16 };
			Matrix4x4f m2(data2);

			m1 = Matrix4x4f::mul(m1, m2);

			Assert::AreEqual(81.3f, m1.mData[0]);
			Assert::AreEqual(87.12f, m1.mData[1]);
			Assert::AreEqual(170.84f, m1.mData[2]);
			Assert::AreEqual(99.45f, m1.mData[3]);

			Assert::AreEqual(205.3f, m1.mData[4]);
			Assert::AreEqual(191.2f, round_3dec(m1.mData[5]));
			Assert::AreEqual(660.68f, m1.mData[6]);
			Assert::AreEqual(238.57f, m1.mData[7]);

			Assert::AreEqual(329.3f, round_3dec(m1.mData[8]));
			Assert::AreEqual(295.28f, round_3dec(m1.mData[9]));
			Assert::AreEqual(1150.52f, round_3dec(m1.mData[10]));
			Assert::AreEqual(377.69000f, round_3dec(m1.mData[11]));

			Assert::AreEqual(round_3dec(453.299999f), round_3dec(m1.mData[12]));
			Assert::AreEqual(round(399.36f * 1000) / 1000.f, round_3dec(m1.mData[13]));
			Assert::AreEqual(1640.36f, round_3dec(m1.mData[14]));
			Assert::AreEqual(516.81f, round_3dec(m1.mData[15]));

		}

		TEST_METHOD(identity)
		{
			float data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
			Matrix4x4f m1(data1);
			m1.identity();

			Assert::AreEqual(1.f, m1.mData[0]);
			Assert::AreEqual(0.f, m1.mData[1]);
			Assert::AreEqual(0.f, m1.mData[2]);
			Assert::AreEqual(0.f, m1.mData[3]);

			Assert::AreEqual(0.f, m1.mData[4]);
			Assert::AreEqual(1.f, round_3dec(m1.mData[5]));
			Assert::AreEqual(0.f, m1.mData[6]);
			Assert::AreEqual(0.f, m1.mData[7]);

			Assert::AreEqual(0.f, round_3dec(m1.mData[8]));
			Assert::AreEqual(0.f, round_3dec(m1.mData[9]));
			Assert::AreEqual(1.f, round_3dec(m1.mData[10]));
			Assert::AreEqual(0.f, round_3dec(m1.mData[11]));

			Assert::AreEqual(0.f, round(m1.mData[12]));
			Assert::AreEqual(0.f, round(m1.mData[13]));
			Assert::AreEqual(0.f, round_3dec(m1.mData[14]));
			Assert::AreEqual(1.f, round_3dec(m1.mData[15]));
		}

	};

	TEST_CLASS(MatrixTest) {
		TEST_METHOD(mul2)
		{
			float arr1[] = { 1, 2, 3, 4 };
			float arr2[] = { 1, 2, 3, 4, 5, 6 };

			Matrix<float> m1(arr1, 2, 2);
			Matrix<float> m2(arr2, 3, 2);

			Matrix<float> m3 = Matrix<float>::mul(m1, m2);

			Assert::AreEqual(9.f, round_3dec(m3.mData[0]));
			Assert::AreEqual(12.f, round_3dec(m3.mData[1]));
			Assert::AreEqual(15.f, round_3dec(m3.mData[2]));

			Assert::AreEqual(19.f, round_3dec(m3.mData[3]));
			Assert::AreEqual(26.f, round_3dec(m3.mData[4]));
			Assert::AreEqual(33.f, round_3dec(m3.mData[5]));

			m3 = Matrix<float>::mul(m1, 4.f);

			Assert::AreEqual(4.f, round_3dec(m3.mData[0]));
			Assert::AreEqual(8.f, round_3dec(m3.mData[1]));
			Assert::AreEqual(12.f, round_3dec(m3.mData[2]));
			Assert::AreEqual(16.f, round_3dec(m3.mData[3]));

		}
	};
}