#include <stdio.h>
#include <ctype.h>
int main(){
    char name[20][101];
    char temp[101];
    for (int i = 0; i < 20; i++){
        scanf(" %[^\n]", name[i]);
        int new_w = 1;
        for (int j = 0; name[i][j] != '\0'; j++){
            if (isspace(name[i][j])) {
                new_w = 1;
        } else {
            if (new_w) {
                name[i][j] = toupper(name[i][j]);
                new_w = 0;
                } else {
                    name[i][j] = tolower(name[i][j]);
                }
            }
        }
    }
for (int i = 0; i < 20 - 1; i++) {
    for (int j = 0; j < 20 - i - 1; j++) {
        int k = 0;
        while (name[j][k] && name[j][k] == name[j+1][k]) {
            k++;
        }

        //เทียบด้วย ASCII
        if (name[j][k] > name[j+1][k]) {
            for (int k = 0; (temp[k] = name[j][k]); k++);
            for (int k = 0; (name[j][k] = name[j+1][k]); k++);
            for (int k = 0; (name[j+1][k] = temp[k]); k++);
        }
    }
}
for (int i = 0; i < 20; i++) {
    printf("%s\n", name[i]);
}

return 0;
}
