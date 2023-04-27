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
    bool possible(int c,vector<int>&n){
        int count=0;
        for(auto&a:n){
            if(a==c)count++;
        }

        return count>n.size()/2;
    }
    int check(vector<int>&nums){
        int ele;
        int c=0;
        for(auto &a:nums){
            if(c==0){
                c++;
                ele=a;
            }else if(ele==a) c++;
            else c--;
        }
        return ele;
    }
public:
    int majorityElement(vector<int>& nums) {
        int condidate=check(nums);
        if(possible(condidate,nums)){
            return condidate;
        }
        return -1;
    }
};