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
void insert_front(SinglyLinkedList* list, char* data);
void delete(SinglyLinkedList* list, char* data);
  
int main() {
    SinglyLinkedList* mylist = createSinglyLinkedList();
    int n;
    char condition;
    char data[100]; // Assuming a maximum string length of 99 characters
    scanf("%d", &n);
  
    for (int i = 0; i < n; i++) {
        scanf(" %c: %[^\n]s", &condition, data); // Read condition and string data
  
        if (condition == 'F') {
            insert_front(mylist, data);
        } else if (condition == 'L') {
            insert_last(mylist, data);
        } else if (condition == 'D') {
            delete(mylist, data);
        } else {
            printf("Invalid Condition!\n");
        }
    }
  
    traverse(mylist);
    // Remember to free allocated memory for each node's data
    DataNode* current = mylist->head;
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
  
void insert_front(SinglyLinkedList* list, char* data) {
    struct DataNode* pNew = createDataNode(data);
    pNew->next = list->head;
    list->head = pNew;
    list->count++;
}
  
void delete(struct SinglyLinkedList* list, char* data) {
    struct DataNode* current = list->head;
    struct DataNode* previous = NULL;
 
    if(current != NULL){
        if(strcmp(current->data, data) == 0){
            list->head = current->next;
            free(current->data);
            free(current);
            list->count--;
            return;
        }
    }
  
    while(current != NULL && strcmp(current->data, data) != 0){
        previous = current;
        current = current->next;
    }
 
    if(current == NULL){
        printf("Cannot delete, %s does not exist.\n", data);
        return;
    }
 
 
    previous->next = current->next; 
    free(current->data);
    free(current);
  
    list->count--;
  
    //d->b->a->c->e
}