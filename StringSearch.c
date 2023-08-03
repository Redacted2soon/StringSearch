#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLENGTH 100

void selection_sort(char arr[][MAXLENGTH], int n) {
    int j, min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            // Convert strings to lowercase for case-insensitive comparison
            for (int k = 0; k < strlen(arr[min]); k++)
                arr[min][k] = tolower(arr[min][k]);
            for (int k = 0; k < strlen(arr[j]); k++)
                arr[j][k] = tolower(arr[j][k]);

            if (strcmp(arr[j], arr[min]) < 0) {
                min = j;
            }
        }
        // Swap the minimum element with the first element of the unsorted part
        char temp[MAXLENGTH];
        strcpy(temp, arr[min]);
        strcpy(arr[min], arr[i]);
        strcpy(arr[i], temp);
    }
}

int main(void) {
    int n;
    printf("Enter how many names: ");
    scanf("%d", &n);

    char arr[n][MAXLENGTH], x;
    char needle[MAXLENGTH];

    for (int i = 0; i < n; i++) {
        printf("Name %d: ", i + 1);
        while ((x = getchar()) != '\n' && x != EOF); // Clear input buffer to avoid unwanted input
        scanf("%[^\n]s", arr[i]); // Read the name (with spaces) into the array
    }

    selection_sort(arr, n); // Sort the names using selection_sort function

    printf("\nSorted Names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]); // Print the sorted names
    }

  printf("\nType \"exit\" to exit\n");
    while (1) {
        printf("Enter search string: ");
        scanf(" %[^\n]s", needle); // Read the search string (with spaces) into the variable

        // Convert the search string to lowercase for case-insensitive search
        for (int i = 0; i < strlen(needle); i++) {
            needle[i] = tolower(needle[i]);
        }

        // If the search string is "exit," exit the search loop
        if (strcmp(needle, "exit") == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < n; i++) {
            if (strstr(arr[i], needle) != NULL) {
                printf("%s\n", arr[i]); // Print the matching names
                found = 1;
            }
        }

        // If no matches are found and the search string is not "exit," print "not found"
        if (!found && strcmp(needle, "exit") != 0) {
            printf("not found\n");
        }
    }

    printf("\nbye!");

    return 0;
}
