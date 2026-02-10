#include <asio/version.hpp>
#include <nlohmann/detail/abi_macros.hpp>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

#include <iostream>
#include <string>

std::string asio_version()
{
	return std::format("{}.{}.{}", ASIO_VERSION / 100000, ASIO_VERSION / 100 % 1000, ASIO_VERSION % 100);
}

std::string nlohmann_json_version()
{
	return std::format("{}.{}.{}", NLOHMANN_JSON_VERSION_MAJOR, NLOHMANN_JSON_VERSION_MINOR, NLOHMANN_JSON_VERSION_PATCH);
}

std::string spdlog_version()
{
	return std::format("{}.{}.{}", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
}

int main(int argc, char* argv[])
{
	nlohmann::ordered_json app_info;
	app_info["asio version"] = asio_version();
	app_info["nlohmann/json version"] = nlohmann_json_version();
	app_info["spdlog version"] = spdlog_version();

	std::cout << app_info.dump(4, ' ') << std::endl;

	return 0;
}
