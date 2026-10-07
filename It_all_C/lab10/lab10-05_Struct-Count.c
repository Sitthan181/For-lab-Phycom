#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
struct Count
{
    int countChar;
    int countWord;
    int countLine;
 
}count1 = {0,0,0};
 
void count(char *ptr, struct Count *c)
{
    int inWord = 0;
    c->countLine++;
 
    while (*ptr != '\0')
    {
        if (isspace((unsigned char)*ptr) == 0)
        {
            c->countChar++;
            if (inWord == 0)
            {
                c->countWord++;
                inWord = 1;
            }
        }
        else
        {
            inWord = 0;
        }
        ptr++;
    }
}
 
int main(){
 
    char str[1000];
    while (1)
    {
        scanf("%[^\n]", str);
        getchar();
 
        if(strlen(str) == 1 && str[0] == '.'){
            break;
        }
        count(str, &count1);
    }
     
    printf("Char = %d, word = %d, line = %d", count1.countChar, count1.countWord, count1.countLine);
 
    return 0;
}