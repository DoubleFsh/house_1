/*
ID:kali_hy1
TASK:ride 
LANG:C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");
	string a,b;
	fin >> a >> b;
	long long sum1 = 1;
	long long sum2 = 1;
	for (int i = 0;i < a.size();i++){
		sum1 = sum1 * (a[i] - '0' - 16);
	}
	for (int i = 0;i < b.size();i++){
		sum2 = sum2 * (b[i] - '0' - 16);
	}
	if ((sum1 % 47) == (sum2 % 47)){
		fout << "GO" << endl;
	}else{
		fout << "STAY" << endl;
	}
	return 0;
}
