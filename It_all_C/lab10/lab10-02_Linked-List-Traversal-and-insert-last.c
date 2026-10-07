#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// DataNode structure using typedef
typedef struct DataNode {
  char* data;
  struct DataNode* next;
} DataNode;
 
typedef struct SinglyLinkedList {
  unsigned int count;
  DataNode* head;
} SinglyLinkedList; 
 
DataNode* createDataNode(char* data);
SinglyLinkedList *createSinglyLinkedList();
 
// Create a new DataNode
DataNode* createDataNode(char* data) {
  unsigned int length = strlen(data);
  char* text_new = (char*) malloc(sizeof(char) * length + 1);
  strcpy(text_new, data);
 
  DataNode *pNew = (DataNode*) malloc(sizeof(DataNode));
  pNew->data = text_new;
  pNew->next = NULL;
 
  return pNew;
}
 
// Create a new SinglyLinkedList
SinglyLinkedList* createSinglyLinkedList() {
    SinglyLinkedList *myList = (SinglyLinkedList*) malloc(sizeof(SinglyLinkedList));
    myList -> count = 0;
    myList -> head = NULL;
 
    return myList;
}
 
void traverse(SinglyLinkedList *list);
void insert_last(SinglyLinkedList *list, char *data);
 
int main() {
    SinglyLinkedList* mylist = createSinglyLinkedList();
    int n;
    char condition;
    char data[101];
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        scanf(" %c: %[^\n]s", &condition, data);
 
        if (condition == 'F') {
            ;
        } else if (condition == 'L') {
            insert_last(mylist, data);
        } else if (condition == 'D') {
            ;
        } else {
            printf("Invalid Condition!\n");
        }
    }
 
    traverse(mylist);
 
    // Remember to free allocated memory for each node's data
    DataNode *current = mylist->head;
    while (current != NULL) {
        free(current->data);
        DataNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(mylist);
    return 0;
}
 
// Traverse the list and print data
void traverse(SinglyLinkedList* list) {
    if (list->count == 0) {
        printf("This is an empty list.\n");
        return;
    }
    struct DataNode* pointer = list->head;
    while (pointer->next != NULL) {
        printf("%s -> ", pointer->data);
        pointer = pointer->next; // ปริ้นข้อมูลและขยับ pointer ไปเรื่อยๆ จนถึงโหนดตัวสุดท้าย
    }
    printf("%s\n", pointer->data);
}
 
// Insert a new node at the end of the list
void insert_last(SinglyLinkedList* list, char* data) {
    struct DataNode* pNew = createDataNode(data);
    if (list->count == 0) {
        list->head = pNew; // ถ้า Linked List ว่างให้เปลี่ยนตำแหน่ง list->head ไปที่ pNew
    } else {
        DataNode *temp = list->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = pNew; // ถ้า Linked List ไม่ว่างให้สร้าง Pointer ตัวใหม่และขยับไปที่โหนดสุดท้ายและเปลี่ยน pointer->next เป็น pNew
    }
    list->count++;
}