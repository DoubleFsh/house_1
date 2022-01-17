#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int n,m,sttx,stty,stpx,stpy;
int map[160][160];
queue <int> xs,ys;
int step[160][160];
int px[4] = {-1,0,1,0};
int py[4] = {0,1,0,-1};

void dfs(int x,int y){
	if (x == sttx && y == stty){
		printf("(%d,%d)",x,y);
		return;
	}
	int nx,ny;
	for (int i = 0;i < 4;i++){
		nx = x+px[i];
		ny = y+py[i];
		if (step[nx][ny] == step[x][y]-1){
			dfs(nx,ny);
			printf("->(%d,%d)",x,y);
			break;
		}
	}
	
}

void bfs(int x,int y){
	map[x][y] = 1;
	xs.push(x);
	ys.push(y);
	while (!xs.empty()){
		int fx = xs.front();
		int fy = ys.front();
		xs.pop();
		ys.pop();
		map[fx][fy] = 1;
		if (fx == stpx && fy == stpy){
			return;
		}
		for (int i = 0;i < 4;i++){
			int nx = fx + px[i];
			int ny = fy + py[i];
			if (map[nx][ny] == 0 && nx > 0 && nx <= n && ny > 0 && ny <= m){
				step[nx][ny] = step[fx][fy]+1;
				xs.push(nx);
				ys.push(ny);
			}
		}
		
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++){
			cin >> map[i][j];
		}
	}
	cin >> sttx >> stty;
	cin >> stpx >> stpy;
	step[sttx][stty] = 1;
	bfs(sttx,stty);
	if (step[stpx][stpy] == 0){
		cout << "no way";
	}else {
		dfs(stpx,stpy);
	}
	return 0;
}
