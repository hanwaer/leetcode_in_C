#ifndef __INT_HASH_H_
#define __INT_HAHS_H_

#define ROOM 1024

struct kv {
    int key; 
    int value;
};

struct bucket {
    int len;
    int cap;
    struct int_kv *items;
};

struct bucket map[ROOM];
void hinit() {
    memset(map, 0, sizeof(struct bucket) * ROOM);    
}

int hash(int key) {
    return (unsigned int)key % ROOM;
}

int hget(int key, int *value) {
    int idx = hash(key);
    int i;
    for (i = 0; i < map[idx].len; i++) {
        if (map[idx].items[i].key == key) {
            *value = map[idx].items[i].value;
            return 0;
        }
    }
    return -1; 
}

void hset(int key, int value) {
    int idx = hash(key);
    int i; 
    if (map[idx].len == 0) {
        map[idx].cap = 32;
        map[idx].items = malloc(32 * sizeof(struct kv));
    } else {
        for (i = 0; i < map[idx].len; i++) {
            if (map[idx].items[i].key == key) {
                map[idx].items[i].value = value;
                return;
            }
        }
        if (map[idx].len + 1 > map[idx].cap) {
            map[idx].cap += 32;
            map[idx].items = realloc(map[idx].items, (map[idx].cap + 32) * sizeof(struct kv));    
        }

    }

    map[idx].items[map[idx].len].key = key;
    map[idx].items[map[idx].len++].value = value;
}

#endif

