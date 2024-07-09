#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
}

bool next_permutation(char* str, int length) {
    int i = length - 1;
    while (i > 0 && str[i - 1] >= str[i]) {
        i--;
    }
    if (i <= 0) {
        return false;
    }
    
    int j = length - 1;
    while (str[j] <= str[i - 1]) {
        j--;
    }
    
    swap(&str[i - 1], &str[j]);
    
    j = length - 1;
    while (i < j) {
        swap(&str[i], &str[j]);
        i++;
        j--;
    }
    
    return true;
}

int main() {
    char word[100];
    printf("Введіть слово: ");
    scanf("%s", word);
    
    int length = strlen(word);
    // Сортуємо слово
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (word[i] > word[j]) {
                swap(&word[i], &word[j]);
            }
        }
    }
    
    int count = 0;
    do {
        count++;
    } while (next_permutation(word, length));
    
    printf("Кількість анаграм: %d\n", count);
    return 0;
}
