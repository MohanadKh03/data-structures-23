#include "BST.h"

template<class T>
BST<T>::BST(){
    root = nullptr;
}

template<class T>
void BST<T>::Insert(T val){
    if(Contains(val))
        return;
    Node<T>* temp = root;
    Node<T>* NewNode = new Node<T>(val);
    if(!root){
        root = NewNode;
        return;
    }
    //go right and skip the left subtree OR go left and skip the right subtree
    //until you find a null place , that is where the node should be inserted at
    while(temp){
        if(val > temp->val){
            if(temp->right)
                temp = temp->right;
            else{
                temp->right = NewNode;
                break;
            }
        }
        if(val < temp->val){
            if(temp->left)
                temp = temp->left;
            else{
                temp->left = NewNode;
                break;
            }
        }
    }
}

template<class T>
Node<T>* BST<T>::Find(T val){
    Node<T>* temp = root;
    //keep skipping left/right subtree until you find the node .. if not found then return null
    while(temp){
        if(val == temp->val)
            return temp;
        if(val > temp->val)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return temp;
}

template<class T>
bool BST<T>::Contains(T val){
    return Find(val) != nullptr;
}

template<class T>
Node<T>* BST<T>::findMin(Node<T>* root){
    Node<T>* temp = root;
    //Go as left as possible to find the minimum element 
    while(temp->left){
        temp = temp->left;
    }
    return temp;
}


template <class T>
void BST<T>::Remove(T val)
{
	assert(Contains(val));

	Node<T>* n = Find(val);

	if ((n->left == NULL) && (n->right == NULL)) //deleting a leaf node
	{
		if (n == root)
		{
			root = NULL;
		}
		else
		{
			Node<T>* parent = findParent(val);
			if (val < parent->val)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		delete n;
	}
	else if ((n->left == NULL) && (n->right != NULL))
	{
		Node<T>* parent = findParent(val);
		if (n == root)
		{
			root = n->right;
		}
		else
		{
			if (val < parent->val)
				parent->left = n->right;
			else
				parent->right = n->right;
		}
		delete n;
	}
	else if ((n->left != NULL) && (n->right == NULL))
	{
		Node<T>* parent = findParent(val);
		if (n == root)
			root = n->left;
		else
		{
			if (val < parent->val)
				parent->left = n->left;
			else
				parent->right = n->left;
		}
		delete n;
	}
	else
	{
		Node<T>* minNode = findMin(n->right);
		Node<T>* parent = findParent(minNode->val);

		n->val = minNode->val;

		if (parent == n)
			parent->right = minNode->right;
		else
			parent->left = minNode->right;

		delete minNode;
	}
}

//in Remove function , We MUST change the parent too

/*
template<class T>
void BST<T>::Remove(T val){
    Node<T>* nodeFound = Find(val);
    if(!nodeFound)
        return;
    //two children
    //Get the minimum node in the GREATER SIDE(right side)
    //then remove that minimum node(which will be a leaf node)
    //and get the val of the minRightNode replace it with the node to be deleted
    if(nodeFound->left && nodeFound->right){
        Node<T>* MinR = findMin(nodeFound->right);
        T temp = MinR->val;
        Remove(MinR->val);
        nodeFound->val = temp;
    }
    else{
        //leaf node
        //If it's a leaf node then just delete it
        if(!nodeFound->left && !nodeFound->right){
            cout << nodeFound << endl;
            delete nodeFound;
            nodeFound = NULL;
            cout << "here\n";
        }
        //If the toBeDeleted node has one child .. replace the node's val with the child(left/right) 
        //and then delete the child which should be a leaf node 
        //left
        else if(nodeFound->left){
            nodeFound->val = nodeFound->left->val;
            delete nodeFound->left;
            nodeFound->left = NULL;
        }
        //right
        else{
            nodeFound->val = nodeFound->right->val;
            delete nodeFound->right;
            nodeFound->right = NULL;
        }
    }
}
*/

template <class T>
Node<T>* BST<T>::findParent(T val)
{
	Node<T>* b =  NULL;
	Node<T>* a = root;

	while (a != NULL)
	{
		if (a->val == val)
		{
			break;
		}

		b = a;
		if (a->val > val)
		{
			a = a->left;
		}
		else
		{
			a = a->right;
		}
	}

	return b;
}

template<class T>
void BST<T>::Traverse(int traversalWay){
    if(traversalWay == 1)
        InOrder(root);
    if(traversalWay == 2)
        PreOrder(root);
    if(traversalWay == 3)
        PostOrder(root);
    cout << "\n";
}

template<class T>
void BST<T>::InOrder(Node<T>* root){
    //base case
    if(root == NULL)
        return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}

template<class T>
void BST<T>::PreOrder(Node<T>* root){
    if(root == NULL)
        return;
    cout << root->val << " ";
    InOrder(root->left);
    InOrder(root->right);
}

template<class T>
void BST<T>::PostOrder(Node<T>* root){
    if(root == NULL)
        return;
    InOrder(root->left);
    InOrder(root->right);
    cout << root->val << " ";
}


template<class T>
void BST<T>::deleteAll(Node<T>* root){
    if(!root)
        return;
    deleteAll(root->left);
    deleteAll(root->right);
    delete root;
    root = nullptr;
}

template<class T>
BST<T>::~BST(){
    deleteAll(root);
}
