#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]==nums.size()){
                i++;
                continue;
            }
            if(nums[i]!=i){
                swap(nums[i],nums[nums[i]]);
            }else{
                i++;
            }
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i)return i;
        }

        return nums.size();
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