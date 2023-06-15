#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main () {
    printf("Grammar:\n");
    printf("--------\n");
    printf(" e -> ta\n a -> +ta | ε\n t -> fb\n b -> *fb | ε\n f -> i | (e)\n\n");
    
    char tab[5][6][5] = { 
        "ta", "@", "@", "ta", "@", "@", 
        "@", "+ta", "@", "@", "!", "!", 
        "fb","@", "@", "fb", "@", "@", 
        "@", "!", "*fb", "@", "!", "!", 
        "i", "@", "@", "(e)", "@", "@" };
        
    char s[30], st[30] = {'$', 'e', '\0'};
    printf("Enter the string : ");
    scanf("%s", s);
    strcat(s, "$");
    
    int st_i = 1, s_i = 0;
    printf ("\nStack\t\tInput\n");
    printf("-----\t\t-----\n");
    printf("$e\t\t%s\n",s);
    while (st[st_i] != '$' || s[s_i] != '$') {
       int s1,s2;
    	switch (st[st_i]) {
            case 'e':s1=0;break;
            case 'a':s1=1;break;
            case 't':s1=2;break;
            case 'b':s1=3;break;
            case 'f':s1=4;break;
            default:s1=-1;
        }   
            
    	switch(s[s_i]) {
            case 'i':s2=0;break;
            case '+':s2=1;break;
            case '*':s2=2;break;
            case '(':s2=3;break;
            case ')':s2=4;break;
            case '$':s2=5;break;
            default:s2=-1;
        }
            
    	if(s1==-1 || s2==-1 || tab[s1][s2]=="@") {
            printf("Failure\n");
            exit(0);
        }
            
    	if(tab[s1][s2][0]=='!') {
            st[st_i]='\0';
            st_i--;
        } 
        
        else {
            int len=strlen(tab[s1][s2]);
            char temp[20];
            for(int k=0;k<len;k++){
                temp[len-k-1]=tab[s1][s2][k];
            } 
            temp[len]='\0';
            st[st_i]='\0';
            strcat(st,temp);
            st_i=strlen(st)-1;
        }
        
    	printf("%s \t\t",st);
    	for(int k=s_i;s[k]!='\0';k++)
            	printf("%c",s[k]);
    	printf("\n");
    
        if(st[st_i]==s[s_i] && s[s_i]!='$') {
            st[st_i]='\0';
            s_i++;
            st_i--;
        }
    }
    printf("Success\n");
}

/*
OUTPUT :
--------------
Grammar:
--------
 e -> ta
 a -> +ta | ε
 t -> fb
 b -> *fb | ε
 f -> i | (e)

Enter the string : i*(i+i)
Stack		Input
-----		-----
$e		i*(i+i)$
$at 		i*(i+i)$
$abf 		i*(i+i)$
$abi 		i*(i+i)$
$abf* 		*(i+i)$
$ab)e( 		(i+i)$
$ab)at 		i+i)$
$ab)abf 		i+i)$
$ab)abi 		i+i)$
$ab)a 		+i)$
$ab)at+ 		+i)$
$ab)abf 		i)$
$ab)abi 		i)$
$ab)a 		)$
$ab) 		)$
$a 		$
$ 		$
Success

*/
