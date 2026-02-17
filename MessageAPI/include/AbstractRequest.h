#pragma once

#include "AbstractMessage.h"

class AbstractRequest
	: public AbstractMessage
{
public:
	~AbstractRequest() override = default;

	void toJson(nlohmann::json& document) const override;
	void fromJson(const nlohmann::json& document) override;
};
