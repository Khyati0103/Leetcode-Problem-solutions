// //Check palindrome of a number 
// #include<stdio.h>
// int main()
// {
//     int x;
//     int rev=0; // initialize rev as 0
//    printf("/n Enter x :");
//     scanf("%d",&x);
//     int original = x ; // set origin as x 
//     while(x!=0)
//     {
//         int digit = x % 10;
//         rev = rev * 10 + digit;
//         x/=10;
//     }
//     if(original==rev)
//     {
//         printf("True");
//     }
//     else
//     {
//         printf("False");
//     }
//    return 0;
// }

// #include<stdio.h>
// #include<string.h>
// int main()
// {
    
//     char str[100];
//     char str1[100];
//     printf("/n Enter string :");
//     // scanf("%99s",&str); // To handle string  overflow
//     fgets(str,sizeof(str),stdin);
//      strcpy(str1,str);
//    for(int i=0;i<strlen(str)/2;i++)
//     {
//         char ch = str[i];
//         str[i]=str[strlen(str)-1-i];
//         str[strlen(str)-1-i]=ch;
//     }
   
//     if(strcmp(str1,str)==0)
//     {
//         printf("Palindrome");
//     }
//     else{
//         printf("Not a palindrome");
//     }
//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100], cleanStr[100], reversedStr[100];
    int len = 0, i, j;

    // Read the input string
    printf("Enter a string: ");
    // scanf("%s", str);
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove the newline character

    // Remove non-alphanumeric characters and convert to lowercase
    for (i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            cleanStr[len++] = tolower(str[i]);
        }
    }
    cleanStr[len] = '\0'; // Null-terminate the cleaned string

    // Create reversed version of the cleaned string
    for (i = 0, j = len - 1; j >= 0; i++, j--) {
        reversedStr[i] = cleanStr[j];
    }
    reversedStr[i] = '\0';

    // Compare the cleaned string and its reverse
    if (strcmp(cleanStr, reversedStr) == 0) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
