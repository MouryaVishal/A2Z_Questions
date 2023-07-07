//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int left=l;
        int right=m+1;
        vector<int> temp;
        while(left<=m && right<=r){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=m){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=r){
            temp.push_back(arr[right]);
            right++;
        }
        // cout<<left<<" "<<right<<endl;
        for(int i=l;i<=r;i++){
            // cout<<temp[i-l]<<" ";
            arr[i]=temp[i-l];
        }
        // cout<<endl;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(r<=l)return;
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
        //code here
    }
};



//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends