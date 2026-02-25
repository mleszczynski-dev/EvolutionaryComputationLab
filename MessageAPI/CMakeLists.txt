project("MessageAPI" LANGUAGES CXX)

add_library(
	${PROJECT_NAME}
    STATIC
	"include/AbstractMessage.h"
	"include/AbstractNotification.h"
	"include/AbstractReply.h"
	"include/AbstractRequest.h"
	"include/AuthorizationReply.h"
	"include/AuthorizationRequest.h"
    "src/AbstractMessage.cpp"
	"src/AbstractNotification.cpp"
	"src/AbstractReply.cpp"
	"src/AbstractRequest.cpp"
	"src/AuthorizationReply.cpp"
	"src/AuthorizationRequest.cpp"
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
