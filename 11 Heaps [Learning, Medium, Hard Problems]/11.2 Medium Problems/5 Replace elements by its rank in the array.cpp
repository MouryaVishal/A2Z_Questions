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
    Node* prev;
    int data;
    Node* next;
    Node()
    { 
    prev = NULL;
    data = 0;
    next = NULL;
    }
    
    Node(int value)
    {
    prev = NULL;
    data = value;
    next = NULL;
    }
  };
struct ListNode {
  int val;
  ListNode *next;
   ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> ans(n);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            q.push({arr[i],i});
        }
        int rank=1;
        while(!q.empty()){
            auto a=q.top();
            q.pop();
            if(mp.find(a.first)!=mp.end()){
                ans[a.second]=mp[a.first];
                continue;
            }
            ans[a.second]=rank;
            mp[a.first]=rank++;
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