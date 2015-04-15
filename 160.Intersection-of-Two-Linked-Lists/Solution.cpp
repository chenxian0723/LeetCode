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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode *temp=headA;
        while(temp!=NULL){
            l1++;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=NULL){
            l2++;
            temp=temp->next;
        }
        if(l1>l2)       //链表相交后，后面都是重叠的，因此长度差就是不相交部分的长度差
            for(int i=0;i<l1-l2;i++)
                headA=headA->next;
        else
            for(int i=0;i<l2-l1;i++)
                headB=headB->next;
        while(headA!=headB){      //第一个相同的点即为相交点
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
