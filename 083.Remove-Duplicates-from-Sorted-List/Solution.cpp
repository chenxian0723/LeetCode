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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL)
            return head;
            
        ListNode *vhead=new ListNode(0);
        vhead->next=head;
        
        ListNode *pre=head;     //直接从前两个元素开始
        head=head->next;
        while(head){
            if(pre->val==head->val)     //相同则head后移，pre不变
                head=head->next;
            else{       //不同，pre->next指向head,pre后移
                pre->next=head;
                pre=head;
                head=head->next;
            }
        }
        pre->next=NULL;
        
        return vhead->next;
    }
};
