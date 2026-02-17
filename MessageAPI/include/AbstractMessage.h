#pragma once

#include <nlohmann/json_fwd.hpp>

class AbstractMessage
{
public:
	virtual ~AbstractMessage() = default;

	virtual void toJson(nlohmann::json& document) const = 0;
	virtual void fromJson(const nlohmann::json& document) = 0;
};

void to_json(nlohmann::json& document, const AbstractMessage& message);
void from_json(const nlohmann::json& document, AbstractMessage& message);
