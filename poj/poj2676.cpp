//DFS ��ϰ ���� poj2676
#include<stdio.h>
#include<string.h>
int row[10][10]; //row[i][x]��ǵ�i������x�Ƿ����
int col[10][10]; //col[j][y]��ǵ�j������y�Ƿ����
int small[10][10]; //small[k][x]����ڵ�k��3*3�ķ���������z�Ƿ������
int map[10][10];
//����ʹ��������һ����������¼С�����е����ֳ������
/*���Ƕ�С����������ʾ��ţ�
		0	1	2
		3	4	5
		6	7	8 
		����i<10,j<10
		i	i/3		j	j/3
		0	 0		0	 0
		1	 0 		1	 0
		2	 0		2 	 0
		3	 1		3	 1
		4	 1		4 	 1
		5	 1		5	 1
		6	 2		6	 2
		7	 2		7	 2 	
		8	 2		8 	 2
����������a = i/3 ; b = j/3 ; ���� �Ź����������������֮��Ĺ�ϵ�����ѷ���
k = 3*a + b ; 
�������ʹ��1~9Ϊ�����±�	=>  k = 3*(i-1)/3 + (j-1)/3 + 1
*/
int f2k(int i,int j){
	return 3*((i-1)/3) + (j-1)/3 + 1;
}
void mymemset(void){
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10 ;j++){
			col[i][j] = 0;
			row[i][j] = 0;
			small[i][j] = 0;
		}
}
void init(){
	int i,j;
	char ch;
	mymemset();
	for(i = 1 ; i < 10; i++){
		for(j = 1; j < 10 ; j++){
			scanf("%c",&ch);
			map[i][j] = (int)(ch - '0');
			if(map[i][j]){	//��¼��Щ��Ϊ0�����ֳ������ 
				int k = f2k(i,j);
				row[i][map[i][j]] = 1;
				col[j][map[i][j]] = 1;
				small[k][map[i][j]] = 1;
			}
		}
		getchar();
	}
}
int dfs(int x,int y){
	if(x == 10)	
		return 1;
	int flag = 0;
	if(map[x][y]){
		if(y == 9)
			flag = dfs(x+1,1);
		else 
			flag = dfs(x,y+1);
		if(flag)
			return 1;
		else 
			return 0;
	}
	else{
		int k = f2k(x,y);
		for(int i = 1 ;i <= 9; i++) //map[x][y]����ո����γ���9������������ɹ�������i 
			if(!row[x][i] && !col[y][i] && !small[k][i]){
				map[x][y] = i;
				row[x][i] = 1;
				col[y][i] = 1;
				small[k][i] = 1;
				if(y == 9)
					flag = dfs(x+1,1);    
				else 
					flag = dfs(x,y+1);
				if(!flag){		//����dfs���ص�flag�ж��Ƿ�ɹ���ʧ�ܾͻ�ԭ 
					map[x][y] = 0;
					row[x][i] = 0;
					col[y][i] = 0;
					small[k][i] = 0;
//					printf("falled");
				}else
					return 1;
			} 		
	}
	return 0; // �޽� 
}

int main(void)
{
	int t;
	scanf("%d",&t); 
	getchar();
	while(t--){
		init();
		dfs(1,1);
		for(int i = 1; i <= 9; i++){
			for(int j = 1; j <= 9; j++)
				printf("%d",map[i][j]);
			printf("\n");
		}
	}	
	return 0;	
} 





















