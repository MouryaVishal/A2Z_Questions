#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)
  int searchInSorted(int arr[], int n, int K) 
    { 
        int st=0;
        int end=n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(arr[mid]==K)return 1;
            if(arr[mid]<K){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
       return -1;
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