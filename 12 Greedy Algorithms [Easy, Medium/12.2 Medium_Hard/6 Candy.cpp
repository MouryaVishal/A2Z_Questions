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
    int candy(vector<int>& r) {
        int len=r.size();
        vector<int> LtoR(len,1);
        vector<int> RtoL(len,1);
       
        for(int i=1;i<len;i++){
            if(r[i]>r[i-1]) LtoR[i]=LtoR[i-1]+1;
        }
        for(int i=len-2;i>=0;i--){
            if(r[i]>r[i+1]) RtoL[i]=RtoL[i+1]+1;
        }
        
        int total=0;
        for(int i=0;i<len;i++){
            total+=max(RtoL[i],LtoR[i]);
        }
        
        return total;
    }
};

class Solution {
public:
    int candy(vector<int>& r) {
        int len=r.size();
        // if(len==0)return 1;
        vector<int> ans(len,1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=0;i<len;i++){
            q.push({r[i],i});
        }
        while(!q.empty()){
            auto a=q.top();
            q.pop();
            int i=a.second;
            if(i==0 && i+1<len){
                if(r[i]>r[i+1]){
                    ans[i]=ans[i+1]+1;
                }
            }else if(i==len-1 && i-1>=0){
                if(r[i]>r[i-1]){
                    ans[i]=ans[i-1]+1;
                }
            }else if(i-1>=0 && i+1<len){
                if(r[i]>r[i-1] && r[i]>r[i+1]){
                    ans[i]=(max(ans[i-1],ans[i+1])+1);
                }else if(r[i]>r[i-1]){
                    ans[i]=ans[i-1]+1;
                }else if(r[i]>r[i+1]){
                    ans[i]=ans[i+1]+1;
                }
            }
        }
        int sum=accumulate(ans.begin(),ans.end(),0);
        return sum;
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