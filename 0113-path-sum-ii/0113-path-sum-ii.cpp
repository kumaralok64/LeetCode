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
void solve(TreeNode* root, vector<vector<int>>& ans, vector<int>v,int sum,int targetSum) {
        if (root == NULL) {
           
            return;

        }
        v.push_back(root->val);
        sum+=root->val;
    if(root->left==NULL && root->right==NULL && sum==targetSum)ans.push_back(v);
        solve(root->left, ans, v,sum,targetSum);
        solve(root->right, ans, v,sum,targetSum);
        sum-=root->val;
        v.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        vector<vector<int>>res;
        if(root==NULL)return {};
        int sum=0;
         solve(root, ans, v,sum,targetSum);
       return ans;
    }
};