#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace sparky
{
	namespace maths
	{
		inline float ToRadians(float degrees)
		{
			return degrees * (M_PI / 180.f);
		}
	}
}