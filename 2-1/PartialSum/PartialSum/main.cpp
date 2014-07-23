#include<iostream>
#include<vector>

int n;
std::vector<int> a = {1, 2, 4, 7};
int k;

bool partialSum(int ind, int sum){
	if (ind == n) return sum==k;
	if (partialSum(ind + 1, sum)) return true;
	if (partialSum(ind + 1, sum + a[ind])) return true;

	return false;
}

void solve(){
	std::cout << (partialSum(0, 0)? "True":"False") << std::endl;
}

int main(){
	n = 4;
	k = 13;
	solve();

	n = 4;
	k = 15;
	solve();

	std::cin >> n;
	return 0;
}