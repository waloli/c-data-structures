#include <stdio.h>
#include "hash_table.h"

int main(void)
{
    HashTable table;
    hash_table_init(&table);

    hash_table_insert(&table, "Ali", "Mulhouse");
    hash_table_insert(&table, "Maxime", "Metz");
    hash_table_insert(&table, "Ali", "Strasbourg");

    const char *value = hash_table_search(&table, "Ali");
    printf("Ali -> %s\n", value ? value : "not found");

    hash_table_delete(&table, "Maxime");
    printf("Maxime -> %s\n", hash_table_search(&table, "Maxime") ? "found" : "not found");

    hash_table_free(&table);
    return 0;
}
