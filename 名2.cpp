#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int n;cin>>n;
	int a[n+10];
	for (int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<n;j++){
		int max_pos=j;
		for(int i=j;i<=n;i++){
			if(a[max_pos]>a[i]){
				max_pos=i;
			}
		}
		swap(a[j],a[max_pos]);		
	}
	
	for(int i=n;i>=1;i--){
		if(a[i]%2!=0){
			cout<<a[i]<<" ";
			break;	
		}	
	}
	for(int i=n;i>=1;i--){
		if(a[i]%2==0){
			cout<<a[i]<<"\n";
			break;	
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
return 0;
}	
