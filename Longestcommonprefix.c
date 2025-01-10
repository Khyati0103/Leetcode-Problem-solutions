#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char* strs[], int strsSize) {
    if (strsSize == 0) return ""; // If there are no strings, return an empty string

    // Start with the first string as the initial prefix
    char *prefix = strs[0];

    // Compare the prefix with every other string
    for (int i = 1; i < strsSize; i++) {
        // Compare the characters of the prefix and the current string
        int j = 0;
        while (prefix[j] != '\0' && strs[i][j] != '\0' && prefix[j] == strs[i][j]) {
            j++;
        }
        // Trim the prefix to the common part
        prefix[j] = '\0';

        // If the prefix becomes empty, return an empty string
        if (prefix[0] == '\0') {
            return "";
        }
    }

    return prefix;
}

int main() {
    // Example array of strings
    char *strs[] = {"flower", "flow", "flight"};
    
    int strsSize = sizeof(strs) / sizeof(strs[0]);

    // Find and print the longest common prefix
    char *result = longestCommonPrefix(strs, strsSize);
    printf("Longest Common Prefix: %s\n", result);

    return 0;
}
