struct LruEntry {
    int key;
    int value;
    struct LruEntry* prev;
    struct LruEntry* next;
    UT_hash_handle hh;
};

typedef struct LruCache {
    size_t cap;
    size_t len;
    struct LruEntry* hash;
    struct LruEntry* head;
    struct LruEntry* tail;
    struct LruEntry entries[];
} LRUCache;

static void removeFromList(struct LruCache* cache, struct LruEntry* entry) {

    if (entry == cache->head) {
        cache->head = entry->next;
    }
    if (entry == cache->tail) {
        cache->tail = entry->prev;
    }

    struct LruEntry* prev = entry->prev;
    struct LruEntry* next = entry->next;
    if (prev != NULL) { prev->next = next; }
    if (next != NULL) { next->prev = prev; }

    entry->prev = NULL;
    entry->next = NULL;
}

static void putAtHeadOfList(struct LruCache* cache, struct LruEntry* entry) {
    if (cache->head == NULL) {
        cache->head = entry;
        cache->tail = entry;
    }
    else {
        entry->next = cache->head;
        cache->head->prev = entry;
        cache->head = entry;
    }
}

LRUCache* lRUCacheCreate(int capacity) {
    if (capacity < 1) { return NULL; }
    struct LruCache* cache =
        malloc(sizeof(struct LruCache) + sizeof(struct LruEntry) * capacity);
    if (cache == NULL) { return NULL; }
    cache->cap = capacity;
    cache->len = 0;
    cache->hash = NULL;
    cache->head = NULL;
    cache->tail = NULL;
    return cache;
}

void lRUCacheFree(LRUCache* cache) {
    free(cache);
}

void lRUCachePut(LRUCache* cache, int key, int value) {

    struct LruEntry* entry = NULL;
    HASH_FIND_INT(cache->hash, &key, entry);

    // Key is found; replace value.
    if (entry != NULL) {
        entry->value = value;
        removeFromList(cache, entry);
        putAtHeadOfList(cache, entry);
    }
    // There are still spaces left in the cache; add.
    else if (cache->len < cache->cap) {
        entry = &cache->entries[cache->len++];
        entry->key = key;
        entry->value = value;
        entry->prev = NULL;
        entry->next = NULL;
        HASH_ADD_INT(cache->hash, key, entry);
        putAtHeadOfList(cache, entry);
    }
    // Evict the least recently used entry.
    else {
        entry = cache->tail;
        HASH_DEL(cache->hash, entry);
        removeFromList(cache, entry);
        entry->key = key;
        entry->value = value;
        HASH_ADD_INT(cache->hash, key, entry);
        putAtHeadOfList(cache, entry);
    }
}

int lRUCacheGet(LRUCache* cache, int key) {
    struct LruEntry* entry = NULL;
    HASH_FIND_INT(cache->hash, &key, entry);
    if (entry == NULL) {
        return -1;
    }
    removeFromList(cache, entry);
    putAtHeadOfList(cache, entry);
    return entry->value;
}
