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
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL)
            return head;
        ListNode *vhead=new ListNode(0);
        vhead->next=head;
        ListNode *pre=vhead;
        while(head!=NULL&&head->next!=NULL){      //每2个都非空时
            ListNode *temp=head->next;
            head->next=temp->next;
            pre->next=temp;
            temp->next=head;
            pre=head;
            head=head->next;      //head只需要变成head->next即可，因为head前面已经插入了一个节点
        }
        return vhead->next;
    }
};
