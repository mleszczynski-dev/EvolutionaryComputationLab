project("NetworkLib" LANGUAGES CXX)

add_library(
	${PROJECT_NAME}
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
    ${PROJECT_NAME}
    PRIVATE
	CommonLib
)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
