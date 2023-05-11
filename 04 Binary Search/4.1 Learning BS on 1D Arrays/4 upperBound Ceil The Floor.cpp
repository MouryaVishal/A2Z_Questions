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
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int fl=-1;
    int ce=1e6;
    for(int i=0;i<n;i++){
        if(arr[i]>fl && arr[i]<=x){
            fl=arr[i];
        }
        if(arr[i]<ce && arr[i]>=x){
            ce=arr[i];
        }
    }
    
    return {fl,ce==1e6?-1:ce};
}

pair<int, int> getFloorAndCeil2(int arr[], int n, int x) {
    sort(arr,arr+n);
    int st=0;
    int end=n-1;
    int fl=-1;
    int ce=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(x==arr[mid]) return {x,x};
        if(x<arr[mid]){
            end=mid-1;
            ce=mid;
        }else{
            st=mid+1;
            fl=mid;
        }
    }
    if(fl!=-1)fl=arr[fl];
    if(ce!=-1)ce=arr[ce];
    return {fl,ce};
    
    
}

#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
}