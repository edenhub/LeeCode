#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(0),right(0) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        if(len == 0) return 0;
        if(len == 1) return new TreeNode(postorder[0]);

        vector<int>::iterator in_s = inorder.begin();
        vector<int>::iterator post_s = postorder.begin();
        in_end = inorder.end(); post_end = postorder.end();
        TreeNode *root;
        rebuild(in_s,post_s,len,root);
        return root;
    }

       void travel(TreeNode *root){
        if(root!=0){
            cout<<root->val<<" ";
            travel(root->left);
            travel(root->right);
        }else{
            cout<<"#"<<" ";
        }
    }

private:
    vector<int>::iterator in_end,post_end;
    
    void rebuild(vector<int>::iterator& in_s,vector<int>::iterator& post_s,int treeLen,TreeNode*& root){
        if(in_s == in_end || post_s == post_end) return;

        int val = *(post_s + treeLen -1);
        cout<<val<<endl;
        if(root == 0) root = new TreeNode(val);

        if(treeLen == 1) return;

        vector<int>::iterator flag = in_s;
        vector<int>::iterator tmp = in_s;
        int cnt=0;

        while((*flag) != val){
            if(in_s != in_end ||  post_s != post_end) cnt++;
            if(cnt > treeLen) break;
            flag++;
        }

        int leftLen = flag - tmp;
        int rightLen = treeLen - leftLen - 1;

        if(leftLen > 0)
            rebuild(in_s,post_s,leftLen,root->left);
        if(rightLen > 0){
              in_s = in_s+leftLen+1;
            post_s = post_s+leftLen;
            rebuild(in_s,post_s, rightLen ,root->right);
        }
    }

 
};



int main(){

    stringstream inStream("4,2,1,5,6,3"), postStream("4,2,6,5,3,1");
    vector<int> in,post;

    while(!inStream.eof()){
        int n; inStream>>n;
        char dot; inStream>>dot;
        in.push_back(n);
    }

    while(!postStream.eof()){
        int n; postStream>>n;
        char dot; postStream>>dot;
        post.push_back(n);
    }

    // vector<int>::iterator iter = in.begin();
    // while(iter != in.end()) cout<<*iter++<<" ";
    // cout<<endl;
    Solution s;

    TreeNode *root = s.buildTree(in,post);
    cout<<"tmp"<<endl;
    s.travel(root);


    return 0;
}