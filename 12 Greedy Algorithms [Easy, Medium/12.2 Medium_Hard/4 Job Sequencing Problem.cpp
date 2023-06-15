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
  struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
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
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int t=0;
        sort(arr,arr+n,[&](Job&a1,Job&a2){
            t=max(t,a1.dead);
            t=max(t,a2.dead);
            if(a1.profit==a2.profit)return a1.dead>a2.dead;
            return a1.profit>a2.profit; 
        });
        int ans=0;
        int count=0;
        // cout<<t<<endl;
        vector<int> vis(t+1,0);
        for(int i=0;i<n;i++){
            int tm=arr[i].dead;
            while(tm>=1 && vis[tm]){
                tm--;
            }
            if(tm>=1){
                ans+=arr[i].profit;
                count++;
                vis[tm]=true;
            }
        }
        return {count,ans};
        // your code here
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