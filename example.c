#include <stdio.h>
#include <string.h>
int main()
{
 char name[20];
 printf(" 저기요 이름이 어떻게 되세요 : ");
 fflush( stdin );
 gets( name );

 printf(" %s 님, 반갑습니다. \n", name );

 return 0;
}