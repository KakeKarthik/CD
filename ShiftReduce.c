// Implementation of Shift Reduce Parsing

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];
void check();

int main() {

      printf("GRAMMAR is :\n E->E+E \n E->E*E \n E->(E) \n E->id\n");
      printf("Enter an input string : ");
      scanf("%s",a);
      c=strlen(a);
      strcpy(act,"SHIFT->");
      printf("stack \t input \t action\n");
      printf("----- \t ----- \t ------\n");
      for(i=0, j=0; j<c; i++,j++) {
         if(a[j]=='i' && a[j+1]=='d') {
              stk[i]=a[j];
              stk[i+1]=a[j+1];
              stk[i+2]='\0';
              a[j]=' ';
              a[j+1]=' ';
              printf("\n$%s\t%s$\t%sid",stk,a,act);
              check();
           } else {
              stk[i]=a[j];
              stk[i+1]='\0';
              a[j]=' ';
              printf("\n$%s\t%s$\t%ssymbols",stk,a,act);
              check();
           }
      }
      printf("\n");
}

void check() {
     
     strcpy(ac,"REDUCE TO E");
     for(z=0; z<c; z++)
       if(stk[z]=='i' && stk[z+1]=='d') {
           stk[z]='E';
           stk[z+1]='\0';
           printf("\n$%s\t%s$\t%s",stk,a,ac);
           j++;
         }

     for(z=0; z<c; z++)
       if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E') {
           stk[z]='E';
           stk[z+1]='\0';
           stk[z+2]='\0';
           printf("\n$%s\t%s$\t%s",stk,a,ac);
           i=i-2;
         }

     for(z=0; z<c; z++)
       if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E') {
           stk[z]='E';
           stk[z+1]='\0';
           stk[z+1]='\0';
           printf("\n$%s\t%s$\t%s",stk,a,ac);
           i=i-2;
         }

     for(z=0; z<c; z++)
       if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')') {
           stk[z]='E';
           stk[z+1]='\0';
           stk[z+1]='\0';
           printf("\n$%s\t%s$\t%s",stk,a,ac);
           i=i-2;
         }
}

/*
OUTPUT:
------
GRAMMAR is :
 E->E+E
 E->E*E
 E->(E)
 E->id
Enter an input string : id+id*id
stack    input   action
-----    -----   ------

$id       +id*id$       SHIFT->id
$E        +id*id$       REDUCE TO E
$E+        id*id$       SHIFT->symbols
$E+id        *id$       SHIFT->id
$E+E         *id$       REDUCE TO E
$E           *id$       REDUCE TO E
$E*           id$       SHIFT->symbols
$E*id           $       SHIFT->id
$E*E            $       REDUCE TO E
$E              $       REDUCE TO E
*/
