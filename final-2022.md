# 1st Question: 
## 1.One
---
## 2.False
---
## 3.False
---
## 4.None 
  ### Front() --> returns front in O(1)
  ### Enqueue() --> enqueues at the back of the queue in O(1)
  ### Empty() ---> Checks if length == 0 in O(1) "or checks if front is null"
---
## 5.Avoid wasting memory
---
## 6.O(n) 
 ### IF The head is constant at the beginning and we are pushing every time at the back WITHOUT having a back pointer
---
## 7.False
---
## 8.False
---
## 9. 3 fields
 ### Value , Pointer to next , Pointer to previous
---
## 10. O(n)
---
## 11. Collision
## 12. O(1)
## 13. A and B (map , set STLs are implemented as Red-Black Trees(a type of balanced Binary Search Trees)
## 14. False
## 15. All of the above
---
---
# 2nd Question: 
## A)
### i. Queue
### ii.Doubly Linked List (Or Deque)
### iii.Stack (Maybe Linked List too ?)
### iv. BST
---
## B)
### i.Not balanced
### ii.Yes BST
### iii. [12 ,14, 9, 19, 23, 17, 67, 72, 54, 76, 50] ... PostOrder : Left , Right , Root
### iv. Minimum Right(54) OR Maximum Left(23)
---
---
# 3rd Question: 
 ```cpp
 #include <iostream>
template<class T>
class Node{
public:
   T val;
   Node<T>* next;
   Node<T>* previous;
   Node(T val){
      this->val = val;
   	next = previous = NULL;
   }
};

template<class T>
class Deque{
  Node<T>* head;
  Node<T>* tail;
  int length;
public:
  Deque(){
  	head = tail = NULL;
   length = 0;
  }
  void pushBack(T val){
  	Node<T>* newNode = new Node<T>(val);
  	if(head == NULL)
  	   head = tail = newNode;
  	else{
  	   tail->next = newNode;
  	   newNode->previous = tail;
  	   tail = newNode;
  	}
   length++;
  }
  void pushFront(T val){
  	Node<T>* newNode = new Node<T>(val);
  	if(head == NULL)
  	   head = tail = newNode;
  	else{
  	   newNode->next = head;
  	   head->previous = newNode;
  	   head = newNode;
  	}
   length++;
  }
  void popBack(){
  	Node<T>* toBeDeleted = tail;
  	if(head != tail){
  		(tail->previous)->next = NULL;
      tail = tail->previous;
   }
   else
      head = tail = NULL;
  	delete toBeDeleted;
  	toBeDeleted = NULL;
   length--;
  }
  void moveToFront(int pos){
    if(pos == 0 || pos >= length) return;
    //assuming 0-based 
    int i=0;
    Node<T>* temp = head;
    while(i != pos){
      temp = temp->next;
      i++;
    }
    (temp->previous)->next = (temp->next);
    if(temp != tail)
      (temp->next)->previous = (temp->previous);
    
    temp->next = head;
    head->previous = temp;
    
    head = temp;
  }
  void display(){
    Node<T>* temp = head;
    while(temp){
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
  }
};
```
---
## NOTE: TO BE UPDATED 
# 4th Question
```cpp
unordered_map<int,int>amazon; //frequency array
//map ---> sorted by key
//key   : id
//value : number of times product has been sold 
//prod : 5
//amazon[prod] = 0 + 1 = 1
//prod : 5
//amazon[prod] = 1 + 1 = 2

void add_transaction(string customer_name,int product_id){
   amazon[product_id]++;
}

int get_product_sales_count(int product_id){
    return amazon[product_id];
}

bool comparator(pair<int,int>& a,pair<int,int>& b){
	return a.second > b.second;
}

void print_top_product_ids(){
   if(amazon.size() < 5) return;
   vector<pair<int,int>>temp;//pair {key:value} , {id:count}
   unordered_map<int,int>::iterator iter = amazon.begin();
   while(iter != amazon.end()){
   	temp.push_back(iter);
   	iter++;
   }
   sort(temp.begin(),temp.end(),comparator);//sort by count
   for(int i=0;i<5;i++){
   	cout << temp[i].first << " ";
   }
   cout << endl;
}

------------------------------------------------------------
//credits to Mohab Ashraf and Bahnas
map<int, int> amazon;
set<pair<int, int>> st;//sorted in increasing order
-10 -9 -8

void add_transaction(string customer_name, int product_id) {
    if (st.find({-amazon[product_id], product_id}) != st.end())
        st.erase({-amazon[product_id], product_id});
    amazon[product_id]++;
    st.insert({-amazon[product_id], product_id});//log n
}

int get_product_sales_count(int product_id) {
    return amazon[product_id];
}

void print_top_product_ids() {
    int cnt = 0;
    for (auto &item: st) {
        if (cnt++ == 5)
            break;
        cout << item.second << "\n";
    }

}
```

  
