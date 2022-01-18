/*
ID:kali_hy1
TASK:gift1
LANG:C++
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int np;
string name[12];
struct P{
	string name;
	int money,num;
	string gn[num];
	int shou;
}pi[12];


int main(){
	ofstream fout ("gift1.out");
	ifstream fin ("gift1.in");
	fin >> np;
	for (int i = 1;i <= np;i++){
		fin >> name[i];
	}
	
	for (int i = 1;i <= np;i++){
		fin >> pi[i].name;
		fin >> pi[i].money >> pi[i].num;
		for (int j = 1;j <= num;j++){
			fin >> pi[j].gn[j];
		}
	}
	
	for (int i = 1;i <= np;i++){
		
	}
	return 0;
}
