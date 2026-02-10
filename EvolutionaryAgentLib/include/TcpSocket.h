#pragma once

#include "AbstractSocket.h"

#include <memory>

class TcpSocket
	: public AbstractSocket
	, public std::enable_shared_from_this<TcpSocket>
{
public:
	~TcpSocket() override;
};
