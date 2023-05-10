#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct Node{
   int data;
   Node* left, * right;
};
#define fr(i,num) for(int i=0;i<num;i++)


class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    #define ll long long
    
    ll merge(ll st,ll mid,ll end, ll arr[]){
        ll n=end-st+1;
        vector<ll> temp(n);
        ll i=st,j=mid+1;
        ll k=0;
        ll ans=0;
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }else{
                ans+=(ll)(mid-i+1);
                temp[k++]=arr[j++];
            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=end){
            temp[k++]=arr[j++];
        }
        for(ll i=0;i<n;i++){
            arr[st+i]=temp[i];
        }
        return ans;
    }
    ll mergeSort(ll i,ll j,ll arr[]){
        if(i<j){
            ll mid=i+(j-i)/2;
            ll a1=mergeSort(i,mid,arr);
            ll a2=mergeSort(mid+1,j,arr);
            ll a3=merge(i,mid,j,arr);
            return a1+a2+a3;
        }
        return 0;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        return mergeSort(0,n-1,arr);
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