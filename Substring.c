#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    // Allocate memory for an array of string pointers
    char **str = (char **)malloc(n * sizeof(char *));
    
    // Input the strings
    printf("Enter string array:\n");
    for (int i = 0; i < n; i++) {
        str[i] = (char *)malloc(100 * sizeof(char)); // Allocate memory for each string
        scanf("%s", str[i]);
    }

    // To find substrings
    printf("Substrings:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {  // Avoid comparing a string with itself
                if (strstr(str[i], str[j]) != NULL) {  // Check if str[j] is a substring of str[i]
                    printf("%s is a substring of %s\n", str[j], str[i]);
                }
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(str[i]);
    }
    free(str);

    return 0;
}
