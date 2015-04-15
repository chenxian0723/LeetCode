/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree2(vector<int> &inorder,int b1,int e1,vector<int> &postorder,int b2,int e2) {
        if(b1>e1)
            return NULL;
        int rval=postorder[e2];     //后序最后一个节点为根节点
        TreeNode *root=new TreeNode(rval);
        if(b1!=e1){
            int pos=b1;
            while(inorder[pos]!=rval)       //找到根节点在中序的位置
                pos++;      
            root->left=buildTree2(inorder,b1,pos-1,postorder,b2,pos-b1+b2-1);     //中序中根节点左边的为左子树
            root->right=buildTree2(inorder,pos+1,e1,postorder,pos-b1+b2,e2-1);    //中序中根节点右边的为右子树
            //找准左右子树在中序和后序中的位置，递归建立树
        }
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size=inorder.size();
        if(size!=0)
            return buildTree2(inorder,0,size-1,postorder,0,size-1);
        else
            return NULL;
    }
};
