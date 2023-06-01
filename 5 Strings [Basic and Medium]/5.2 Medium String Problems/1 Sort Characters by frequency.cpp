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
};
#define fr(i,num) for(int i=0;i<num;i++)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto&a:s){
            mp[a]++;
        }
        vector<pair<int,char>> vec;
        for(auto&a:mp){
            vec.push_back({a.second,a.first});
        }
        sort(begin(vec),end(vec),greater<pair<int,char>>());
        string ans="";
        for(auto&a:vec)
        {
            int val=a.first;
            while(val--){
                ans+=a.second;             
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