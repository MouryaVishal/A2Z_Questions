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
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        for(int i=0;i<bills.size();i++){
            int a=bills[i];
            int val=a-5;
            // cout<<i<<" "<<a<<endl;
            if(val==0){
                mp[a]++;
            }else if(val==5){
                if(mp[5]>0){
                    mp[5]--;
                }else{
                    return false;
                }
                mp[a]++;
            }else if(val==15){
                if(mp[5]>0 && mp[10]>0){
                    mp[5]--,mp[10]--;
                }else if(mp[5]>2){
                    mp[5]=mp[5]-3;
                }else{
                    return false;
                }
                mp[a]++;
            }
        }

        return true;
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