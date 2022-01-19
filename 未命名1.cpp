/*
ID:kali_hy1
TASK:gift1
LANG:C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int np;
string name[15];
struct A{
	string name;
	int money,ple;
	string name2[15];
}ren[15];
 

int main(){
	ifstream fin ("gift1.in");
	ofstream fout ("gift1.out");	
	fin >> np;
	for (int i = 1;i <= np;i++){
		fin >> name[i];
	}
	for (int i = 1;i <= np;i++){
		fin >> ren[i].name;
		fin >> ren[i].money >> ren[i].ple;
		for (int j = 1;j <= ple;j++){
			fin >> ren[i].name2[j];
		}
	}
	
	for (int i = 1;i <= np;i++){
		int gm = ren[i].money / ren[i].ple;
		for (int j = 1;j <= ren[i],ple;j++){
			string tmpna = ren[i].name2[j];
			for (int z = 1;z <= np;z++){
				if (tmpna == ren[z].name){
					ren[z].shou += gm;
				}
			}
		}
		
	}
	return 0;
}
