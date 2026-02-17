set(TargetName "CommonLib")

add_library(
	${TargetName}
    STATIC
    "include/AppInfo.h"
	"src/AppInfo.cpp"
)

target_include_directories(
	${TargetName}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${ASIO_DIR}/include
	${NLOHMANN_JSON_DIR}/include
	${SPDLOG_DIR}/include
)
