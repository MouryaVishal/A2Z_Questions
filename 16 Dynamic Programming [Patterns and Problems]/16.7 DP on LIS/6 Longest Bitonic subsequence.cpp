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
    void lis(vector<int>&nums,vector<int>&ans){
        for(int i=0;i<nums.size();i++){
            for(int pr=0;pr<i;pr++){
                if(nums[pr]<nums[i]){
                    ans[i]=max(ans[i],ans[pr]+1);
                }
            }
        }
    }
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    vector<int> back(nums.size(),1);
	    vector<int> front(nums.size(),1);
	    lis(nums,front);
	    reverse(nums.begin(),nums.end());
	    lis(nums,back);
	    reverse(back.begin(),back.end());
	    int ans=0;
	    for(int i=0;i<nums.size();i++){
	       // cout<<front[i]<<" "<<back[i]<<endl;
	        ans=max(ans,back[i]+front[i]-1);
	    }
	   // cout<<endl;
	    return ans;
	    // code here
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