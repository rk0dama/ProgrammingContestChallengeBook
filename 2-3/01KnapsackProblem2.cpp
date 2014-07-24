#include<iostream>

const int MAX_N = 100;
const int MAX_W = 10000;

int n = 4;
int W = 5;
int w[MAX_N] = {2, 1, 3, 2,};
int v[MAX_N] = {3, 2, 4, 2,};

int dp[MAX_N+1][MAX_W+1];

int max(int a, int b){
	return ((a>b)? a:b);
}

int rec(int i, int j){
	if(dp[i][j] >= 0){
		return dp[i][j];
	}
	
	int res;
	if(i==n){
		res = 0;
	}else if(j < w[i]){
		res = rec(i + i, j);
	}else{
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	return dp[i][j] = res;
}

void solve(){
	memset(dp, -1, sizeof(dp));
	std::cout << rec(0, W) << std::endl;
}

int main(){
	solve();
	return 0;
}
