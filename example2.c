#include <stdio.h>
int main()
{
 int dan, i;
 printf(" 몇단 출력할까요 : ");
 scanf("%d", &dan);

 printf(" [%d dan] \n", dan);
 for(i=1; i<10; i++)
  printf(" %d * %d = %d \n", dan, i, dan*i);

 return 0;
}