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

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,int> mp;
        vector<int> ans;
        if(!root)return ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            if(mp.find(t.second)==mp.end())
                mp[t.second]=(t.first->data);
            if(t.first->left) q.push({t.first->left,t.second-1});
            if(t.first->right) q.push({t.first->right,t.second+1});
        }

        for(auto&a:mp){
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