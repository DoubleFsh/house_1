#include <iostream>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

int n;
int num[210];
bool pass[210][210];
int dp[210];
int road[210];

int main(){
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> num[i];
	}
	while (1){
		int a,b;
		cin >> a >> b;
		if (a == 0){
			break;
		}
		pass[a][b] = true;
	}
	
	int maxa = 0;
	//dp[n]Îª±ß½ç 
	dp[n] = num[n];
	int start = 0;
	for (int i = n-1;i >= 1;i--){
		int maxc = 0;
		int next = 0;
		for (int j = i+1;j <= n;j++){
			if (pass[i][j] && dp[j] > maxc){
				maxc = dp[j];
				next = j;
			}
		}
		dp[i] = num[i] + maxc;
		road[i] = next;
		if (dp[i] > maxa){
			maxa = dp[i];
			start = i;
		}
	}
	cout << start;
	while (road[start] != 0){
		cout << "-" << road[start];
		start = road[start];
	}
	cout << endl;
	cout << maxa;
	return 0;
}
