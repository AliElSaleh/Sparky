#pragma once

// ReSharper disable CppInconsistentNaming
#define _USE_MATH_DEFINES
// ReSharper restore CppInconsistentNaming
#include <math.h>

namespace sparky
{
	namespace maths
	{
		inline float ToRadians(const float degrees) { return degrees * (float(M_PI) / 180.f); }
	}
}
