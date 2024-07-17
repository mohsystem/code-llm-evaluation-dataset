// C
#include <mongoc.h>

int main () {
    mongoc_client_t *client;
    mongoc_database_t *database;
    mongoc_collection_t *collection;
    bson_t *command, reply, *insert, *query, *update;
    bson_error_t error;

    mongoc_init ();

    client = mongoc_client_new ("mongodb://localhost:27017/");
    database = mongoc_client_get_database (client, "test");
    collection = mongoc_client_get_collection (client, "test", "testCollection");

    // Create
    insert = BCON_NEW ("name", BCON_UTF8 ("MongoDB"),
                       "type", BCON_UTF8 ("database"),
                       "count", BCON_INT32 (1),
                       "versions", "[", BCON_UTF8 ("v3.2"), BCON_UTF8 ("v3.0"), BCON_UTF8 ("v2.6"), "]",
                       "info", "{", "x", BCON_INT32 (203), "y", BCON_INT32 (102), "}");
    if (!mongoc_collection_insert_one (collection, insert, NULL, NULL, &error)) {
        fprintf (stderr, "%s
", error.message);
    }

    // Read
    query = BCON_NEW ("name", BCON_UTF8 ("MongoDB"));
    if (mongoc_collection_find_one (collection, query, NULL, &reply, &error)) {
        char *str = bson_as_json (&reply, NULL);
        printf ("%s
", str);
        bson_free (str);
    }

    // Update
    query = BCON_NEW ("name", BCON_UTF8 ("MongoDB"));
    update = BCON_NEW ("$set", "{", "count", BCON_INT32 (2), "}");
    if (!mongoc_collection_update_one (collection, query, update, NULL, NULL, &error)) {
        fprintf (stderr, "%s
", error.message);
    }

    // Delete
    query = BCON_NEW ("name", BCON_UTF8 ("MongoDB"));
    if (!mongoc_collection_delete_one (collection, query, NULL, NULL, &error)) {
        fprintf (stderr, "%s
", error.message);
    }

    bson_destroy (&reply);
    bson_destroy (insert);
    bson_destroy (query);
    bson_destroy (update);
    mongoc_collection_destroy (collection);
    mongoc_database_destroy (database);
    mongoc_client_destroy (client);
    mongoc_cleanup ();

    return 0;
}