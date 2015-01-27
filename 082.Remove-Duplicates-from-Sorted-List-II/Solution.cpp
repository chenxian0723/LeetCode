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
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *vhead=new ListNode(0);
        ListNode *pre=vhead;
        vhead->next=head;
        
        bool flag=false;    //用来记录是否找到相同值
        while(head->next!=NULL){
            flag=false;
            while(head->val==head->next->val){    //循环判断是否相等
                flag=true;
                head=head->next;
                if(head->next==NULL){   //如果已经到链表最后就直接返回
                    pre->next=NULL;
                    return vhead->next;
                }
            }
            if(flag){   //找到相同值，跳过这些点
                pre->next=head->next;
                head=head->next;
            }
            else{   //没有找到相同值，将指针后移一位继续寻找
                pre=pre->next;
                head=head->next;
            }
        }
        
        return vhead->next;
    }
};
