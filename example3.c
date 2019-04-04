#include <stdio.h>
int main()
{
 char nation[20];
 int age;
 printf(" 여행하고픈 나라는 : ");
 fflush(stdin);
 gets(nation);

 printf(" 몇 살까지 살고 싶나요 : ");
 scanf("%d", &age);

 printf(" %s 좋아요. %d 살까지 사세요. \n", nation, age);

 return 0;
}