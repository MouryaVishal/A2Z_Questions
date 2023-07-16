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
class NumArray {
    int arr[10004];
    int seg[4*10004];
    int t;
    void buildSeg(int ind,int l,int r){
        if(l==r){
            seg[ind]=arr[l];
            return;
        }
        int mid=(r+l)/2;
        buildSeg(2*ind+1,l,mid);
        buildSeg(2*ind+2,mid+1,r);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    int queryAns(int ind,int low,int high,int l,int r){
        if(low>r || l>high)return 0;
        if(low>=l && high<=r){
            return seg[ind];
        }
        int mid=(high+low)/2;
        return queryAns(2*ind+1,low,mid,l,r)+queryAns(2*ind+2,mid+1,high,l,r);
    }
public:
    NumArray(vector<int>& nums) {
        t=nums.size();
        for(int i=0;i<nums.size();i++){
            arr[i]=(nums[i]);
        }
        buildSeg(0,0,t-1);
    }
    
    int sumRange(int left, int right) {
        return queryAns(0,0,t-1,left,right);
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