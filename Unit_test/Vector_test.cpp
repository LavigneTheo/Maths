#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Maths/vector/Vector3f.h"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unit_test
{
	TEST_CLASS(Vector3f_test)
	{
	public:

		TEST_METHOD(set_data) {
			Vector3f vec1;
			Assert::AreEqual(0.f, vec1.getX());
			Assert::AreEqual(0.f, vec1.getY());
			Assert::AreEqual(0.f, vec1.getZ());

			Vector3f vec2(1.2f, 2.987f, 3.987f);
			Assert::AreEqual(1.2f, vec2.getX());
			Assert::AreEqual(2.987f, vec2.getY());
			Assert::AreEqual(3.987f, vec2.getZ());

			vec1.set(vec2);
			Assert::AreEqual(1.2f, vec1.getX());
			Assert::AreEqual(2.987f, vec1.getY());
			Assert::AreEqual(3.987f, vec1.getZ());

			vec1.set(1.6, 98.87, 1234.987);
			Assert::AreEqual(1.6f, vec1.getX());
			Assert::AreEqual(98.87f, vec1.getY());
			Assert::AreEqual(1234.987f, vec1.getZ());
		}

		TEST_METHOD(add_sub)
		{
			Vector3f vec1;
			Vector3f vec2(1.2f, 2.987f, 3.987f);

			vec1.add(vec2),
			Assert::AreEqual(1.2f, vec1.getX());
			Assert::AreEqual(2.987f, vec1.getY());
			Assert::AreEqual(3.987f, vec1.getZ());

			vec1.add(1.f, 2.2f, 3.3f),
			Assert::AreEqual(2.2f, vec1.getX());
			Assert::AreEqual(5.187f, round(vec1.getY() * 1000)/ 1000.f);
			Assert::AreEqual(7.287f, round(vec1.getZ() * 1000) / 1000.f);

			vec1.sub(1, 2.2f, 3.3f),
			Assert::AreEqual(1.2f, round(vec1.getX() * 1000) / 1000.f);
			Assert::AreEqual(2.987f, round(vec1.getY() * 1000) / 1000.f);
			Assert::AreEqual(3.987f, round(vec1.getZ() * 1000) / 1000.f);

			vec1.sub(vec2),
			Assert::AreEqual(0.f, round(vec1.getX() * 1000) / 1000.f);
			Assert::AreEqual(0.f, round(vec1.getY() * 1000) / 1000.f);
			Assert::AreEqual(0.f, round(vec1.getZ() * 1000) / 1000.f);

		}

		TEST_METHOD(set) {
			Vector3f vec1;
			vec1.set(1.05f, 2.09f, 3.87f);
			Assert::AreEqual(1.05f, round(vec1.getX() * 1000) / 1000.f);
			Assert::AreEqual(2.09f, round(vec1.getY() * 1000) / 1000.f);
			Assert::AreEqual(3.87f, round(vec1.getZ() * 1000) / 1000.f);

			Vector3f vec2(1.2f, 2.987f, 3.987f);
			vec1.set(vec2);
			Assert::AreEqual(1.2f, round(vec1.getX() * 1000) / 1000.f);
			Assert::AreEqual(2.987f, round(vec1.getY() * 1000) / 1000.f);
			Assert::AreEqual(3.987f, round(vec1.getZ() * 1000) / 1000.f);
		}

		TEST_METHOD(length) {
			Vector3f vec1;
			Assert::AreEqual(0.f, vec1.length());

			vec1.set(1.f, 9.f, 10.f);
			Assert::AreEqual(13.491f, round(vec1.length() * 1000) / 1000.f);

			vec1.set(16.086f, 345.098f, 34.23f);
			Assert::AreEqual(347.164f, round(vec1.length() * 1000) / 1000.f);
		}

		TEST_METHOD(cross) {
			Vector3f vec1(2, 3, 4);
			Vector3f vec2(5, 6, 7);

			vec1 = vec1.cross(vec2);
			Assert::AreEqual(-3.f, round(vec1.getX() * 1000) / 1000.f);
			Assert::AreEqual(6.f, round(vec1.getY() * 1000) / 1000.f);
			Assert::AreEqual(-3.f, round(vec1.getZ() * 1000) / 1000.f);
			
			vec1.set(1.2f, 4.56f, 23.87f);
			vec2.set(34.871f, 8.2f, 87.89f);

			vec1 = vec1.cross(vec2);
			Assert::AreEqual(205.044f, round(vec1.getX() * 1000) / 1000.f);
			Assert::AreEqual(726.903f, round(vec1.getY() * 1000) / 1000.f);
			Assert::AreEqual(-149.172f, round(vec1.getZ() * 1000) / 1000.f);
		}

		TEST_METHOD(dot_product) {
			Vector3f vec1(9, 2, 7);
			Vector3f vec2(4, 8, 10);

			Assert::AreEqual(122.f, vec1.dot_product(vec2));

			vec1.set(1.2f, 4.56f, 23.87f);
			vec2.set(34.871f, 8.2f, 87.89f);

			Assert::AreEqual(2177.1716f, round(vec1.dot_product(vec2) * 10000) / 10000.f);
		}

		TEST_METHOD(mul) {
			Vector3f vec1(9.987, 2.098, 7.8765);
			Vector3f vec2(4.9876, 8.876, 10.8765);
			Vector3f vec3;

			vec1.mul(vec2, vec3);

			Assert::AreEqual(49.811f, round(vec3.getX() * 1000) / 1000.f);
			Assert::AreEqual(18.622f, round(vec3.getY() * 1000) / 1000.f);
			Assert::AreEqual(85.669f, round(vec3.getZ() * 1000) / 1000.f);

			vec1.mul(vec2);

			Assert::AreEqual(49.811f, round(vec1.getX() * 1000) / 1000.f);
			Assert::AreEqual(18.622f, round(vec1.getY() * 1000) / 1000.f);
			Assert::AreEqual(85.669f, round(vec1.getZ() * 1000) / 1000.f);

			vec2.mul(3.67, vec3);
		
			Assert::AreEqual(18.304f, round(vec3.getX() * 1000) / 1000.f);
			Assert::AreEqual(32.575f, round(vec3.getY() * 1000) / 1000.f);
			Assert::AreEqual(39.917f, round(vec3.getZ() * 1000) / 1000.f);

			vec2.mul(3.67);

			Assert::AreEqual(18.304f, round(vec2.getX() * 1000) / 1000.f);
			Assert::AreEqual(32.575f, round(vec2.getY() * 1000) / 1000.f);
			Assert::AreEqual(39.917f, round(vec2.getZ() * 1000) / 1000.f);
			
		}

		TEST_METHOD(divide) {
			Vector3f vec1(9.98, 2.987, 7.987);

			vec1.divide(3.141);

			Assert::AreEqual(3.177f, round(vec1.getX() * 1000) / 1000.f);
			Assert::AreEqual(0.951f, round(vec1.getY() * 1000) / 1000.f);
			Assert::AreEqual(2.543f, round(vec1.getZ() * 1000) / 1000.f);

			
		}

		TEST_METHOD(normalize) {
			Vector3f vec1(1, 1, 2);

			vec1.normalize();

			Assert::AreEqual(round_3dec(1 / (float)sqrtf(6)), round(vec1.getX() * 1000) / 1000.f);
			Assert::AreEqual(round_3dec(1 / (float)sqrtf(6)), round(vec1.getY() * 1000) / 1000.f);
			Assert::AreEqual(round_3dec((float)sqrtf(2 / 3.0f)), round(vec1.getZ() * 1000) / 1000.f);
		}

		TEST_METHOD(intersect) {
			Vector3f ray(0, 0, 1);
			Vector3f plane(0, 0, 1);

			Vector3f r0(0, 0, 0);
			Vector3f p0(0, 0, 10);

			float t;
			Vector3f::intersect(plane, ray, p0, r0, t);

		}
	};
}