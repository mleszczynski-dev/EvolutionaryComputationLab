#pragma once

#include "AbstractRequest.h"

#include <string>

class AuthorizationRequest
	: public AbstractRequest
{
public:
	inline static const std::string type = "AuthorizationRequest";

	void toJson(nlohmann::json& document) const override = 0;
	void fromJson(const nlohmann::json& document) override = 0;
};
