#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DataNode structure using typedef
typedef struct DataNode {
  char* data;
  struct DataNode* next;
} DataNode;

DataNode* createDataNode(char* data);
// Create a new DataNode
DataNode* createDataNode(char* data) {
  unsigned int length = strlen(data);
  char* text_new = (char*) malloc(sizeof(char) * (length+1));
  strcpy(text_new, data);

  DataNode * pNew = (DataNode*) malloc(sizeof(DataNode));
  //*(pNew).data = text_new;
  pNew -> data = text_new;
  pNew -> next = NULL;
}
int main() {
  char data[101];
  scanf("%[^\n]s", data);

  DataNode* pNew = createDataNode(data);

  printf("%s\n", pNew->data);
  printf("%p\n", (void*)pNew->next);

  return 0;
}