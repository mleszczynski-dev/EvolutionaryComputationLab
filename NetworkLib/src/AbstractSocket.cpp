#include "AbstractSocket.h"

void AbstractSocket::setErrorCallback(std::function<void()> callback)
{
    errorCallback_ = std::move(callback);
}
