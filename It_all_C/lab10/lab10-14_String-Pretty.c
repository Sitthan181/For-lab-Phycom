#include <stdio.h>
#include <string.h>

int main(){

    int len;
    scanf("%d", &len);
    char str1[51], str2[41];
    
    // ปรับการรับค่าให้อ่านทั้งบรรทัดตามฟอร์แมตเดิม เพื่อรองรับกรณีมีช่องว่างในข้อความ
    scanf(" %[^\n]", str1);
    scanf(" %[^\n]", str2);

    int l_space1, r_space1, l_space2, r_space2;

    int space1 = (len - strlen(str1) - 2);
    if(space1 % 2 == 0){
        l_space1 = space1 / 2, r_space1 = space1 / 2;
    }else{
        l_space1 = (space1 / 2) + 1, r_space1 = space1 / 2;
    }
    
    int space2 = (len - strlen(str2) - 2);
    if(space2 % 2 == 0){
        l_space2 = space2 / 2, r_space2 = space2 / 2;
    }else{
        l_space2 = (space2 / 2) + 1, r_space2 = space2 / 2;
    }
    
    for(int i = 0; i < len;i++){
        printf("*");
    }
    printf("\n");
    printf("*");

    for(int i = 0;i < l_space1;i++){
        printf(" ");
    }
    printf("%s", str1);
    for(int i = 0;i < r_space1;i++){
        printf(" ");
    }

    printf("*");
    printf("\n");
    printf("*");
    
    for(int i = 0;i < l_space2;i++){
        printf(" ");
    }
    printf("%s", str2);
    for(int i = 0;i < r_space2;i++){
        printf(" ");
    }

    printf("*");
    printf("\n");

    for(int i = 0; i < len;i++){
        printf("*");
    }

    return 0;
}
