// C++
#include <map>
#include <string>

class CryptoKeyManager {
private:
    std::map<std::string, std::string> keys;

public:
    void addKey(const std::string& keyName, const std::string& keyValue) {
        keys[keyName] = keyValue;
    }

    std::string getKey(const std::string& keyName) {
        auto it = keys.find(keyName);
        if (it != keys.end()) {
            return it->second;
        }
        return "";
    }

    void removeKey(const std::string& keyName) {
        keys.erase(keyName);
    }
};