add_library(
	EvolutionaryNodeLib
    STATIC
	"include/GeneticAlgorithm.h"
	"src/GeneticAlgorithm.cpp"
	"include/TcpServer.h"
	"include/TcpServerPtr.h"
	"src/TcpServer.cpp")

target_link_libraries(
    EvolutionaryNodeLib
    PUBLIC
    NetworkLib)

target_include_directories(
	EvolutionaryNodeLib
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
	${ASIO_DIR}/include
	${NLOHMANN_JSON_DIR}/include
	${SPDLOG_DIR}/include)
