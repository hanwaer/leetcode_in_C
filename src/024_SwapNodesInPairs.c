/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space. You may not modify the
 * values in the list, only nodes itself can be changed.
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode *head) {
    struct ListNode *new_head = NULL;
    struct ListNode *p1 = head, *p2 = NULL, *temp = NULL;
    struct ListNode *last = NULL;

    if (!head) 
        return NULL;
    if (!head->next)
        return head;

    new_head = head->next;    
    for (; p1 && (p2 = p1->next); p1 = p1->next) {
        if (last)
            last->next = p2;
        temp = p2->next;
        p2->next = p1;
        p1->next = temp;
        last = p1;
    }

    return new_head;
}
