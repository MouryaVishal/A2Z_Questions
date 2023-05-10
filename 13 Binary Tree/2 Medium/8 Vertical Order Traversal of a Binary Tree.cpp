#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct Node{
   int data;
   Node* left, * right;
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            mp[t.second.first][t.second.second].insert(t.first->val);
            if(t.first->left) q.push({t.first->left,{t.second.first-1,t.second.second+1}});
            if(t.first->right) q.push({t.first->right,{t.second.first+1,t.second.second+1}});
        }

        for(auto&a:mp){
            vector<int> temp;
            for(auto&b:a.second){
                temp.insert(temp.end(),b.second.begin(),b.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};




class Solution_Accepted_as_We_have_sortElement_at_EachLevel {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mp;
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            mp[t.second].push_back(t.first->val);
            if(t.first->left) q.push({t.first->left,t.second-1});
            if(t.first->right) q.push({t.first->right,t.second+1});
        }

        for(auto&a:mp){
            sort(begin(a.second),end(a.second));
            ans.push_back(a.second);
        }
        return ans;
    }
};




#define fr(i,num) for(int i=0;i<num;i++)
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
