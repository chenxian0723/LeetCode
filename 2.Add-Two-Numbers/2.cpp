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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *result=l1,*pre;
        int carry=0;                        //carry记录进位，开始考虑用bool，后来发现用int型能直接做加法，更加方便
        
        while(l1&&l2){
            int temp=l1->val+l2->val+carry;
            l1->val=temp%10;                //直接修改l1的值，避免了新建链表
            carry=temp/10;
            pre=l1;
            l1=l1->next;
            l2=l2->next;
        }
        
        if(l2)                              //如果l2还有剩余的话，将l2剩余部分链接到l1后面
            pre->next=l2;
            
        while(pre->next&&carry==1){         //处理较长链表的剩余部分，当不满足进位条件时可以提前结束循环
            pre=pre->next;
            int temp=pre->val+carry;
            pre->val=temp%10;
            carry=temp/10;
        }
        
        if(carry==1){                       //处理最后一个数产生的进位
            ListNode *tnode=new ListNode(1);
            pre->next=tnode;
        }
        
        return result;
    }
};
