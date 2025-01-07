//Check palindrome of a number 
#include<stdio.h>
int main()
{
    int x;
    int rev=0; // initialize rev as 0
   printf("/n Enter x :");
    scanf("%d",&x);
    int original = x ; // set origin as x 
    while(x!=0)
    {
        int digit = x % 10;
        rev = rev * 10 + digit;
        x/=10;
    }
    if(original==rev)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
   return 0;
}

#include<stdio.h>
#include<string.h>
int main()
{
    
    char str[100];
    char str1[100];
    printf("/n Enter string :");
    scanf("%99s",&str); // To handle string  overflow
     strcpy(str1,str);
   for(int i=0;i<strlen(str)/2;i++)
    {
        char ch = str[i];
        str[i]=str[strlen(str)-1-i];
        str[strlen(str)-1-i]=ch;
    }
   
    if(strcmp(str1,str)==0)
    {
        printf("Palindrome");
    }
    else{
        printf("Not a palindrome");
    }
    return 0;
}
