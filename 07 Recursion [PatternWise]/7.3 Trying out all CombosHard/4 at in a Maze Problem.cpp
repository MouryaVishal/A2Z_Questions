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
#define fr(i,num) for(int i=0;i<num;i++)


// !Solution 
class Solution{
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    void solRecDfs(int i,int j,vector<string>&ans,string temp,vector<vector<int>>&m,unordered_map<string,string> &mp){
        if(i<0 || j<0 || j>=m.size() || i>=m.size() || m[i][j]==0){
            return;
        }
        if(i==m.size()-1 && j==m.size()-1){
            ans.push_back(temp);
            return;
        }
        m[i][j]=0;
        for(int k=0;k<4;k++){
            string t=to_string(dx[k])+"+"+to_string(dy[k]);
            solRecDfs(i+dx[k],j+dy[k],ans,temp+mp[t],m,mp);
        }
        m[i][j]=1;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        unordered_map<string,string> mp;
        mp[to_string(0)+"+"+to_string(-1)]="L";
        mp[to_string(0)+"+"+to_string(1)]="R";
        mp[to_string(-1)+"+"+to_string(0)]="U";
        mp[to_string(1)+"+"+to_string(0)]="D";
        solRecDfs(0,0,ans,"",m,mp);
        return ans;
    }
};
// !Solution 
int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
}