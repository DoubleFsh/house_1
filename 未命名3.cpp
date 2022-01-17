#include <iostream>
#include <cmath>
using namespace std;

int num[100010];
int dp[100010];


int main(){
	int n,x;
	cin >> n >> x;
	num[1] = x;
	dp[1] = x;
	int sum = x;
	for (int i = 2;i <= n;i++){
		num[i] = (379*num[i-1]+131)%997;
		dp[i] = min(num[i],dp[i-1]);
		sum += dp[i];
	}
	cout << sum;
	return 0;
}
