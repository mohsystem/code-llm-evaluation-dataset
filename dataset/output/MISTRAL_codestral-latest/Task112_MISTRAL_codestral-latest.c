// C
// Note: C does not have a built-in MongoDB driver. You need to use a third-party library like libmongoc.
// This example uses libmongoc.
#include <mongoc.h>

int main() {
    // Create a connection
    mongoc_client_t *client;
    mongoc_database_t *database;
    mongoc_collection_t *collection;
    bson_error_t error;
    bson_oid_t oid;
    bson_t *doc;
    char *str;

    mongoc_init();
    client = mongoc_client_new("mongodb://localhost:27017");

    // Create a database
    database = mongoc_client_get_database(client, "test-database");

    // Create a collection
    collection = mongoc_client_get_collection(client, "test-database", "test-collection");

    // Insert a document
    doc = BCON_NEW("name", BCON_UTF8("John"), "age", BCON_INT32(30));
    if (!mongoc_collection_insert_one(collection, doc, NULL, NULL, &error)) {
        fprintf(stderr, "%s\n", error.message);
    }
    bson_destroy(doc);

    // Read a document
    doc = BCON_NEW("name", BCON_UTF8("John"));
    bson_t *result = mongoc_collection_find_one(collection, doc, NULL, NULL, NULL, &error);
    if (result) {
        str = bson_as_json(result, NULL);
        printf("%s\n", str);
        bson_free(str);
        bson_destroy(result);
    }
    bson_destroy(doc);

    // Update a document
    doc = BCON_NEW("name", BCON_UTF8("John"));
    bson_t *update = BCON_NEW("$set", "{", "age", BCON_INT32(31), "}");
    if (!mongoc_collection_update_one(collection, doc, update, NULL, NULL, &error)) {
        fprintf(stderr, "%s\n", error.message);
    }
    bson_destroy(doc);
    bson_destroy(update);

    // Delete a document
    doc = BCON_NEW("name", BCON_UTF8("John"));
    if (!mongoc_collection_delete_one(collection, doc, NULL, NULL, &error)) {
        fprintf(stderr, "%s\n", error.message);
    }
    bson_destroy(doc);

    mongoc_collection_destroy(collection);
    mongoc_database_destroy(database);
    mongoc_client_destroy(client);
    mongoc_cleanup();

    return 0;
}