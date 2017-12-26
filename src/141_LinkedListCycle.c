/*
 * Given a linked list, determine if it has a cycle in it.
 *
 * Follow up:
 * Can you solve it without using extra space?
 */

bool hasCycle(struct ListNode *head) {
    struct ListNode *p1, *p2;
    p1 = p2 = head;
    while (p1 && p2) {
        p1 = p1->next;
        p2 = p2->next;
        if (!p2)
            break;
        p2 = p2->next;
        if (p2 && (p1 == p2))
            return true;
    }
    return false;
}