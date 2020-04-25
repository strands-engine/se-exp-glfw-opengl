#pragma once

#include <memory>

#include "application.h"
#include "log.h"

#ifdef OXP_PLATFORM_WIN

extern oglexp::application * create_oglexp_application();

int main(int argc, char** argv)
{
	oglexp::log::init();
	OXP_CORE_INFO("Logger initialized!");
	OXP_INFO("Running oglexp engine...\n");

	auto app = create_oglexp_application();
	app->run();
	delete app;
	return 0;
}

#else
#error Only Windows platform is supported.
#endif
