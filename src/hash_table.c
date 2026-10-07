#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

unsigned long hash_string(const char *key)
{
    unsigned long hash = 0;

    if (key == NULL) {
        return 0;
    }

    for (const unsigned char *p = (const unsigned char *)key; *p != '\0'; p++) {
        hash += *p;
    }

    return hash % HASH_TABLE_SIZE;
}

void hash_table_init(HashTable *table)
{
    if (table == NULL) {
        return;
    }

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        table->buckets[i] = NULL;
    }
}

int hash_table_insert(HashTable *table, const char *key, const char *value)
{
    if (table == NULL || key == NULL || value == NULL ||
        strlen(key) > HASH_KEY_MAX || strlen(value) > HASH_VALUE_MAX) {
        return 0;
    }

    unsigned long index = hash_string(key);
    HashEntry *current = table->buckets[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            strcpy(current->value, value);
            return 1;
        }
        current = current->next;
    }

    HashEntry *entry = malloc(sizeof(*entry));
    if (entry == NULL) {
        return 0;
    }

    strcpy(entry->key, key);
    strcpy(entry->value, value);
    entry->next = table->buckets[index];
    table->buckets[index] = entry;
    return 1;
}

const char *hash_table_search(const HashTable *table, const char *key)
{
    if (table == NULL || key == NULL) {
        return NULL;
    }

    unsigned long index = hash_string(key);
    const HashEntry *current = table->buckets[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return NULL;
}

int hash_table_delete(HashTable *table, const char *key)
{
    if (table == NULL || key == NULL) {
        return 0;
    }

    unsigned long index = hash_string(key);
    HashEntry *current = table->buckets[index];
    HashEntry *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (previous == NULL) {
                table->buckets[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return 1;
        }

        previous = current;
        current = current->next;
    }

    return 0;
}

void hash_table_free(HashTable *table)
{
    if (table == NULL) {
        return;
    }

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashEntry *current = table->buckets[i];
        while (current != NULL) {
            HashEntry *next = current->next;
            free(current);
            current = next;
        }
        table->buckets[i] = NULL;
    }
}
