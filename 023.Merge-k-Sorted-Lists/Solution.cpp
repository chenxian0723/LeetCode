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
    struct myComp{              //定义比较函数
        bool operator()(ListNode* l1,ListNode* l2){
            return l1->val > l2->val;
        }
    };
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*,vector<ListNode*>,myComp> heap;      //优先队列做为最大堆，使用自定义比较函数
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)        
                heap.push(lists[i]);      //堆里的每个节点都是各链表的首节点
        }

        ListNode* vhead=new ListNode(0);
        ListNode* pre=vhead;
        while(!heap.empty()){
            ListNode* temp=heap.top();    //堆的自排序，保证每次出堆的都是最大值
            heap.pop();
            pre->next=temp;
            pre=temp;
            temp=temp->next;
            if(temp)
                heap.push(temp);        //把下一个节点做为首节点加入堆中
        }
        return vhead->next;
    }
};
