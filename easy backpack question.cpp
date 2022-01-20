#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int maxw,n;
int w[110],v[110];
int dp[110][20010]; 


int main(){
	cin >> maxw >> n;
	for (int i = 1;i <= n;i++){
		cin >> w[i] >> v[i];
	}
	
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= maxw;j++){
			if (w[i] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = max(dp[i-1][j],v[i]+dp[i-1][j-w[i]]);
			}
		}
	}
	cout << dp[n][maxw];
	return 0;
}
