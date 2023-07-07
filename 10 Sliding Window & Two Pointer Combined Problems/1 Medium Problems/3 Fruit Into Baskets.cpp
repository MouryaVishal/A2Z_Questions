//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int n, vector<int> &f) {
        unordered_map<int,int> mp;
        int j=0;
        int i=0;
        int ans=0;
        while(j<n){
            mp[f[j]]++;
            if(mp.size()>2){
                while(mp.size()>2){
                    mp[f[i]]--;
                    if(mp[f[i]]==0){
                        mp.erase(f[i]);
                    }
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends