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
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        int start,arrS,arrE;
        for(int i=0;i<nums.size();i++){
            if(sum==0)start=i;
            sum+=nums[i];
            if(sum>maxi){
                maxi=sum;
                arrS=start;
                arrE=i;
            }
            if(sum<0){
                sum=0;
            }
        }
        cout<<arrS<<" "<<arrE<<endl;
        return maxi;
    }
};