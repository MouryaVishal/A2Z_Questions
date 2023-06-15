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
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        if(inter.size()==1)return inter;
        sort(inter.begin(),inter.end());
        int j=1;
        vector<vector<int>> ans;

        int st=inter[0][0];
        int end=inter[0][1];
        while(j<inter.size()){
            if(end>=inter[j][0]){
                if(end<inter[j][1])
                    end=inter[j][1];
                j++;
            }else{
                ans.push_back({st,end});
                st=inter[j][0];
                end=inter[j][1];
                j++;
            }
        }
        ans.push_back({st,end});
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