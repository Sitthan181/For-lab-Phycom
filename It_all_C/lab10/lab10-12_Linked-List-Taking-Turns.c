#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DataNode
{
    char* info;
    struct DataNode *next;
}DataNode;

typedef struct SinglyLinkedList
{
    unsigned int count;
    DataNode* head;
}SinglyLinkedList;

DataNode* createDataNode(char* data){
    unsigned int len = strlen(data);
    char *info = (char *) malloc((len + 1) * (sizeof(char)));

    strcpy(info, data);

    DataNode *pNew = (DataNode *) malloc(sizeof(DataNode));
    pNew->info = info;
    pNew->next = NULL;

    return pNew;
}

SinglyLinkedList* createSinglyLinkedList(){
    SinglyLinkedList *myList = (SinglyLinkedList *) malloc(sizeof(SinglyLinkedList));

    myList->count = 0;
    myList->head = NULL;

    return myList;
}

void insert(SinglyLinkedList *list, char *data){
    DataNode *pNew = createDataNode(data);
    if(list->count == 0){
        list->head = pNew;
    }else{
        DataNode *temp = list->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = pNew;
    }
    list->count++;
}

void traverse(SinglyLinkedList *list){
    if (list->count == 0) return;
    
    int left_idx = 0;
    int right_idx = list->count - 1;
    int round = 1;
    unsigned int printed_count = 0;

    while (left_idx <= right_idx) {
        
        if (left_idx == right_idx) {
            DataNode *mid = list->head;
            for (int i = 0; i < left_idx; i++) mid = mid->next;
            
            printf("%s", mid->info);
            printed_count++;
            break;
        }

        // ค้นหาโหนดฝั่งซ้ายปัจจุบันตาม left_idx
        DataNode *leftNode = list->head;
        for (int i = 0; i < left_idx; i++) leftNode = leftNode->next;

        // ค้นหาโหนดฝั่งขวาปัจจุบันตาม right_idx
        DataNode *rightNode = list->head;
        for (int i = 0; i < right_idx; i++) rightNode = rightNode->next;

        // สลับฝั่งพิมพ์ตามรอบคู่/รอบคี่
        if (round % 2 != 0) {
            // รอบคี่: พิมพ์ ขวา -> ซ้าย (เช่น 7 -> 1)
            printf("%s -> %s", rightNode->info, leftNode->info);
        } else {
            // รอบคู่: พิมพ์ ซ้าย -> ขวา (เช่น 2 -> 6)
            printf("%s -> %s", leftNode->info, rightNode->info);
        }

        // ขยับอินเด็กซ์บีบเข้าหากัน
        left_idx++;
        right_idx--;
        printed_count += 2;
        round++; // ✨ เปลี่ยนเป็นเพิ่มทีละ 1 รอบ เพื่อให้สลับคู่/คี่ได้อย่างถูกต้อง

        // พิมพ์เครื่องหมายเชื่อมถ้ายังมีโหนดเหลืออยู่
        if (printed_count < list->count) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main(){
    int len;
    scanf("%d", &len);
    SinglyLinkedList* myList = createSinglyLinkedList();
    for (int i = 0;i < len;i++)
    {
        char *str = malloc(21 * sizeof(char));
        scanf("%s", str);
        if(strcmp(str, "Last") == 0){
            break;
        }

        insert(myList, str);
        free(str);
    }

    traverse(myList);

    return 0;
}