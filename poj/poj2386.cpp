/*poj2386 DFS
A pond is a connected set of squares with water in them,
 where a square is considered adjacent to all eight of its neighbors. 
 八联通的w被认为是一个pond 
*/
#include<stdio.h>
#define MAX_N 100
#define MAX_M 100
int N,M;  
char field[MAX_N][MAX_M];

void dfs(int x,int y){
	field[x][y] = '.';
	//search all eight neighbors
	for(int dx = -1; dx <= 1; dx++)
		for(int dy = -1; dy <= 1 ; dy++){
			int nx = x + dx, ny = y + dy;
			if(0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W')
				dfs(nx,ny);
		}
	return ;
}

void solve() {
	int res = 0;
	for (int i = 0; i < N ; i++)
		for (int j = 0; j < M ; j++){
			if(field[i][j] == 'W'){
					dfs(i,j);
					res++;
//					printf("%d\n",res); 
			}
		}
	printf("%d\n",res); 
}
int main(void){
	while(~scanf("%d%d",&N,&M)){
		getchar();
		for (int i = 0; i < N ; i++){
			for (int j = 0; j < M ; j++){
				scanf("%c",&field[i][j]);
			}
			getchar();
		}
		solve();	
	}
	return 0;
		
}
