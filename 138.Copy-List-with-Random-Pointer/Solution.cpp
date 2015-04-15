/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *vhead=new RandomListNode(0);
        RandomListNode *pre=vhead;
        unordered_map<RandomListNode *,RandomListNode *> rm;      //使用哈希表记录节点间的一一对应情况
        while(head){
            RandomListNode *temp=new RandomListNode(head->label);
            rm[head]=temp;
            temp->random=head->random;          //先把两个链表的random指针都指向原链表
            pre->next=temp;
            head=head->next;
            pre=pre->next;
        }
        head=vhead->next;
        while(head){
            head->random=rm[head->random];      //一一修改新链表的random指针
            head=head->next;
        }
        return vhead->next;
    }
};
