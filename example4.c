#include <stdio.h>
int main()
{
 //필요한 변수 선언
 int score[5] = {90,30,80,70,60};
 int i, j, n, tmp;
 n = sizeof(score)/sizeof(int);
 
 // 원본 출력
 printf(" [%d]개의 원본 데이터 \n", n);
 for(i=0; i<n; i++)
  printf(" score[%d] = %d \n", i, score[i]);

 // 정렬
 for(i=0; i<n-1; i++)
 {
  for(j=i+1; j<n; j++)
  {
   if(score[i] > score[j])
   {
    tmp = score[i];
    score[i] = score[j];
    score[j] = tmp;
   }
  }
 }

 //정렬후 출력
 printf(" \n [ 정 렬 후 ] \n");
 for(i=0; i<n; i++)
  printf(" score[%d] = %d \n", i, score[i]);

 return 0;
}