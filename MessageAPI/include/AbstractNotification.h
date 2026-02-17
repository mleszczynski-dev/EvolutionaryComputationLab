#pragma once

#include "AbstractMessage.h"

class AbstractNotification
	: public AbstractMessage
{
public:
	~AbstractNotification() override = default;

	void toJson(nlohmann::json& document) const override = 0;
	void fromJson(const nlohmann::json& document) override = 0;
};
