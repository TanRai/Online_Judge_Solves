// struct ListNode{
//     int val;
//     //ListNode *prev;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// }
struct Node {
  int val;
  Node *next;

  Node(int v) : val(v), next(nullptr) {}
  Node() : val(0), next(nullptr) {}
  Node(int v, Node *next) : val(v), next(next) {}
};
class MyLinkedList {
private:
int length = 0;
Node *head;
Node *tail;
public:
MyLinkedList() {

}

int get(int index) {
if(length<index+1)
  return -1;
int i = 0;
Node *ptr = head;
while(i<index)
{
  ptr = ptr->next;
  i++;
}
return ptr->val;
}

void addAtHead(int val) {
if(length == 0)
  head = tail = new Node(val);
else
{
  head = new Node(val,head);
}
length++;
}

void addAtTail(int val) {
if(length == 0)
  head = tail = new Node(val);
else
{
  tail->next = new Node(val,nullptr);
  tail = tail->next;
}
length++;
}

void addAtIndex(int index, int val) {
if(index>length)
  return;
if(index==length)
{
  if(length == 0)
  head = tail = new Node(val);
  else
  {
      tail->next = new Node(val,nullptr);
      tail = tail->next;
  }
  length++;
}
else if(index==0)
{
  if(length == 0)
  head = tail = new Node(val);
  else
  {
      head = new Node(val,head);
  }
  length++;
}
else
{
  int i = 0;
  Node *ptr = head;
  while(i<index-1)
  {
      ptr = ptr->next;
      i++;
  }
  //Node* temp = ptr;
  ptr->next = new Node(val,ptr->next);
  length++;
}
}

void deleteAtIndex(int index) {
if(index >=length)
  return;
if(length == 1)
{
  head = tail = nullptr;
  length--;
  return;
}
if(index == 0)
{
  head = head->next;
  length--;
  return;
}
int i = 0;
Node *ptr = head;
while(i<index-1)
{
  ptr = ptr->next;
  i++;
}
ptr->next = ptr->next->next;
length--;
if(index==length)
  tail = ptr;
}
};





