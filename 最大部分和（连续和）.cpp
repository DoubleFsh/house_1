#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int n;
int num[110];
int dp[110];


int main(){
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> num[i];
	}
	dp[1] = num[1];
	dp[2] = max(dp[1]+num[2],num[2]);
	for (int i = 3;i <= n;i++){
		dp[i] = max(dp[i-1]+num[i],dp[i]);
	}
	int maxn = 0;
	for (int i = 1;i <= n;i++){
		if (dp[i] > maxn){
			maxn = dp[i];
		}
	}
	cout << maxn;
	return 0;
}
