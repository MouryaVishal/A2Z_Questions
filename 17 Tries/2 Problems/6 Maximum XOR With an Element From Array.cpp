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

struct Node{
    Node* links[2];

    bool containKey(int bit){
        return (links[bit]!=NULL);
    }
    void put(int bit,Node*node){
        links[bit]=node;
    }
    Node*getRef(int bit){
        return links[bit];
    }
};

class Trie{
    public:
    Node*root;
    Trie(){
        root=new Node();
    }

    void insert(int num){
        Node*node=root;
        for(int i=31;i>=0;i--){
            int bit=((num>>i)&1);
            if(!node->containKey(bit)){
                node->put(bit,new Node());
            }
            node=node->getRef(bit);
        }
    }
    
    int getValue(int x){
        Node*node=root;
        int curr=0;
        for(int i=31;i>=0;i--){
            int bit=((x>>i)&1);
            if(node->containKey(1-bit)){
                curr=(curr|(1<<i));
                node=node->getRef(!bit);
            }else
                node=node->getRef(bit);
        }

        return curr;
    }


};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        Trie obj;
        sort(nums.begin(),nums.end());

        vector< pair<int, pair<int,int> > > vec;
        for(int i=0;i<q.size();i++){
            vec.push_back({q[i][1],{q[i][0],i}});
        }
        vector<int> ans(q.size(),-1);
        sort(vec.begin(),vec.end());

        int j=0;
        for(auto a:vec){
            int ind=a.second.second;
            int x=a.second.first;
            int lessEle=a.first;
            while(j<nums.size() && nums[j]<=lessEle){
                // cout<<"sdS"<<endl;
                obj.insert(nums[j]);
                j++;
            }
            int temp=-1;
            if(j!=0)
                temp=obj.getValue(x);
            ans[ind]=(temp);
        }

        return ans;
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