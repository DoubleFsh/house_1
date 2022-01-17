#include <iostream>
#include <queue>
using namespace std;

int n,m,c=1;
int map[110][110];
queue <int> xs,ys;
int px[2] = {0,1};
int py[2] = {1,0};

void bfs(int x,int y){
	xs.push(x);
	ys.push(y);
	while(!xs.empty()){
		int ax = xs.front();
		int ay = ys.front();
		for (int i = 0;i < 2;i++){
			int nx = ax+px[i];
			int ny = ay+py[i];
			if (map[nx][ny] == 0 && nx > 0 && nx <= n && ny > 0 && ny <= m){
				map[nx][ny] = c++;
				xs.push(nx);
				ys.push(ny);
			}
		}
		xs.pop();
		ys.pop();
	}
}

int main(){
	cin >> n >> m;
	map[1][1] = c++;
	bfs(1,1);
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
