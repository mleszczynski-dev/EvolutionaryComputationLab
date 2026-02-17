#pragma once

#include "AbstractReply.h"

class AuthorizationReply
	: public AbstractReply
{
public:
	void toJson(nlohmann::json& document) const override;
	void fromJson(const nlohmann::json& document) override;
};
