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
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double wt=(double) W;
        priority_queue<pair<double,pair<double,double>>> q;
        for(int i=0;i<n;i++){
            q.push({arr[i].value*1.0/arr[i].weight*1.0,{arr[i].value*1.0,arr[i].weight*1.0}});
        }
        
        double ans=0.0;
        while(!q.empty()){
            auto a=q.top();
            q.pop();
            if(wt>=a.second.second){
                ans+=a.second.first;
                wt-=a.second.second;
            }else{
                ans+=a.second.first*wt/a.second.second;
                wt=0;
            }
            if(wt==0)break;
        }
        
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