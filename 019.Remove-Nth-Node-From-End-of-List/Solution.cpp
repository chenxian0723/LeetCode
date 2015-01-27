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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *vhead=new ListNode(0);
        vhead->next=head;
        ListNode *p1=head;  
        ListNode *p2=vhead;   //让p2比head多一个节点，可以方便地处理移除头结点等问题。
        
        for(int i=0;i<n;i++){   //将p1移动n个单位
            p1=p1->next;
        }
        
        while(p1){    //同时移动p1和p2
            p1=p1->next;
            p2=p2->next;
        }
        p2->next=p2->next->next;    //删除节点
        
        return vhead->next;
    }
};
