// w/space
class Solution {
public:
    void solve(TreeNode* root,vector<int>&ans){
        if(root==NULL) return;
        // inorder left,mid,right
        if(root->left) solve(root->left,ans);
        ans.push_back(root->val);
        if(root->right) solve(root->right,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        vector<int>ans;
        solve(root,ans);
        return ans[k-1];
    }
};

//w/0 space
class Solution {
public:
    void solve(TreeNode* root, int k,int &ans,int &cnt){
        if(!root)return;
        solve(root->left,k,ans,cnt);
        cnt++;
        if(cnt==k){
            ans=root->val;
            return;
        }
        solve(root->right,k,ans,cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int cnt=0;
        solve(root,k,ans,cnt);
        return ans;
    }
};
