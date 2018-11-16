#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Maths/matrix/Matrix4x4.h"
#include <math.h>
#include "../Maths/Utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unit_test
{
	TEST_CLASS(Utils_test)
	{
	public:

		TEST_METHOD(deg_conversion) {
			
			Assert::AreEqual(1.74533f, round(deg_to_rad(100.f) * 100000) / 100000.f);
			Assert::AreEqual(1.13446f, round(deg_to_rad(64.99999978265f) * 100000) / 100000.f);
			Assert::AreEqual(3.49066f, round(deg_to_rad(200.0) * 100000) / 100000.f);

		}


	};
}