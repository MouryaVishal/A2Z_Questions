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

class Solution {
public:
    void func(int i,vector<int>&arr,vector<int>temp,vector<vector<int>>&ans,int tr){
        if(tr==0){
            ans.push_back(temp);
            return;
        }
        if(i==arr.size())return;
        func(i+1,arr,temp,ans,tr);
        if(arr[i]<=tr){
            temp.push_back(arr[i]);
            func(i,arr,temp,ans,tr-arr[i]);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tr) {
        vector<int> temp;
        vector<vector<int>> ans;
        func(0,arr,temp,ans,tr);
        return ans;
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