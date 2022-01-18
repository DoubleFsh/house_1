#include <iostream>
#include <cmath>
using namespace std;

int n;
int num[110];
int dp_1[110],dp_2[110];

int main(){
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> num[i];
	}
	for (int i = 2;i <= n;i++){
		for (int j = 1;j < i;j++){
			if (num[i] > num[j]){
				dp_1[i] = max(1+dp_1[j],dp_1[i]);
			}
		}
	}
	for (int i = n-1;i >= 1;i--){
		for (int j = n;j > i;j--){
			if (num[i] > num[j]){
				dp_2[i] = max(1+dp_2[j],dp_2[i]);
			}
		}
	}
	int maxn = 0;
	for (int i = 1;i <= n;i++){
		maxn = max(dp_1[i]+dp_2[i],maxn);
	}
	maxn++;
	cout << n-maxn;
	return 0;
}
