// //Word Subjets
// 916. Word Subsets
// Medium
// Topics
// Companies
// You are given two string arrays words1 and words2.

// A string b is a subset of string a if every letter in b occurs in a including multiplicity.

// For example, "wrr" is a subset of "warrior" but is not a subset of "world".
// A string a from words1 is universal if for every string b in words2, b is a subset of a.

// Return an array of all the universal strings in words1. You may return the answer in any order.

 

// Example 1:

// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
// Output: ["facebook","google","leetcode"]
// Example 2:

// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
// Output: ["apple","google","leetcode"]
 

// Constraints:

// 1 <= words1.length, words2.length <= 104
// 1 <= words1[i].length, words2[i].length <= 10
// words1[i] and words2[i] consist only of lowercase English letters.
// All the strings of words1 are unique.


// #include<stdio.h>
// #include<string.h>
// int main()
// {
//   char str1[100],str2[100];
//   char result[100]; 
//    printf("Enter string in array 1 :");
//    scanf("%s",str1);
//    printf("%s",str1);
//    printf("Enter String in array 2 :");
//    scanf("%s",str2);
//     for(int i=0;i<strlen(str1);i++)
//     {
//         for(int j=0;j<strlen(str2);j++)
//         {
//             //   if(str1[i]==str2[j])
//             if(strstr(str1,str2) != NULL) 
//               {
//                  printf("%s",str1[i]);
//               }
//             // printf("%s",result);             
//         }
//     }
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to count the frequency of each letter in a word
void countFrequency(const char *word, int *freq) {
    for (int i = 0; word[i] != '\0'; i++) {
        freq[word[i] - 'a']++;
    }
}

// Main function
char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    int maxFreq[26] = {0}; // Maximum required frequencies across all words in words2
    int tempFreq[26];      // Temporary frequency array for individual words in words2

    // Determine the maximum frequency requirements from words2
    for (int i = 0; i < words2Size; i++) {
        memset(tempFreq, 0, sizeof(tempFreq)); // Reset temporary frequency array
        countFrequency(words2[i], tempFreq);  // Count frequencies for the current word
        for (int j = 0; j < 26; j++) {
            maxFreq[j] = maxFreq[j] > tempFreq[j] ? maxFreq[j] : tempFreq[j]; // Update max frequencies
        }
    }

    // Prepare the result array
    char **result = (char **)malloc(words1Size * sizeof(char *));
    *returnSize = 0;

    // Check each word in words1
    for (int i = 0; i < words1Size; i++) {
        int freq[26] = {0};
        countFrequency(words1[i], freq); // Count frequencies for the current word

        int isUniversal = 1; // Assume the word is universal
        for (int j = 0; j < 26; j++) {
            if (freq[j] < maxFreq[j]) {
                isUniversal = 0; // The word doesn't meet the requirements
                break;
            }
        }

        if (isUniversal) {
            result[*returnSize] = words1[i]; // Add the word to the result
            (*returnSize)++;
        }
    }

    return result;
}
