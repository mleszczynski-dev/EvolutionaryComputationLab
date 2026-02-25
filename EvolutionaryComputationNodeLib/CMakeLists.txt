project("EvolutionaryComputationNodeLib" LANGUAGES CXX)

add_library(
	${PROJECT_NAME}
    STATIC
	"include/GeneticAlgorithm.h"
	"src/GeneticAlgorithm.cpp"
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
	CommonLib
    NetworkLib
)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
