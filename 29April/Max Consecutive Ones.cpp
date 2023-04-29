#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                curr++;
            }else{
                maxi=max(maxi,curr);
                curr=0;
            }
        }
        return max(maxi,curr);
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