#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int maxi=0;
        int curr=p[0];
        for(int i=0;i<p.size();i++){
            maxi=max(maxi,p[i]-curr);
            curr=min(curr,p[i]);
        }
        return maxi;
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