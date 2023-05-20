# vector (C++ implementation of ArrayList)
  ### -Insertions: O(n)
  ### -Deletions: O(n)
  ### -Accessing an index by random access: O(1)
  ---
# list (C++ implementation of Doubly LinkedList)
  ### -Append at the beginning/end: O(1)
  ### -Delete at the beginning/end: O(1)
  ### -Insertions/Deletions in the middle: O(n)
  ---
# stack (C++ implementation of Stack obviously)
  ### Push/Pop/Top in O(1) at one end 
  ---
# queue (C++ implementation of Queue .. again obviously)
  ### push/pop in O(1) BUT push from one end at pop at the other end
  ---
# deque (C++ implementation of Deque)
  ### push/pop in O(1) in both ends .. push front/back and pop front/back
  ---
# pair (C++ implementation for a key value element)
 ---
# map (Key/Value set of pairs which uses Red-Black Tree , a balanced Binary Search Tree)
  ### Insertions,Deletions,Searches O(log n)
  ### Its iterator moves Inorder traversal
 ---
# unordered_map (C++ implementation of HashTable - Key/Value pairs)
  ### In case of collisions in hashtables in general it would be O(k) where k is the number of elements in one bucket
  ### But using a good hash function should cause most of the operations *INSTEAD OF REHASHING* (Insert,Delete,Update,Search) be in O(1)
 ---
# set (Stores Keys only which and Red-Black Tree , a balanced Binary Search Tree)
  ### Searching,Insertions,Deletions,Updates all are O(log n)
  ### Its iterator moves Inorder traversal
  
# unordered_set (C++ implementation of HashTable - Key only)
  ### In case of collisions in hashtables in general it would be O(k) where k is the number of elements in one bucket
  ### But using a good hash function should cause most of the operations *INSTEAD OF REHASHING* (Insert,Delete,Update,Search) be in O(1)
