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

class KthLargest {
    int kth=0;
    priority_queue<int,vector<int>,greater<int>> q;
public:
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        int i=0;
        for(;i<nums.size() && k>0;i++){
            q.push(nums[i]);
            k--;
        }
        cout<<i<<" "<<q.size()<<endl;
        for(;i<nums.size();i++){
            if(q.top()<nums[i]){
                q.pop();
                q.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(q.empty() || q.size()<kth){
            q.push(val);
        }else if(q.top()<val){
            q.pop();
            q.push(val);
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */



int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    // Solution obj;
}