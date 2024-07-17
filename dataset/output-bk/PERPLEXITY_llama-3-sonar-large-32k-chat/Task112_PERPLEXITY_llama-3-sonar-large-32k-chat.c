#include <mongoc/mongoc.h>

int main() {
    mongoc_client_t *client;
    mongoc_collection_t *collection;
    bson_t *doc;
    bson_error_t error;
    char *str;

    // Create
    mongoc_init();
    client = mongoc_client_new("mongodb://localhost:27017");
    collection = mongoc_client_get_collection(client, "mydatabase", "mycollection");
    doc = BCON_NEW("name", BCON_UTF8("John"), "age", BCON_INT32(30));
    mongoc_collection_insert_one(collection, doc, NULL, NULL, &error);
    bson_destroy(doc);

    // Read
    doc = mongoc_collection_find_one(collection, BCON_NEW, NULL, NULL, &error);
    str = bson_as_json(doc, NULL);
    printf("%s
", str);
    bson_free(str);
    bson_destroy(doc);

    // Update
    bson_t *update = BCON_NEW("$set", "{", "age", BCON_INT32(31), "}");
    mongoc_collection_update_one(collection, BCON_NEW, update, NULL, NULL, &error);
    bson_destroy(update);

    // Delete
    mongoc_collection_delete_one(collection, doc, NULL, &error);
    bson_destroy(doc);
    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_cleanup();
    return 0;
}