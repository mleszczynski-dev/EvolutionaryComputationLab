#pragma once

class AbstractClient
{
public:
	virtual ~AbstractClient() = default;

    void setAutoreconnect(bool value);
    bool isAutoreconnect() const;

private:
    bool autoreconnect_ = false;
};
