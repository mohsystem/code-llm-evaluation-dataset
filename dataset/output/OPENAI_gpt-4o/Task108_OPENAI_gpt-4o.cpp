#include <iostream>
#include <string>
#include <unordered_map>
#include <SFML/Network.hpp>

int main() {
    std::unordered_map<std::string, std::string> objects;

    sf::TcpListener listener;
    if (listener.listen(7896) != sf::Socket::Done)
        return EXIT_FAILURE;

    while (true) {
        sf::TcpSocket client;
        if (listener.accept(client) != sf::Socket::Done)
            return EXIT_FAILURE;

        char action[10], key[256], value[256];
        std::size_t received;

        client.receive(action, sizeof(action), received);
        client.receive(key, sizeof(key), received);
        client.receive(value, sizeof(value), received);
        
        if (std::string(action) == "put") {
            objects[std::string(key)] = std::string(value);
            client.send("Success", 7);
        } else if (std::string(action) == "get") {
            client.send(objects[std::string(key)].c_str(), objects[std::string(key)].size());
        }

        client.disconnect();
    }

    return 0;
}