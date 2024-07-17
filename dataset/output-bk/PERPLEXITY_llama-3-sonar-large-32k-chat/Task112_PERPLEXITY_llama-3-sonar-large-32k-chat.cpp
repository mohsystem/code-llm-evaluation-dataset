#include <bsoncxx/bsoncxx.hpp>
#include <mongocxx/mongocxx.hpp>

int main() {
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{}};

    // Create
    bsoncxx::builder::stream::document doc;
    doc << "name" << "John" << "age" << 30;
    conn["mydatabase"]["mycollection"].insert_one(doc.view());

    // Read
    auto cursor = conn["mydatabase"]["mycollection"].find({});
    for (const bsoncxx::document::view& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }

    // Update
    bsoncxx::builder::stream::document update;
    update << "$set" << bsoncxx::builder::stream::open_document << "age" << 31 << bsoncxx::builder::stream::close_document;
    conn["mydatabase"]["mycollection"].update_one({}, update.view());

    // Delete
    conn["mydatabase"]["mycollection"].delete_one({});
    return 0;
}