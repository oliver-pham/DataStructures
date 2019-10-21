#include <stdio.h>

typedef struct Item
{
    char* key;
    char* value;
} Item;

typedef struct HashTable
{
    int size;
    int count;
    int baseSize;
    Item* *items; 
} HashTable;

void insertItem(HashTable *ht, const char *key, const char *value);
char* searchItem(HashTable *ht, const char *key);
void deleteItem(HashTable *ht, const char *key);
