#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"
#include "prime.c"
#define HT_PRIME_1 3
#define HT_PRIME_2 11
#define HT_INITIAL_BASE_SIZE 50

// Initialize an item in the hash table

static Item* initItem(const char *k, const char *v)
{
    Item *i = malloc(sizeof(Item));
    i->key = strdup(k);
    i->value = strdup(v);
    printf("Initialized an item successfully!\n");
    return i;
}

static HashTable* newSize(const int baseSize)
{
    HashTable *ht = xmalloc(sizeof(HashTable));
    ht->baseSize = baseSize;
    ht->size = nextPrime(ht->baseSize);
    ht->count = 0;
    ht->items = xcalloc((size_t)ht->size, sizeof(Item*));
    return ht;
}

static void resize(HashTable *ht, const int baseSize)
{
    if (baseSize < HT_INITIAL_BASE_SIZE)
    {
        printf("Error! Smaller than base size!\n");
        return;
    }
    HashTable *newHashTable = newSize(baseSize);
    for (int i = 0; i < ht->size; i++)
    {
        Item *item = ht->items[i];
        if (item != NULL && item != &HT_DELETED_ITEM)
        {
            insertItem(newHashTable, item->key, item->value);
        }
    }

    ht->baseSize = newHashTable->baseSize;
    ht->count = newHashTable->count;

    const int tmpSize = ht->size;
    ht->size = newHashTable->size;
    newHashTable->size = tmpSize;

    Item* *tmpItems = ht->items;
    ht->items = newHashTable->items;
    newHashTable->items = tmpItems;

    removeHashTable(newHashTable);
}

HashTable* initHashTable()
{
    printf("Initialized a hash table successfully!\n");
    return newSize(HT_INITIAL_BASE_SIZE);
}

static void removeItem(Item *i)
{
    free(i->key);
    free(i->value);
    free(i);
    printf("Removed the item successfully!\n");
}

void removeHashTable(HashTable *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        Item *item = ht->items[i];
        if (item != NULL)
        {
            removeItem(item);
        }
    }
    free(ht->items);
    free(ht);
    printf("Removed the hash table successfully!\n");
}

static int hashFunction(const char *s, const int a, const int m)
{
    long hash = 0;
    const int stringLength = strlen(s);
    for (int i = 0; i < stringLength; i++)
    {
        hash += (long)pow(a, stringLength - (i + 1)) * s[i];
        hash = hash % m;
    }
    return (int)hash;
}

static int getHash(const char *s, const int num_buckets, const int attempt)
{
    const int hashA = hashFunction(s, HT_PRIME_1, num_buckets);
    const int hashB = hashFunction(s, HT_PRIME_2, num_buckets);
    printf("Hashed successfully!\n");
    return (hashA + (attempt * (hashB + 1))) % num_buckets;
}

// To insert a new key-value pair, we iterate through indexes until we find an empty bucket.
// We then insert the item into that bucket and increment the hash table's count attribute, to indicate a new item has been added.
// A hash table's count attribute will become useful when we look at resizing in the next section.

void insertItem(HashTable *ht, const char *key, const char *value)
{
    Item *item = initItem(key, value);
    int index = getHash(item->key, ht->size, 0;
    Item *cur_item = ht->items[index];
    int i = 1;
    while (cur_item != NULL && cur_item !=HT_DELETED_ITEM)
    {
        index = getHash(item->key, ht->size, i);
        cur_item = ht->items[index];
        i++;
    }
    ht->items[index] = item;
    ht->count++;
    printf("Insert the item successfully!\n");
}

// Searching is similar to inserting, but at each iteration of the while loop,
// we check whether the item's key matches the key we're searching for.
// If it does, we return the item's value. 
// If the while loop hits a NULL bucket, we return NULL, to indicate that no value was found.
char* searchItem(HashTable *ht, const char *key)
{
    int index = getHash(key, ht->size, 0);
    Item *item = ht->items[index];
    int i = 1;
    while (item != NULL)
    {
        if (item != &HT_DELETED_ITEM)
        {
            if (strcmp(item->key, key) == 0)
            {
                return item->value;
            }
        }
        index = getHash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    return NULL;
}

// Deleting from an open addressed hash table is more complicated than inserting or searching. 
// The item we wish to delete may be part of a collision chain. 
// Removing it from the table will break that chain, and will make finding items in the tail of the chain impossible.
// To solve this, instead of deleting the item, we simply mark it as deleted.
static Item HT_DELETED_ITEM = {NULL, NULL};

void deleteItem(HashTable *ht, const char *key)
{
    int index = getHash(key, ht->size, 0);
    Item *item = ht->items[index];
    int i = 1;
    while (item != NULL)
    {
        if (item != &HT_DELETED_ITEM)
        {
            if (strcmp(item->key, key) == 0)
            {
                removeItem(item);
                ht->items[index] = &HT_DELETED_ITEM;
            }
        }
        index = getHash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    ht->count--;
}