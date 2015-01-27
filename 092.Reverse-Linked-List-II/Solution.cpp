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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *vhead=new ListNode(0);
        vhead->next=head;
        ListNode *pre=vhead;
        
        for(int i=1;i<m;i++){   //寻找到开始反转的节点
            pre=head;
            head=head->next;
        }
        
        ListNode *temp=head;
        for(int i=m;i<n;i++){     //将后面的点插入到前面，这部分感觉写得略繁琐，但一下子没想出更简洁的写法。。。
            temp=pre->next;
            pre->next=head->next;
            head->next=head->next->next;
            pre->next->next=temp;
        }
        
        return vhead->next;
    }
};
