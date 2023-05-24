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
        if(_num%2){
            cout<<-1<<endl;
        }else{
            int oo=_num-1;
            int ee=_num;
            for(int i=0;i<_num;i++){
                if(i%2==0){
                    cout<<ee<<" ";
                    ee-=2;
                }else{
                    cout<<oo<<" ";
                    oo-=2;
                }
            }
            cout<<endl;
        }
        
    }
  return 0;
}