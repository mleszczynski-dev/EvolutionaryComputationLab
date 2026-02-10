add_library(EvolutionaryAgentLib STATIC "src/TcpSocket.cpp" "include/AbstractSocket.h")

target_include_directories(EvolutionaryAgentLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${ASIO_DIR}/include ${NLOHMANN_JSON_DIR}/include ${SPDLOG_DIR}/include)
