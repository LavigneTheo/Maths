#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Maths/matrix/Matrix4x4.h"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unit_test
{		
	TEST_CLASS(Matrix4x4Test)
	{
	public:

		TEST_METHOD(set_data) {
			float data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
			Matrix4x4 m1;

			for (int i = 0; i < 16; i++)
				Assert::AreEqual(0.f, m1.get(i));

			m1.set_data(data1);

			for (int i = 0; i < 16; i++)
				Assert::AreEqual(*(data1 + i), m1.get(i));

			float data2[] = { 1, 10.01, 3, 4.865, -5.098, 6, -7.0987, 8, 9.09876, 10, 11, 20, 13, 12, 15, 16 };
			 m1.set_data(data2);

			 for (int i = 0; i < 16; i++)
				 Assert::AreEqual(*(data2 + i), m1.get(i));

		}
		
		TEST_METHOD(mul)
		{
			float data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
			Matrix4x4 m1(data1);

			m1.mul(5);
			Assert::AreEqual(5.f, m1.get(0));
			Assert::AreEqual(10.f, m1.get(1));
			Assert::AreEqual(15.f, m1.get(2));
			Assert::AreEqual(20.f, m1.get(3));

			Assert::AreEqual(25.f, m1.get(4));
			Assert::AreEqual(30.f, m1.get(5));
			Assert::AreEqual(35.f, m1.get(6));
			Assert::AreEqual(40.f, m1.get(7));

			Assert::AreEqual(45.f, m1.get(8));
			Assert::AreEqual(50.f, m1.get(9));
			Assert::AreEqual(55.f, m1.get(10));
			Assert::AreEqual(60.f, m1.get(11));

			Assert::AreEqual(65.f, m1.get(12));
			Assert::AreEqual(70.f, m1.get(13));
			Assert::AreEqual(75.f, m1.get(14));
			Assert::AreEqual(80.f, m1.get(15));

			float data3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
			m1.set_data(data3);

			float data2[] = { 7.9, 1.02, 98, 6.09, 5, 2.9, 7, 8.71, 9, 8.1, 11, 3.98, 9.1, 14, 6.46, 16 };
			Matrix4x4 m2(data2);

			m1.mul(m2);
			Assert::AreEqual(81.3f, m1.get(0));
			Assert::AreEqual(87.12f, m1.get(1));
			Assert::AreEqual(170.84f, m1.get(2));
			Assert::AreEqual(99.45f, m1.get(3));

			Assert::AreEqual(205.3f, m1.get(4));
			Assert::AreEqual(191.2f, round(m1.get(5)*1000)/1000.0f);
			Assert::AreEqual(660.68f, m1.get(6));
			Assert::AreEqual(238.57f, m1.get(7));

			Assert::AreEqual(329.3f, round(m1.get(8) * 1000) / 1000.0f);
			Assert::AreEqual(295.28f, round(m1.get(9) * 1000) / 1000.0f);
			Assert::AreEqual(1150.52f, round(m1.get(10) * 1000) / 1000.0f);
			Assert::AreEqual(377.69000f, round(m1.get(11) * 1000) / 1000.0f);

			Assert::AreEqual(round(453.299999f * 1000)/1000.f, round(m1.get(12) * 1000) / 1000.0f);
			Assert::AreEqual(round(399.36f * 1000) / 1000.f, round(m1.get(13) * 1000) / 1000.0f);
			Assert::AreEqual(1640.36f, round(m1.get(14) * 1000) / 1000.0f);
			Assert::AreEqual(516.81f, round(m1.get(15) * 1000) / 1000.0f);

		}

	};
}