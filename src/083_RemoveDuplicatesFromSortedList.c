/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */

struct ListNode* deleteDuplicates(struct ListNode *head) {
    if (!head)
        return NULL;

    struct ListNode *p = head, *n = head->next;

    while (n) {
        if (p->val == n->val) {
            p->next = n->next;
            n = n->next;
        } else {
            p = n;
            n = n->next;
        }
    }

    return head;
}
