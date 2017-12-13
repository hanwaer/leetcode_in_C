/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode *merge2lists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode dummy = {0};
    struct ListNode *p = &dummy;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if (l1 != NULL) p->next = l1;
    if (l2 != NULL) p->next = l2;
    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (lists==NULL || listsSize==0)
        return NULL;
        
    int end = listsSize - 1;
    while (end > 0) {
        int begin = 0;
        while (begin < end) {
            lists[begin] = merge2lists(lists[begin], lists[end]);
            begin++;
            end--;
        }
    }
    return lists[0];
}