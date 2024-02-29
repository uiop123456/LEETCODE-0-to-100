/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>que;
        que.push(root);
        bool even_level=true;
        int prev;
        while(!que.empty()){
            int n=que.size();
            if(even_level){
                prev=INT_MIN;
            }else{
                prev=INT_MAX;
            }

            while(n--){
                TreeNode *node = que.front();
                que.pop();
                if(even_level){
                    //if even level then odd interger && node->val>prev
                    if(node->val%2!=1 || node->val<=prev) return false;
                }
                else{
                    //if odd level then even interger && node->val<prev
                    if(node->val%2!=0 || node->val>=prev) return false;
                } 

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

                prev=node->val;
            }
            even_level=!even_level;
        }
        return true;
    }
};
