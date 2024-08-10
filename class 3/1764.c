/*
Date: 7/22
No: 1764
Tier: s - 4
Name: µË∫∏¿‚
Language: C 99
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 21

int compare(const void* first, const void* second)
{
    return strcmp(*(const char**)first, *(const char**)second);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char **input = (char **)malloc((n + m) * sizeof(char *));
    
    for (int i = 0; i < n + m; i++) 
    {
        input[i] = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
        scanf("%s", input[i]);
    }

    qsort(input, n + m, sizeof(char *), compare);

    char **duplicates = (char **)malloc((n + m) * sizeof(char *));
    int idx = 0;
    
    for (int i = 0; i < n + m - 1; i++) 
    {
        if (strcmp(input[i], input[i + 1]) == 0) {
            duplicates[idx++] = input[i];
            i++; 
        }
    }

    printf("%d\n", idx);
    
    for (int i = 0; i < idx; i++) 
    {
        printf("%s\n", duplicates[i]);
    }

    for (int i = 0; i < n + m; i++) 
    {
        free(input[i]);
    }
    
    free(input);
    free(duplicates);

    return 0;
}