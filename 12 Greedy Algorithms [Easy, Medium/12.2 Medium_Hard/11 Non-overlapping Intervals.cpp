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
    int eraseOverlapIntervals(vector<vector<int>>& i) {
        if(i.size()<=1)return 0;
        sort(i.begin(),i.end());
        int ans=0;
        int st=0;
        int end=1;
        while(end<i.size()){
            if(i[st][1]<=i[end][0]){
                st=end;
                end++;
            }else if(i[st][1]<=i[end][1]){
                // Partial Overlapping
                ans++;
                end++;
            }else if(i[st][1]>i[end][1]){
                // smaller interval is completly overlap  with larger one
                ans++;
                st=end;
                end++;
            }
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