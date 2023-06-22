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

class Solution {
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    bool dfs(int i,int j,int k,vector<vector<char>>& b, string w){
        if(k==w.size()){
            return true;
        }
        if(i<0 || j<0 || j>=b[0].size() || i>=b.size() || b[i][j]!=w[k])return  false;
        char node=b[i][j];
        b[i][j]=' ';
        bool flag=false;
        for(int x=0;x<4;x++){
            int nx=i+dx[x];
            int ny=j+dy[x];
            flag=flag||dfs(nx,ny,k+1,b,w);
            if(flag)return true;
        }
        b[i][j]=node;
        return flag;
    }
public:
    bool exist(vector<vector<char>>& b, string w) {
        int n=b.size();
        int m=b[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]==w[0] && dfs(i,j,0,b,w)){
                    return true;
                }
            }
        }

        return false;
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