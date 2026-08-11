#include <stdio.h>
 
int main() {
    char str[201];
    scanf("%[^\n]", str);
    char keep[201];
    char wheel[] = "AIWGZVFUTHSOJLKDECNMRQPYXB";
    char s_wheel[] = "aiwgzvfuthsojlkdecnmrqpyxb";
    int i = 0;
        while (str[i] != '\0') {
            char c = str[i];
 
            if (c >= 'A' && c <= 'Z') {
                for (int j = 0; j < 26; j++) {
                    if (c == wheel[j]) {
                        keep[i] = wheel[(j + 5) % 26];
                        break;
                    }
                }
            } 
            else if (c >= 'a' && c <= 'z') {
                for (int j = 0; j < 26; j++) {
                    if (c == s_wheel[j]) {
                        keep[i] = s_wheel[(j + 5) % 26];
                        break;
                    }
                }
            } 
            else {
                keep[i] = c;
            }
 
            i++;
        }
 
        keep[i] = '\0';
        printf("%s\n", keep);
 
    return 0;
}
