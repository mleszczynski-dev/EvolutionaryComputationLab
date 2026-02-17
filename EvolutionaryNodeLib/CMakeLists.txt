set(TargetName "EvolutionaryNodeLib")

add_library(
	${TargetName}
    STATIC
	"include/GeneticAlgorithm.h"
	"include/TcpServer.h"
	"include/TcpServerPtr.h"
	"src/GeneticAlgorithm.cpp"
	"src/TcpServer.cpp")

target_link_libraries(
    ${TargetName}
    PUBLIC
    NetworkLib)

target_include_directories(
	${TargetName}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
	${ASIO_DIR}/include
	${NLOHMANN_JSON_DIR}/include
	${SPDLOG_DIR}/include)
