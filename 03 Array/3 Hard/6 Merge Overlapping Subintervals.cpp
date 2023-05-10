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

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int,int> mp;
        for(auto &a:intervals ){
            mp[a[0]]--;
            mp[a[1]]++;
        }
        vector<vector<int>> ans;
        int s=0;
        int a,b;
        bool f=1;
        for(auto &ele:mp){
            // cout<<ele.first<<" "<<ele.second<<endl;
            if(s==0 && f){
                a=ele.first;
                f=0;
            }
            s+=ele.second;
            if(s==0 && !f){
                b=ele.first;
                f=1;
                ans.push_back({a,b});
            }
        }
        return ans;
    }
};



#define fr(i,num) for(int i=0;i<num;i++)
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