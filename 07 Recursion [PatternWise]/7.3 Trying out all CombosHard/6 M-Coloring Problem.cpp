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
public:
    bool possible(int c,int node,unordered_map<int,vector<int>> &mp,vector<int>&col){
        for(auto a:mp[node]){
            if(c==col[a])return false;
        }
        return true;
    }
    bool dfs(int node,int cnt,int m,unordered_map<int,vector<int>>&mp,vector<int>&col){
        if(node==col.size())return true;
        for(int c=0;c<m;c++){
            if(possible(c,node,mp,col)){
                col[node]=c;
                bool temp=dfs(node+1,cnt+1,m,mp,col);
                if(temp)return true;
                col[node]=-1;
            }
        }
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][j]){
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        
        vector<int> col(n,-1);
        return dfs(0,0,m,mp,col);
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