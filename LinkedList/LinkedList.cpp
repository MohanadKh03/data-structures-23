#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList(){
    length = 0;
    head = tail = NULL;
}

template<class T>
LinkedList<T>::LinkedList(T val){
    length = 0;
    head = tail = NULL;
}

template<class T>
int LinkedList<T>::getSize(){
    return length;
}

template<class T>
void LinkedList<T>::Append(T val){
    Node<T>* newNode = new Node<T>(val);
  
    //If the list is empty then the head and tail will point to the node we just created
    if(length == 0)
        head = tail = newNode;
    //BUT if it is not empty 
    //NewNode(4)
    //1->2->3->NULL
    //H     T
    // 3's pointer will point at the newly created node instead of null AND then the tail will point at the last element(newly added one)
    //1->2->3->4->NULL
    //H        T
    else{
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

template<class T>
T LinkedList<T>::At(int pos){
    assert(pos >= 0 && pos < length);
    //Loop through the whole list and when pos is found return the value of the node  
    Node<T>* temp = head;
    for(int i=0;i < length;i++){
        if(i == pos)
            return temp->val;
        temp = temp->next;
    }
}

//bool isEmpty();
template<class T>
void LinkedList<T>::InsertAt(T val,int pos){
    assert(pos >= 0 && pos < length);
  
    Node<T>* newNode = new Node<T>(val); //n = newNode
    if(pos == 0){
        newNode->next = head;
        head = newNode;
        length++;
        return;
    }
    Node<T>* temp = head;//t = temp .. T = Tail
    //Loop through the whole list UNTIL you find the position BEFORE you pos(in order to fix its pointer to point at newNode)
    for(int i=0;i<pos-1;i++){
        temp = temp->next; 
    }
    //InsertAt(3,2)
  
    //  tmp
    //1->2->4->5->NULL
    //H       T
    //1->2->4->5->NULL
    //    (3)
    newNode->next = temp->next;
    //H  t     T
    //1->2->4->5->NULL;
    //    3-| 
    //now we need the temp's pointer to point at the new node
    temp->next = newNode;
    //1->2->4->5->NULL;
    //   |-3-|
    //or just 1->2->3->4->5->NULL
    //        H  t  n     T
    length++;
}

template<class T>
void LinkedList<T>::DeleteAt(int pos){
     assert(pos >= 0 && pos < length);
     Node<T>* temp = head;
     if(pos == 0){
        head = head->next;
        delete temp;
        length--;
        return;
     }
     //Loop through the whole list until you find the position BEFORE you want
     for(int i=0;i<pos-1;i++){
          if(i == pos) 
              break;
          temp = temp->next; 
     }
     //DeleteAt(2)
  
     //1->2->4->3->NULL
     Node<T>* toBeDeleted = temp->next;//TBD = toBeDeleted
  
     //     TBD
     //1->2->4->3->NULL
     //H  t     T
     temp->next = toBeDeleted->next;
     //1->4->3->NULL
     //H     T
      
      //IN CASE THE NODE WE WANT TO BE DELETED (toBeDeleted) is the last one we need to point the tail at the node before it
      if(pos == length)
          tail = temp;
      delete toBeDeleted;
      toBeDeleted = NULL;
      length--;
}

template<class T>
void LinkedList<T>::Display(){
    Node<T>* temp = head;
    for(int i=0;i<length;i++){
      cout << temp->val << " ";  
      temp = temp->next;
    }
    cout << endl;
}

template<class T>
LinkedList<T>::~LinkedList(){
   //keep deleting the first element until there are no elements left
   while(length){
      DeleteAt(0); 
   }
}
