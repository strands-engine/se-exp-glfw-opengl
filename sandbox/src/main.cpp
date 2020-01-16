#include "oglexp.h"
#include "oglexp/entry_point.h"

class sandbox_app : public oglexp::application
{
public:
	sandbox_app() = default;
	virtual ~sandbox_app() = default;
};

oglexp::application * create_oglexp_application()
{
	return new sandbox_app();
}

//int main()
//{
//	auto app = std::make_unique<sandbox_app>();
//
//	app->run();
//
//	return 0;
//}