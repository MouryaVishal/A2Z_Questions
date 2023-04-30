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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(begin(nums),end(nums));
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int s=i+1,t=n-1;
            while(s<t){
                long long sum=(long long )nums[i]+(long long )nums[s]+(long long )nums[t];
                if(sum==0){
                    ans.push_back({nums[i],nums[s],nums[t]});
                    int se=nums[s];
                    int lt=nums[t];
                    while(s<t && se==nums[s])s++;
                    while(s<t && lt==nums[t]) t--;
                }else if(sum>0){
                    t--;
                }else{
                    s++;
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