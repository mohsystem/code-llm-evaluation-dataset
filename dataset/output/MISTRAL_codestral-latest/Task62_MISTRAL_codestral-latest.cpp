#include <nlohmann/json.hpp>
#include <string>

std::string getRootElement(const std::string& jsonString) {
    nlohmann::json jsonData = nlohmann::json::parse(jsonString);
    return jsonData.begin().key();
}