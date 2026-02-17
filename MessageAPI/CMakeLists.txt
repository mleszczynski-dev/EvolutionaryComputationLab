set(TargetName "MessageAPI")

add_library(
	${TargetName}
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
    ${TargetName}
    PRIVATE
	CommonLib
)

target_include_directories(
	${TargetName}
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
