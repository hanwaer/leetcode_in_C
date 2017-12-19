/*
 * Reverse a singly linked list.
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode *head) {
    struct ListNode *p, *x, *y;

    if (!head)
        return NULL;

    x = head;
    p = NULL;
    y = head->next;

    while (y) {
        x->next = p;
        p = x;
        x = y;
        y = y->next;
    }
    x->next = p;

    return x;
}
