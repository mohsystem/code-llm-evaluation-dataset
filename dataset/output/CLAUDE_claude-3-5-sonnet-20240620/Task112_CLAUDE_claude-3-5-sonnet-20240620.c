
#include <stdio.h>
#include <stdlib.h>
#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main() {
    mongoc_client_t *client;
    mongoc_database_t *database;
    mongoc_collection_t *collection;
    bson_error_t error;
    bson_t *doc;
    mongoc_cursor_t *cursor;
    const bson_t *found_doc;

    mongoc_init();

    client = mongoc_client_new("mongodb://localhost:27017");
    database = mongoc_client_get_database(client, "testdb");
    collection = mongoc_client_get_collection(client, "testdb", "users");

    // Create
    doc = BCON_NEW("name", BCON_UTF8("John Doe"),
                   "age", BCON_INT32(30),
                   "city", BCON_UTF8("New York"));
    if (!mongoc_collection_insert_one(collection, doc, NULL, NULL, &error)) {
        fprintf(stderr, "Insert failed: %s\
", error.message);
    } else {
        printf("Document inserted\
");
    }
    bson_destroy(doc);

    // Read
    doc = BCON_NEW("name", BCON_UTF8("John Doe"));
    cursor = mongoc_collection_find_with_opts(collection, doc, NULL, NULL);
    if (mongoc_cursor_next(cursor, &found_doc)) {
        char *str = bson_as_canonical_extended_json(found_doc, NULL);
        printf("Found document: %s\
", str);
        bson_free(str);
    }
    bson_destroy(doc);
    mongoc_cursor_destroy(cursor);

    // Update
    doc = BCON_NEW("$set", "{", "age", BCON_INT32(31), "}");
    bson_t *query = BCON_NEW("name", BCON_UTF8("John Doe"));
    if (!mongoc_collection_update_one(collection, query, doc, NULL, NULL, &error)) {
        fprintf(stderr, "Update failed: %s\
", error.message);
    } else {
        printf("Document updated\
");
    }
    bson_destroy(doc);
    bson_destroy(query);

    // Delete
    doc = BCON_NEW("name", BCON_UTF8("John Doe"));
    if (!mongoc_collection_delete_one(collection, doc, NULL, NULL, &error)) {
        fprintf(stderr, "Delete failed: %s\
", error.message);
    } else {
        printf("Document deleted\
");
    }
    bson_destroy(doc);

    mongoc_collection_destroy(collection);
    mongoc_database_destroy(database);
    mongoc_client_destroy(client);
    mongoc_cleanup();

    return 0;
}
