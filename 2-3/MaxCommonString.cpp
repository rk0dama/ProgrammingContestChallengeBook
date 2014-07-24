#include <iostream>
#include <algorithm>

const int MAX_N = 100;
const int MAX_M = 100;

int n = 4;
int m = 4;
char s[MAX_N] = "abcd";
char t[MAX_M] = "becd";

int dp[MAX_N+1][MAX_M+1];		// dp table

void solve(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(s[i+1] == t[j+1]){
				dp[i+1][j+1] = std::max({dp[i][j] + 1, dp[i][j+1], dp[i+1][j]});
			}else{
				dp[i+1][j+1] = std::max({dp[i][j+1], dp[i+1][j]});
			}
		}
	}
	std::cout << dp[n][m] << std::endl;
}

int main(){
	solve();
	return 0;
}

