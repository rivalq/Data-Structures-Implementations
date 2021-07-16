#include<bits/stdc++.h>



template<typename T>
class node{
public:        
	T val;
	node<T>* left;
	node<T>* right; 
        node(T val):val(val){}
};


template<typename T>
node<T>* create(T val){
	node<T>* temp = new node<T>(val);
	temp->left = NULL;
	temp->right = NULL;
        return temp;
}

template<typename T>
class deque{
     node<T>* root = NULL;
     int sz = 0;

public:
     deque(){

     }

     int size(){
     	return sz;
     } 
     bool empty(){
     	return sz == 0;
     }
     //root itself will be front
     // root->right will be back
     void push_back(T val){
     	 if(root == NULL){
     	 	root = create(val);
     	 	root->left = root;
     	 	root->right = root;
     	 	sz++;
     	 	return;
     	 }
     	 node<T>* temp = create(val);
     	 temp->left = root;
         root->right->left = temp;
         temp->right = root->right;
         root->right = temp;
         sz++;
         return; 
     }
     void push_front(T val){
     	 if(root == NULL){
     	 	root = create(val);
     	 	root->left = root;
     	 	root->right = root;
     	 	sz++;
     	 	return;
     	 }
     	 node<T>* temp = create(val);
     	 root->right->left = temp;
     	 temp->right = root->right;
     	 root->right = temp;
     	 temp->left = root;
     	 root = temp;
     	 sz++;
     	 return;
     }
     void pop_back(){
     	 node<T>* temp = root->right;
     	 root->right->right->left = root;
     	 root->right = root->right->right;
     	 delete(temp);
     	 sz--;
     	 return; 
     }
     void pop_front(){
     	  node<T>* temp = root;
     	  root->left->right = root->right;
     	  root->right->left = root->left;
     	  root = root->left;
     	  delete(temp);
     	  sz--;
     	  return;
     } 
     T front(){
     	 return root->val;
     }
     T back(){
         return root->right->val;
     }
};


int main(){


        deque<int> dq;

}
