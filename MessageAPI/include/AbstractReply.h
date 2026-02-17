#pragma once

#include "AbstractMessage.h"

class AbstractReply
	: public AbstractMessage
{
public:
	~AbstractReply() override = default;

	void toJson(nlohmann::json& document) const override;
	void fromJson(const nlohmann::json& document) override;
};
