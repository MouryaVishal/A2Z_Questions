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
        vector<int> vec;
        fr(i,_num){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        int small=2;
        vector<int> vis(_num+1,0);
        vector<int>ans;
        ans.push_back(1);
        vis[1]=1;
        for(int i=1;i<_num;i++){
            int prev=vec[i-1]+ans[i-1];
            int rev=prev-vec[i];
            if(rev<=small){
                ans.push_back(small++);
            }else{
                if(!vis[rev])ans.push_back(rev);
                else {
                    while(rev<_num+1 && vis[rev]==1){
                        rev++;
                    }
                    ans.push_back(rev);
                    vis[rev]=1;
                }
            }
        }

        for(int i=0;i<_num;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
    }
  return 0;
}