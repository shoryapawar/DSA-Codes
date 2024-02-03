 //  Link  :- https://ideone.com/nqRtI6
#include <bits/stdc++.h>
using namespace std;

bool canweplace(vector<int> &stalls, int cows, int dis){
       int n = stalls.size();
        int noOfcows =1, lastcowPos = stalls[0]; // last cow position
        for(int i =1 ; i<n ; i++){
            if(stalls[i] - lastcowPos >=dis){ // if dis is possible 
                noOfcows++; // increase cows count
                lastcowPos = stalls[i]; // updated the last cow position 
            }
        }
        return noOfcows >= cows;
    }
int aggressiveCows(vector<int> &stalls, int cows)
{   int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int l = 1; // min possible dis
    int h = stalls[n-1] - stalls[0]; // max - min  (max possible dis)
    while(l<=h){
        int m = (l+h)/2;
        if(canweplace(stalls,cows, m)){
            l = m+1;// move right to find max possible if any
        }
        else  h = m-1; // move left to find possible distance
    }
    return h;
}
int main() {
    // your code goes here
    int t ;
    cin>>t;
    while(t--){
        int n , k ;
        cin>>n>>k;
        vector<int> stalls(n);
        for( int i =0 ; i < n ; i++) {
            int input ; cin>>input;
            stalls[i] = input;
        }
        cout<<aggressiveCows(stalls,k)<<endl;
    }
    return 0;
}
