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
public:
    bool check(vector<int>& nums) {
        for(int i=0, k=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%nums.size()] && ++k>1)
                return false;
        }
        return true;
    }
};


// 

class Solution {
public:
    bool check(vector<int>& nums) {
        int x=1;
        int n=nums.size();
        while(x<n){
            if(nums[x-1]<=nums[x]){
                x++;
            }else{
                break;
            }
        }
        if(x==n)return 1;
        x++;
        while(x<n){
            if(nums[x-1]<=nums[x]){
                x++;
            }else{
                return false;
            }
        }
        if(x==n){
            if(nums[0]>=nums[n-1]) return true;
        }
        cout<<3<<endl;

        return false;
    }
};