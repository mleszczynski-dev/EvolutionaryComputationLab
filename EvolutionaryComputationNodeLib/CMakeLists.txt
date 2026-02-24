set(TargetName "EvolutionaryComputationNodeLib")

add_library(
	${TargetName}
    STATIC
	"include/GeneticAlgorithm.h"
	"src/GeneticAlgorithm.cpp"
)

target_link_libraries(
    ${TargetName}
    PRIVATE
	CommonLib
    NetworkLib
)

target_include_directories(
	${TargetName}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
