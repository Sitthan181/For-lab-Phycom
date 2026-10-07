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

int main(){
    SinglyLinkedList* myList = createSinglyLinkedList();
    while (1)
    {
        char *str = malloc(21 * sizeof(char));
        scanf("%s", str);
        if(strcmp(str, "Last") == 0){
            break;
        }

        insert(myList, str);
        free(str);
    }
    
    int index;
    scanf("%d", &index);
    if(index < 0){
        index += myList->count;
    }
    if(index < 0 || index >= myList->count){
        printf("Error");
    }else{
        DataNode *temp = myList->head;
        for(int i = 0;i < index;i++){
            temp = temp->next;
        }
        printf("%s", temp->info);
    }
    
    return 0;
}