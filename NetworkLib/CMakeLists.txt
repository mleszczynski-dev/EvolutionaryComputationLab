set(TargetName "NetworkLib")

add_library(
	${TargetName}
    STATIC
	"include/AbstractClient.h"
	"include/AbstractServer.h"
	"include/AbstractSocket.h"
	"include/TcpClient.h"
	"include/TcpServer.h"
	"include/TcpServerPtr.h"
	"include/TcpSocket.h"
	"src/AbstractClient.cpp"
	"src/AbstractServer.cpp"
	"src/TcpClient.cpp"
	"src/TcpServer.cpp"
	"src/TcpSocket.cpp"
)

target_link_libraries(
    ${TargetName}
    PRIVATE
	CommonLib
)

target_include_directories(
	${TargetName}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
