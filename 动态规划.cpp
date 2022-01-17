#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int n;
int a[110][110];
int dp[110][110];


int main(){
	cin >> n;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= i;j++){
			cin >> a[i][j];
		}
	}
	
	for (int i = n;i >= 1;i--){
		for (int j = 1;j <= i;j++){
			dp[i][j] = a[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
		}
	}
	cout << dp[1][1];
	return 0;
}
