/*************************************************************************
	> File Name: poj2000.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  5/20 10:46:03 2017
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#define nsqueue(x) (x)*(x+1)*(2*(x)+1)/6
int in[21];
int main(void)
{
    int d,i = 0;
    scanf("%d",&d);
    while(d!=0){
        in[i++] = d;
        scanf("%d",&d);
    }
    //printf("%d\n",nsqueue(13));
    for(int j=0;j<i;j++){
        int n = (int)sqrt((double)2*in[j]);
        if(n*(n+1) == 2*in[j]){
            printf("%d %d\n",in[j],nsqueue(n));
            }
        else if(n*(n+1) > 2*in[j]){
            int superplus = 2*in[j] - n*(n-1);
            int end = nsqueue(n-1) + superplus*n/2;
            printf("%d %d\n",in[j],end);
        }
        else if(n*(n+1) < 2*in[j]){
            int superplus = 2*in[j] - n*(n+1);
            int end =  nsqueue(n) + superplus*(n+1)/2;
            printf("%d %d\n",in[j],end);
        }
    }
    return 0;
}
