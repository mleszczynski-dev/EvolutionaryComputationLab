add_library(
	EvolutionaryNodeLib
    STATIC
	"src/TcpSocket.cpp"
	"include/AbstractSocket.h")

target_include_directories(
	EvolutionaryNodeLib
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
	${ASIO_DIR}/include
	${NLOHMANN_JSON_DIR}/include
	${SPDLOG_DIR}/include)
