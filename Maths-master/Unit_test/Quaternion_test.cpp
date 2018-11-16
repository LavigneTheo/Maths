#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Maths/vector/Vector3f.h"
#include <math.h>
#include "../Maths/vector/Vector3f.h"
#include "../Maths/matrix/Matrix4x4.h"
#include "../Maths/quaternion/Quaternion.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unit_test
{
	TEST_CLASS(Quaternion_test)
	{
	public:

		TEST_METHOD(set_data) {
			Vector3f v(1.02f, 2.03f, 3.09f);
			Quaternion q;
			
			Assert::AreEqual(0.f, q.getV().getX());
			Assert::AreEqual(0.f , q.getV().getY());
			Assert::AreEqual(0.f, q.getV().getZ());
			Assert::AreEqual(0.f, q.getW());

			Quaternion q2(1.057f, v);

			Assert::AreEqual(1.02f, q2.getV().getX());
			Assert::AreEqual(2.03f, q2.getV().getY());
			Assert::AreEqual(3.09f, q2.getV().getZ());
			Assert::AreEqual(1.057f, q2.getW());

			Quaternion q3(1.057f, 1.02f, 2.03f, 3.09f);

			Assert::AreEqual(1.02f, q3.getV().getX());
			Assert::AreEqual(2.03f, q3.getV().getY());
			Assert::AreEqual(3.09f, q3.getV().getZ());
			Assert::AreEqual(1.057f, q3.getW());

			q.setW(2.09f);
			q.setV(v);

			Assert::AreEqual(2.09f, q.getW());
			Assert::AreEqual(1.02f, q.getV().getX());
			Assert::AreEqual(2.03f, q.getV().getY());
			Assert::AreEqual(3.09f, q.getV().getZ());
			
			q.setV(1.098f, 2.456f, 3.567f);

			Assert::AreEqual(1.098f, q.getV().getX());
			Assert::AreEqual(2.456f, q.getV().getY());
			Assert::AreEqual(3.567f, q.getV().getZ());
		}

		TEST_METHOD(add_sub)
		{
			Quaternion q1(2.09, 1.05f, 2.87f, 678.0987f);
			Quaternion q2(1.456, 1.94f, 2.406f, 478.876f);

			q1.add(q2);

			Assert::AreEqual(3.546f, q1.getW());
			Assert::AreEqual(2.99f, q1.getV().getX());
			Assert::AreEqual(5.276f, q1.getV().getY());
			Assert::AreEqual(1156.9747f, q1.getV().getZ());

			q1.sub(q2);

			Assert::AreEqual(1.05f, round(q1.getV().getX() * 100) / 100.f);
			Assert::AreEqual(2.87f, round(q1.getV().getY() * 100) / 100.f);
			Assert::AreEqual(678.0988f, round(q1.getV().getZ() * 10000) / 10000.f);
			Assert::AreEqual(2.09f, round(q1.getW() * 100) / 100.f);

		}

		TEST_METHOD(mul) {
			Quaternion q1(1.098, 56.098, 45.948, 4.4598);
			Quaternion q2(5.987, 49.987, 4.981, 67.450);
			
			q1.mul(q2);

			Assert::AreEqual(-3327.277f, round(q1.getW() * 1000) / 1000.f);
			Assert::AreEqual(3467.723f, round(q1.getV().getX() * 1000) / 1000.f);
			Assert::AreEqual(-3280.318f, round(q1.getV().getY() * 1000) / 1000.f);
			Assert::AreEqual(-1916.618f, round(q1.getV().getZ() * 1000) / 1000.f);
			
		}

		TEST_METHOD(normalize) {
			Quaternion q1(1.098, 56.098, 45.948, 4.4598);

			q1.normalize();

			Assert::AreEqual(0.015f, round(q1.getW() * 1000) / 1000.f);
			Assert::AreEqual(0.772f, round(q1.getV().getX() * 1000) / 1000.f);
			Assert::AreEqual(0.632f, round(q1.getV().getY() * 1000) / 1000.f);
			Assert::AreEqual(0.061f, round(q1.getV().getZ() * 1000) / 1000.f);

			q1.setV(-1.987f, 67.765f, -567.98f);
			q1.setW(-987.97);

			q1.normalize();

			Assert::AreEqual(-0.865f, round(q1.getW() * 1000) / 1000.f);
			Assert::AreEqual(-0.002f, round(q1.getV().getX() * 1000) / 1000.f);
			Assert::AreEqual(0.059f, round(q1.getV().getY() * 1000) / 1000.f);
			Assert::AreEqual(-0.498f, round(q1.getV().getZ() * 1000) / 1000.f);
		}

		TEST_METHOD(conjugate) {
			Quaternion q1(1.098, 56.098, 45.948, 4.4598);
			Quaternion q2 = q1.conjugate(q2);

			Assert::AreEqual(1.098f, round(q2.getW() * 1000) / 1000.f);
			Assert::AreEqual(-56.098f, round(q2.getV().getX() * 1000) / 1000.f);
			Assert::AreEqual(-45.948f, round(q2.getV().getY() * 1000) / 1000.f);
			Assert::AreEqual(-4.460f, round(q2.getV().getZ() * 1000) / 1000.f);
		}

		TEST_METHOD(rotate) {
			Quaternion q1(0, 2, 0, 0);

			q1.rotate(Vector3f(sqrtf(2.f)/2.f, 0, sqrtf(2.f) / 2.f), 90);
			
			Assert::AreEqual(0.0f, round(q1.getW() * 1000) / 1000.f);
			Assert::AreEqual(1.f, round(q1.getV().getX() * 1000) / 1000.f);
			Assert::AreEqual(round(sqrtf(2.f) * 1000) / 1000.f, round(q1.getV().getY() * 1000) / 1000.f);
			Assert::AreEqual(1.f, round(q1.getV().getZ() * 1000) / 1000.f);
		}

		TEST_METHOD(rotation_matrix) {
			Quaternion q1 = Quaternion::get_rotation_quaternion(
				Vector3f(1, 0, 0), 90.f
			);
			Matrix4x4 rotation_matrix;
			q1.rotation_quaternion_to_matrix(rotation_matrix);

			Assert::AreEqual(round_3dec(1.f), round_3dec(rotation_matrix.get(0)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(1)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(2)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(3)));

			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(4)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(5)));
			Assert::AreEqual(round_3dec(-1.f), round_3dec(rotation_matrix.get(6)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(7)));

			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(8)));
			Assert::AreEqual(round_3dec(1.f), round_3dec(rotation_matrix.get(9)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(10)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(11)));

			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(12)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(13)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(14)));
			Assert::AreEqual(round_3dec(1.f), round_3dec(rotation_matrix.get(15)));

			q1 = Quaternion::get_rotation_quaternion(
				Vector3f(1, 1, -1.98f), -87.09f
			);
			q1.rotation_quaternion_to_matrix(rotation_matrix);

			Assert::AreEqual(round_3dec(0.2110998f), round_3dec(rotation_matrix.get(0)));
			Assert::AreEqual(round_3dec(-0.6523656f), round_3dec(rotation_matrix.get(1)));
			Assert::AreEqual(round_3dec(-0.7279121f), round_3dec(rotation_matrix.get(2)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(3)));

			Assert::AreEqual(round_3dec(0.9730307f), round_3dec(rotation_matrix.get(4)));
			Assert::AreEqual(round_3dec(0.2110998f), round_3dec(rotation_matrix.get(5)));
			Assert::AreEqual(round_3dec(0.0929952f), round_3dec(rotation_matrix.get(6)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(7)));

			Assert::AreEqual(round_3dec(0.0929952f), round_3dec(rotation_matrix.get(8)));
			Assert::AreEqual(round_3dec(-0.7279121f), round_3dec(rotation_matrix.get(9)));
			Assert::AreEqual(round_3dec(0.6793349f), round_3dec(rotation_matrix.get(10)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(11)));

			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(12)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(13)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(14)));
			Assert::AreEqual(round_3dec(1.f), round_3dec(rotation_matrix.get(15)));
			

			q1 = Quaternion::get_rotation_quaternion(
				Vector3f(1.9, 8.75, -76.98), 322.09f
			);
			q1.rotation_quaternion_to_matrix(rotation_matrix);

			Assert::AreEqual(round_3dec(0.7891037f), round_3dec(rotation_matrix.get(0)));
			Assert::AreEqual(round_3dec(-0.6097242f), round_3dec(rotation_matrix.get(1)));
			Assert::AreEqual(round_3dec(-0.0745101f), round_3dec(rotation_matrix.get(2)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(3)));

			Assert::AreEqual(round_3dec(0.6108924f), round_3dec(rotation_matrix.get(4)));
			Assert::AreEqual(round_3dec(0.7916669f), round_3dec(rotation_matrix.get(5)));
			Assert::AreEqual(round_3dec(-0.0086025f), round_3dec(rotation_matrix.get(6)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(7)));

			Assert::AreEqual(round_3dec(0.0642323f), round_3dec(rotation_matrix.get(8)));
			Assert::AreEqual(round_3dec(-0.0387294f), round_3dec(rotation_matrix.get(9)));
			Assert::AreEqual(round_3dec(0.9971831), round_3dec(rotation_matrix.get(10)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(11)));

			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(12)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(13)));
			Assert::AreEqual(round_3dec(0.f), round_3dec(rotation_matrix.get(14)));
			Assert::AreEqual(round_3dec(1.f), round_3dec(rotation_matrix.get(15)));

		}

		TEST_METHOD(get_rotation_quaternion) {
			Quaternion q1 = Quaternion::get_rotation_quaternion(
				Vector3f(sqrtf(2.f) / 2.f, 0, sqrtf(2.f) / 2.f), 90.f
			);


			Assert::AreEqual(0.707f, round(q1.getW() * 1000) / 1000.f);
			Assert::AreEqual(0.5f, round(q1.getV().getX() * 1000) / 1000.f);
			Assert::AreEqual(0.0f, round(q1.getV().getY() * 1000) / 1000.f);
			Assert::AreEqual(0.5f, round(q1.getV().getZ() * 1000) / 1000.f);

			q1 = Quaternion::get_rotation_quaternion(
				Vector3f(1, 0, 0), 90.f
			);

			Assert::AreEqual(0.707f, round(q1.getW() * 1000) / 1000.f);
			Assert::AreEqual(0.707f, round(q1.getV().getX() * 1000) / 1000.f);
			Assert::AreEqual(0.0f, round(q1.getV().getY() * 1000) / 1000.f);
			Assert::AreEqual(0.0f, round(q1.getV().getZ() * 1000) / 1000.f);

			q1 = Quaternion::get_rotation_quaternion(
				Vector3f(0, 1, 0), 229.0f
			);

			Assert::AreEqual(-0.415f, round(q1.getW() * 1000) / 1000.f);
			Assert::AreEqual(0.f, round(q1.getV().getX() * 1000) / 1000.f);
			Assert::AreEqual(0.910f, round(q1.getV().getY() * 1000) / 1000.f);
			Assert::AreEqual(0.0f, round(q1.getV().getZ() * 1000) / 1000.f);

			q1 = Quaternion::get_rotation_quaternion(
				Vector3f(1, 1, 0), 229.0f
			);

			Assert::AreEqual(-0.415f, round(q1.getW() * 1000) / 1000.f);
			Assert::AreEqual(0.643f, round(q1.getV().getX() * 1000) / 1000.f);
			Assert::AreEqual(0.643f, round(q1.getV().getY() * 1000) / 1000.f);
			Assert::AreEqual(0.0f, round(q1.getV().getZ() * 1000) / 1000.f);

			q1 = Quaternion::get_rotation_quaternion(
				Vector3f(1, 1, -1.98f), -87.09f
			);
			
			Assert::AreEqual(round_3dec(0.7248335f), round(q1.getW() * 1000) / 1000.f);
			Assert::AreEqual(round_3dec(-0.2831365f), round(q1.getV().getX() * 1000) / 1000.f);
			Assert::AreEqual(round_3dec(-0.2831365f), round(q1.getV().getY() * 1000) / 1000.f);
			Assert::AreEqual(round_3dec(0.5606102f), round(q1.getV().getZ() * 1000) / 1000.f);
		}

		

		
	};
}