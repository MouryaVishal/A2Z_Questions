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
        int _num,_valk;
        cin>>_num>>_valk;
        if(_num<2*_valk){
            cout<<"NO"<<endl;
        }else{
            // cout<<"fs"<<endl;
            int temp=_num/2+(_num%2?1:0);
            int ee=_num/2;

            // cout<<temp<<endl;
            temp=temp-_valk;
            int val=temp%2;
            // cout<<val<<endl;
            if(val){
                cout<<"NO"<<endl;
            }else{
                cout<<"YES"<<endl;
            }

        }
        
    }
  return 0;
}