#include <stdio.h>
#include <string.h>

struct Weather {
    char outlook[9]; //outlook{overcast,sunny,rain}
    int temperature;
    int humidity;
    char wind; //wind{T,F}
};

void playing_decision(struct Weather *a){

    int len = 0;
    while(strcmp(a[len].outlook, "END") != 0)
        {
            if(strcmp(a[len].outlook, "rain") == 0){
                if (a[len].wind == 'T')
                {
                    printf("no");
                }else{
                    printf("yes");
                }
            }else if (strcmp(a[len].outlook, "sunny") == 0){
                if (a[len].humidity > 77.5)
                {
                    printf("no");
                }else{
                    printf("yes");
                }
            }else if (strcmp(a[len].outlook, "overcast") == 0)
            {
                printf("yes");
            }
            printf("\n");
            len++;
        }
}

int main(){

    int len;
    scanf("%d", &len);
    struct Weather weather[len + 1];

    for (int i = 0; i < len; i++)
    {
        scanf("%s %d %d %c", weather[i].outlook, &weather[i].temperature, &weather[i].humidity, &weather[i].wind);
    }

    strcpy(weather[len].outlook, "END");
    playing_decision(weather);



    return 0;
}