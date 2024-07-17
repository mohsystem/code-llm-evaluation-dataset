// C++
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

int main() {
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{}};
    auto collection = conn["test"]["testCollection"];

    // Create
    auto doc = bsoncxx::builder::stream::document{}
        << "name" << "MongoDB"
        << "type" << "database"
        << "count" << 1
        << "versions" << bsoncxx::builder::stream::open_array << "v3.2" << "v3.0" << "v2.6" << bsoncxx::builder::stream::close_array
        << "info" << bsoncxx::builder::stream::open_document << "x" << 203 << "y" << 102 << bsoncxx::builder::stream::close_document
        << bsoncxx::builder::stream::finalize;
    collection.insert_one(doc.view());

    // Read
    auto cursor = collection.find({{"name", "MongoDB"}});
    for (auto&& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }

    // Update
    collection.update_one({{"name", "MongoDB"}}, bsoncxx::builder::stream::document{} << "$set" << bsoncxx::builder::stream::open_document << "count" << 2 << bsoncxx::builder::stream::close_document << bsoncxx::builder::stream::finalize);

    // Delete
    collection.delete_one({{"name", "MongoDB"}});

    return 0;
}