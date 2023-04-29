#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p;
        vector<int> m;
        for(auto&a:nums){
            if(a>0){
                p.push_back(a);
            }else{
                m.push_back(a);
            }
        }
        int k=0,j(0);
        for(int i=0;i<nums.size();i++){
            if(i%2){
                nums[i]=m[j++];
            }else{
                nums[i]=p[k++];
            }
        }
        return nums;
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