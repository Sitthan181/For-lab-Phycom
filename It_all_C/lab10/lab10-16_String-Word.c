#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[155];
    scanf("%[^\n]", str);

    char words[150][155];
    int word_lengths[150];
    int word_count = 0;

    int len = strlen(str);
    int in_word = 0;
    int char_idx = 0;

    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            if (in_word) {
                words[word_count][char_idx] = '\0';
                word_lengths[word_count] = char_idx;
                word_count++;
                in_word = 0;
                char_idx = 0;
            }
        } else {
            if (!in_word) {
                in_word = 1;
            }
            words[word_count][char_idx] = tolower(str[i]);
            char_idx++;
        }
    }

    printf("%d words\n", word_count);
    printf("----\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s : %d\n", words[i], word_lengths[i]);
    }

    return 0;
}
