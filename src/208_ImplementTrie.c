/*
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 */

struct TrieNode {
    bool w;
    struct TrieNode *childs[26];
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    struct TrieNode *t;

    t = malloc(sizeof(struct TrieNode));
    if (!t) return NULL;

    t->w = false;
    int i;
    for (i = 0; i < 26; i++) {
        t->childs[i] = NULL;
    }
    return t;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode *root, char *word) {
    int i;
    struct TrieNode *p = root;

    for (i = 0; i < strlen(word); i++) {
        if (p->childs[word[i]-'a'] == NULL) {
            p->childs[word[i]-'a'] = trieCreate();
        }
        p = p->childs[word[i]-'a'];
    }
    p->w = true;
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode *root, char *word) {
    int i;
    struct TrieNode *p = root;

    for (i = 0; i < strlen(word); i++) {
        if (p->childs[word[i]-'a'] == NULL)
            return false;
        p = p->childs[word[i]-'a'];
    }
    return p->w;
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    int i;
    struct TrieNode *p = root;

    for (i = 0; i < strlen(prefix); i++) {
        if (p->childs[prefix[i]-'a'] == NULL)
            return false;
        p = p->childs[prefix[i]-'a'];
    }

    return true;
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    int i;

    for (i = 0; i < 26; i++) {
        if (root->childs[i] != NULL) {
            trieFree(root->childs[i]);
            free(root->childs[i]);
        }
    }
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);
