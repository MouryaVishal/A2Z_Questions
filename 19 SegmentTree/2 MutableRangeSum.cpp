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
    vector<int> arr;
    vector<int> seg;
    int t;
   
public:
    NumArray(vector<int>& nums) {
        t=nums.size();
        for(int i=0;i<t;i++){
            arr.push_back(nums[i]);
        }
        seg.resize(4*t+1);
        buildSeg(0,0,t-1);
    }
    void buildSeg(int ind,int low,int high){
        if(low==high){
            seg[ind]=arr[low];
            return;
        }
        int mid=low+(high-low)/2;
        buildSeg(2*ind+1,low,mid);
        buildSeg(2*ind+2,mid+1,high);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    void updateSegWithNewVal(int ind,int low,int high,int index,int val){
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid=low+(high-low)/2;
        if(index<=mid && index>=low){
            updateSegWithNewVal(2*ind+1,low,mid,index,val);
        }else{
            updateSegWithNewVal(2*ind+2,mid+1,high,index,val);
        }
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    };

    int ansQuery(int ind,int low,int high,int l,int r){
        if(high<l || low>r){
            return 0;
        }
        if(low>=l && high<=r){
            return seg[ind];
        }
        int mid=low+(high-low)/2;
        return ansQuery(2*ind+1,low,mid,l,r)+ansQuery(2*ind+2,mid+1,high,l,r);
    }
    
    void update(int index, int val) {
        updateSegWithNewVal(0,0,t-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return ansQuery(0,0,t-1,left,right);
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