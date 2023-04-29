#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=nums[0];
        for(int i=1;i<nums.size();i++){
            x^=nums[i];
        }
        return x;
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