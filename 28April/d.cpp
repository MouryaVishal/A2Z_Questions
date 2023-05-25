#include<bits/stdc++.h>

#define int               long long
#define mod               1000000007
#define inf               1e18
#define pq                priority_queue
#define pqi               priority_queue<int>
#define pb                push_back
#define sz(v)             ((int)(v).size())
#define all(v)            (v).begin(),(v).end()
#define ss                second
#define ff                first
#define fr(i,num)         for(int i=0;i<num;i++)
 
using namespace std;
using ld = long double;


int32_t main(){
    int _testCase;
    cin>>_testCase;
    while(_testCase--){
        int _num;
        cin>>_num;
        string _str;
        cin>>_str;
        int ans=-1;
        int i=0;
        while(i<_num){
            int curr=1;
            char ch=_str[i];
            i++;
            while(i<_num && _str[i]==ch){
                i++;
                curr++;
            }
            ans=max(ans,curr);
        }

        cout<<ans+1<<endl;
        
    }
  return 0;
}