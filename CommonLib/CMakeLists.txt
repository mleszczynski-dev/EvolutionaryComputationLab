set(TargetName "CommonLib")

add_library(
	${TargetName}
    STATIC
	"include/dummy.h")

target_include_directories(
	${TargetName}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
	${ASIO_DIR}/include
	${NLOHMANN_JSON_DIR}/include
	${SPDLOG_DIR}/include)
