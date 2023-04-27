#include<bits/stdc++.h>
using namespace std;

#define fr(i,num) for(int i=0;i<num;i++)

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int>ans;
        int i=0;
        int j=0;
        while(i<n && j<m){
            // cout<<i<<" "<<j<<endl;
            if(arr1[i]<=arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }else{
                // cout<<i<<" "<<arr2[j]<<endl;
                ans.push_back(arr2[j]);
                j++;
            }
            while(i<n){
                if(ans.back()==arr1[i]){
                    i++;
                }else{
                    break;
                }
            }
            while(j<m){
                if(ans.back()==arr2[j]){
                    j++;
                }else{
                    break;
                }
            }
        }
        
        while(i<n){
            if(ans.back()!=arr1[i]){
                ans.push_back(arr1[i]);
            }
            i++;
        }
        while(j<m){
            if(ans.back()!=arr2[j]){
                ans.push_back(arr2[j]);
            }
            j++;
        }
        return ans;
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