#include<bits/stdc++.h>
using namespace std;

//---------------LPS-----------------
void computeLPS(vector<int>&lps ,string &pat){
	int i =1,len=0; // len is max prefix length in pattern
	
	// 0th index don't have any same prefix and suffix
	lps[0]=0;
	int m = pat.length();

	while(i<m){
		if(pat[i]==pat[len]){// if we find same 
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if(len!=0) 
				len = lps[len-1];
			else{
				lps[i]=0;
				i++;// we can't find any match in prefix and suffix for this index
			}
		}
	}

}

vector<int> KMP(string &s, string &pat){
	int n = s.length();
	int m = pat.length();
	vector<int> res;
	//LPS array 
	vector<int> lps(m,0);
	computeLPS(lps,pat); // making LPS array

	//---------KMP algo---------
	int i =0 ,j=0;
	while(i<n){
		if(s[i]== pat[j]){ // if pat and s matches then increase both
			i++;
			j++;
		}
		if(j==m){// we found a pattern in string cause j becomes equal to size of pat
			res.push_back(i-j+1); // 1 based indexing
			j = lps[j-1]; // update j to it's previous value 
		}    
		else if (i<n && s[i]!=pat[j]){ // pat and s are different
			// if j!=0 then look at j-1 index in LPS and try to match
			if(j!=0) 
				j = lps[j-1]; 
			else {
				i++; // move i cause we don't have j in limit (j goes out of bound)
			}
		}

	}//while ends
	return res;
} //KMP algo ends

int main (){
	string s ="aaaaaac";
	string pat = "aaac";
	vector<int> ans;
    ans = KMP(s, pat);
    if (ans.empty()) {
        cout << "Pattern not found." << endl;
    } else {
        cout << "Pattern found at positions: ";
        for(auto i : ans) cout<<i<<" ";
        cout << endl;
    }
}
