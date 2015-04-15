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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==head)
            return head;
        ListNode *p1=head,*p2=head;
        while(p2 && p2->next){
            p1=p1->next;
            p2=p2->next->next;
            if(p1==p2){       //相遇后，此时p2路程是p1的两倍，注意此时p2可能已经绕了n圈
                if(p1==head)
                    return head;
                p1=head;      //p1从头开始走，p2继续走，大家每次都走1步，再次相遇即为开始循环的地方
                while(true){
                    p2=p2->next;
                    p1=p1->next;
                    if(p2==p1)
                        return p1;
                }
            }
        }
        return NULL;
    }
};
