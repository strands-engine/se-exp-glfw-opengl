#pragma once

#include "core.h"

namespace oglexp
{
	class OXP_API application
	{
	public:
		application() = default;
		virtual ~application() = default;

	public:
		void run();
	};
}