#include "AbstractClient.h"

void AbstractClient::setAutoreconnect(bool value)
{
    autoreconnect_ = value;
}

bool AbstractClient::isAutoreconnect() const
{
    return autoreconnect_;
}
