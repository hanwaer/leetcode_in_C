/*
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getNextNode(struct ListNode **a, struct ListNode **b) {
    struct ListNode *ret;
    if ((*a)->val <= (*b)->val) {
        ret = *a;
        *a = ret->next;
    } else {
        ret = *b;
        *b = ret->next;
    }
    return ret;
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head;
    struct ListNode *curr;
    
    if (!l1 && !l2)
        return NULL;
    else if (!l1)
        return l2;
    else if (!l2)
        return l1;
        
    head = getNextNode(&l1, &l2);
    curr = head;
    
    while (l1 && l2) {
        curr->next = getNextNode(&l1, &l2);
        curr = curr->next;
    }
    if (l1) {curr->next = l1;}
    if (l2) {curr->next = l2;}
    

    return head;
} 