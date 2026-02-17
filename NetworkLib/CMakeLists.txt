set(TargetName "NetworkLib")

add_library(
	${TargetName}
    STATIC
	"include/AbstractClient.h"
	"include/AbstractServer.h"
	"include/AbstractSocket.h"
	"include/TcpClient.h"
	"include/TcpSocket.h"
	"src/AbstractClient.cpp"
	"src/AbstractServer.cpp"
	"src/TcpClient.cpp"
	"src/TcpSocket.cpp")

target_include_directories(
	${TargetName}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
	${ASIO_DIR}/include
	${NLOHMANN_JSON_DIR}/include
	${SPDLOG_DIR}/include)
