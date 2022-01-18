#include <iostream>
#include <cmath>
using namespace std;

int n;
int num[110];
int dp[110];

int main(){
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> num[i];
		dp[i] = 1;
	}
	int maxn = 1;
	for (int i = 2;i <= n;i++){
		for (int j = 1;j < i;j++){
			if (num[i] > num[j]){
				dp[i] = max(1+dp[j],dp[i]); 
			}
		}
		maxn = max(maxn,dp[i]);
	}
	cout << maxn;
	return 0;
}
