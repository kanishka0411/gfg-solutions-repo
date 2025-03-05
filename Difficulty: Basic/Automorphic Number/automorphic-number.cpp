//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
		string is_AutomorphicNumber(int n)
		{
		   long long sq=(long long)n*n;
		   int temp=n;
		   if(sq%10 ==temp%10) return "Automorphic";
		   return "Not Automorphic";
		}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_AutomorphicNumber(n);
    	cout << ans <<"\n";
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends