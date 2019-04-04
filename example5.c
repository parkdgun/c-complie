#include <stdio.h>
#include <string.h>
int main()
{
 //필요한 변수 선언
 char flower[5][10] = {"들국화","솜다리","개나리","옥잠화","백년초"};
 char tmp[10];
 int i,j,n;
 n = sizeof(flower)/sizeof(char[10]);

 //원본 출력, 안되면 넘어가지 말것, 반드시 해결하고 넘어갈것.
 puts(" [원 본 데이터] ");
 for(i=0; i<n; i++)
  printf(" flower[%d] = %s \n", i, flower[i]);

 //정렬
 for(i=0; i<n-1; i++)
 {
  for(j=i+1; j<n; j++)
  {
   if( strcmp( flower[i], flower[j] ) > 0)
   {
    strcpy(tmp, flower[i]);
    strcpy(flower[i], flower[j]);
    strcpy(flower[j], tmp);
   }
  }
 }

 //정렬후  출력
 puts("\n [정렬된 데이터] ");
 for(i=0; i<n; i++)
  printf(" flower[%d] = %s \n", i, flower[i]);

 getchar();

 return 0;
}