#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* pt = root;
        stack<TreeNode*> st;
        vector<int> ret;

        while( pt != 0 || !st.empty()){
            while(pt!=0){
                st.push(pt);
                pt = pt->left;
            }

            if(!st.empty()){
                pt = st.top(); st.pop();
                ret.push_back(pt->val);
                pt = pt->right;    
            }
        }

        return ret;
    }
};

int main(){

}