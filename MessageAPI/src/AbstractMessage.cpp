#include "AbstractMessage.h"

void to_json(nlohmann::json& document, const AbstractMessage& message)
{
    message.toJson(document);
}

void from_json(const nlohmann::json& document, AbstractMessage& message)
{
    message.fromJson(document);
}
