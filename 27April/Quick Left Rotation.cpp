#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution{
	
	
	public:
	void leftRotate(int nums[], int k, int n) 
	{ 
	    k%=n;
        reverse(nums,nums+n);
        reverse(nums,nums+n-k);
        reverse(nums+n-k,nums+n);
	   // Your code goes here
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