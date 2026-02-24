#include "Application.h"
#include "AppInfo.h"

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << AppInfo::toString() << std::endl;

    return Application::exec(argc, argv);
}
