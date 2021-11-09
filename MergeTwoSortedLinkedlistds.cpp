/* Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]


CODE: */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *d=new ListNode(0);           /*Create a new linkedlist with head element as zero*/
        ListNode *p=d;
        if(l1==NULL)
            return l2;                          /*Check if any of the linkedlists are empty and return the other one if the one is empty*/       
        if(l2==NULL)
            return l1;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<=l2->val)
            {
                p->next=l1;
                l1=l1->next;
                
            }
            else
            {
                p->next=l2;
                l2=l2->next;
                
            }
            p=p->next;
        }
        while(l1!=NULL)
        {
            p->next=l1;
            l1=l1->next;
            p=p->next;
        }
        while(l2!=NULL)
        {
            p->next=l2;
            l2=l2->next;
            p=p->next;
        }
        return d->next;
            
    }
};


/*Another approach using Recursion*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
          ListNode* result = NULL;
        
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        
        if(l1->val <= l2->val)
        {
            result = l1; result->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            result = l2; result->next = mergeTwoLists(l1, l2->next);
        }
        return result;    
    }
};
