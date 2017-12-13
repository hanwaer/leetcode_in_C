/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     struct ListNode *next;
 *      * };
 *       */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head;
    struct ListNode *n = &head;
    int extra = 0;
    while (l1 || l2 || extra) {
        struct ListNode *node = calloc(1, sizeof(struct ListNode));
        node->val = ((l1?l1->val:0) + (l2?l2->val:0) + extra) % 10;
        extra = ((l1?l1->val:0) + (l2?l2->val:0) + extra) / 10;
        l1 = l1?l1->next:NULL;
        l2 = l2?l2->next:NULL;
        n->next = node;
        n = n->next;
    }

    return head.next;
}
