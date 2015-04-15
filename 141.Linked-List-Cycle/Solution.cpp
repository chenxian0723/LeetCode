/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *p1=head;
        ListNode *p2=head;
        do{         //每次p2走2步，p1走1步，由于p2走得快，只需判断p2是否为空
            if(p2->next)
                p2=p2->next;
            else
                return false;
            if(p2->next)
                p2=p2->next;
            else
                return false;
            p1=p1->next;
        }while(p1!=p2);
        return true;
    }
};
