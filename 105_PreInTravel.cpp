#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root=0;
        rebuild(0,0,preorder.size(),preorder,inorder,root);

        return root;
    }

    void preTravel(TreeNode *root){
        if(root != 0){
            cout<<root->val<<" ";
            if(root->left == 0)
                cout<<"#"<<" ";
            else preTravel(root->left);
            if(root->right == 0) cout<<"#"<<" ";
            else 
            preTravel(root->right);
        }
    }

    void rebuild(int pre,int in,int treeLen,vector<int>& preorder,vector<int>& inorder,TreeNode*& root){
        if(preorder.size() == 0 || inorder.size() == 0) return;

        if(root == 0) root = new TreeNode(preorder[pre]);
        if(treeLen == 1) return;

        int inStart = in;
        int inBound = in;

        int tmpCnt=0;

        //warning:should to check the treelen is overflow
        //should to check the tree is not null
        while(inorder[inStart] != preorder[pre]){
            if( inorder.size() != 0 || preorder.size() != 0)
             tmpCnt++;
            if(tmpCnt > treeLen) break;
            inStart++;
        }

        int leftTreeLen = inStart - inBound;
        int rightTreeLen = treeLen - leftTreeLen  - 1;
        // cout<<root->val<<" "<<leftTreeLen<<" "<<rightTreeLen<<endl;
        if(leftTreeLen > 0)
            rebuild(pre+1,in,leftTreeLen,preorder,inorder,root->left);
        if(rightTreeLen > 0)
            rebuild(pre+leftTreeLen+1,in+leftTreeLen+1,rightTreeLen,preorder,inorder,root->right);
    }
};

int main(){
//     [7,-10,-4,3,-1,2,-8,11], [-4,-10,3,-1,7,11,-8,2]
// Output: {7,-10,2,-4,3,#,-8,#,#,#,-1,#,11}
// Expected:   {7,-10,2,-4,3,-8,#,#,#,#,-1,11}

    Solution s;
    vector<int> pre,in;
    pre.push_back(7);pre.push_back(-10);pre.push_back(-4);pre.push_back(3);pre.push_back(-1);pre.push_back(2);pre.push_back(-8),pre.push_back(11);
    in.push_back(-4);in.push_back(-10);in.push_back(3);in.push_back(-1);in.push_back(7);in.push_back(11);in.push_back(-8),in.push_back(2);

    TreeNode *root = s.buildTree(pre,in);
    s.preTravel(root);

    return 0;
}