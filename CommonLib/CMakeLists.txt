project("CommonLib" LANGUAGES CXX)

add_library(
	${PROJECT_NAME}
    STATIC
    "include/AppInfo.h"
	"include/JsonFile.h"
	"include/LoggerInitializer.h"
	"src/AppInfo.cpp"
	"src/JsonFile.cpp"
	"src/LoggerInitializer.cpp"
)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${ASIO_DIR}/include
	${NLOHMANN_JSON_DIR}/include
	${SPDLOG_DIR}/include
)
