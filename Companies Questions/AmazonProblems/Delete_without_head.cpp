struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node)
{
   // Your code here
   Node *prev;
   prev = node;
   while(node&&node->next){
       node->data = node->next->data;
       prev = node;
       node = node->next;
   }
   prev->next = NULL;
   delete node;
}
