/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
            return;
        if(root->left){   //若不是叶子节点
            root->left->next=root->right;
            if(root->next)    //右子树的next分两种情况
                root->right->next=root->next->left;   
            else
                root->right->next=NULL;
        }
        connect(root->right);
        connect(root->left);
    }
};
