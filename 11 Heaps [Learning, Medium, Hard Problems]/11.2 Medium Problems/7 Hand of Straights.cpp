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
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)
            return false;
        map<int,int> count;
        map<int,int>::iterator it;
        int freq;
        for(int &i:nums)
            count[i]++;
        for(it=count.begin();it!=count.end();it++)
            if(it->second)
            {
                freq=it->second;
                for(int i=0;i<k;i++)
                    if(count[it->first+i]<freq) 
                        return false;
                    else
                        count[it->first+i]-=freq;
            }
        return true;
    }
};

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int len=hand.size();
        if(len%g)return false;
        // if(g==1)return true;

        // sort(hand.begin(),hand.end());
        unordered_map<int,int> mp;
        for(auto&a:hand){
            mp[a]++;
        }

        for(auto&a:hand){
            if(mp.find(a)==mp.end())continue;
            int cnt=1;
            if(mp.find(a-1)!=mp.end()){
                int b=a-1;
                while(cnt<g && mp.find(b)!=mp.end()){
                    b--;
                    cnt++;
                }
            }
            if(cnt==g){
                while(cnt--){
                    mp[a]--;
                    if(mp[a]==0){
                        mp.erase(a);
                    }
                    a--;
                }
            }
        }


        return mp.size()==0;
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