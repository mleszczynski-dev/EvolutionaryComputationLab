#pragma once

#include "AbstractRequest.h"

class AuthorizationRequest
	: public AbstractRequest
{
public:
	void toJson(nlohmann::json& document) const override;
	void fromJson(const nlohmann::json& document) override;
};
