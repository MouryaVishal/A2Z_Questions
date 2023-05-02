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
    int longestConsecutive_NlogN(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(begin(nums),end(nums));
        int maxi=1;
        int curr=1;

        for(int i=1;i<nums.size();i++){
            // cout<<nums[i]<<" ";
            if(nums[i]==nums[i-1])continue;
            if(nums[i]==nums[i-1]+1){
                curr++;
            }else{
                maxi=max(maxi,curr);
                curr=1;
            }
        }

        return max(maxi,curr);;
    }


     int longestConsecutive_N(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &a:nums){
            st.insert(a);
        }
        int maxi=0;
        for(auto &a:nums){
            if(!st.count(a-1)){
                int start=a;
                int count=1;
                while(st.count(a+1)){
                    count++;
                    a++;
                }
                maxi=max(maxi,count);
            }
        }

        return maxi;
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