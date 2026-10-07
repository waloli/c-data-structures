#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define HASH_TABLE_SIZE 10
#define HASH_KEY_MAX 63
#define HASH_VALUE_MAX 127

typedef struct HashEntry {
    char key[HASH_KEY_MAX + 1];
    char value[HASH_VALUE_MAX + 1];
    struct HashEntry *next;
} HashEntry;

typedef struct {
    HashEntry *buckets[HASH_TABLE_SIZE];
} HashTable;

void hash_table_init(HashTable *table);
unsigned long hash_string(const char *key);
int hash_table_insert(HashTable *table, const char *key, const char *value);
const char *hash_table_search(const HashTable *table, const char *key);
int hash_table_delete(HashTable *table, const char *key);
void hash_table_free(HashTable *table);

#endif
