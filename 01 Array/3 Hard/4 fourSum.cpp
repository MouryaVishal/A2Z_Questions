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
    vector<vector<int>> fourSum(vector<int>& nums, int tr) {
        sort(begin(nums),end(nums));
        vector<vector<int>> ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if( j>i+1 && nums[j]==nums[j-1])continue;
                int k=j+1,l=n-1;
                while(k<l){
                    long long  s=(long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l];
                    if(s==(long long)tr){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        int t=nums[k],f=nums[l];
                        while(k<l && t==nums[k]) k++;
                        while(k<l && f==nums[l])l--;
                    }else if(s>(long long)tr){
                        l--;
                    }else {
                        k++;
                    }
                }
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