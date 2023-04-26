#include<bits/stdc++.h>
using namespace std;

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
class Solution {
    pair<int,int> candi(vector<int>&num){
        int n1=-1e9-1,n2=-1e9-1,c1(0),c2(0);
        for(auto &a:num){
            if(a==n1)c1++;
            else if(a==n2)c2++;
            else if(c1==0)n1=a,c1=1;
            else if(c2==0)n2=a,c2=1;
            else c1--,c2--;
        }
        return {n1,n2};
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        pair<int,int> p=candi(nums);
        int c1(0),c2(0);
        for(auto&a:nums){
            if(a==p.first)c1++;
            if(a==p.second)c2++;
        }
        vector<int> ans;
        if(c1>nums.size()/3)ans.push_back(p.first);
        if(c2>nums.size()/3)ans.push_back(p.second);
        return ans;
    }
};