#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        if(root==NULL)return ans;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            long long s=q.size();
            long long st=0,end=0;
            long long tempval=q.front().second;
            for(long long i=0;i<s;i++){
                auto a=q.front();
                q.pop();
                if(i==0){
                    st=a.second;
                }
                if(i==s-1){
                    end=a.second;
                }
                if(a.first->left)q.push({a.first->left,(a.second-tempval)*2+1});
                if(a.first->right)q.push({a.first->right,(a.second-tempval)*2+2});
            }
            ans=max(ans,end-st+1);
        }
        return (int)ans;
    }
};



int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
}