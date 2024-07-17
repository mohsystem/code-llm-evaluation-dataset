#include <nlohmann/json.hpp>

nlohmann::json deserialize_json(const std::string& json_data) {
    return nlohmann::json::parse(json_data);
}