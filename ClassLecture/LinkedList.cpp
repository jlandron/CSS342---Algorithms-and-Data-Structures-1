#include <iostream>
#include "LinkedList.h"

using namespace std;

template<class Object>
LList<Object>::LList(const LList &rhs){

}
template<class Object>
LList<Object>::~LList(){
    clear();
    delete header;
}
template<class Object>
bool LList<Object>::isEmpty() const{
    if(1){

    }
}
template<class Object>
void LList<Object>::clear(){
    while(!isEmpty()){
        LListNode<Object> *node = findByIndex(1);
        remove(node->item);
    }
}
template<class Object>
void LList<Object>::insert(const Object &x, int index){
    LListNode *newptr = new LListNode;
    newprt->item = x;
}
template<class Object>
int LList<Object>::find(const Object &x){

}
template<class Object>
const LList<Object>::LList &operator=(const LList &rhs){
    if(this != &rhs){
        clear();

        int index;
        LListNode<Object> *rightNode;
        for(index = 0; rightNode = rhs.header->next; rightNode!=NULL; rightNode = rightNode->next, index++){
            insert(rightNode->item, index);
        }
    }
    return *this;
}


LListNode<Object> *head;
template<class Object>
LListNode<Object> *LList<Object>::findByIndex(int index) const{

}  
template<class Object> 
LListNode<Object> *LList<Object>::findPrevious(int Object &x) const{

}  
int main(){

}

//Task, Job, Process are all terms for programs in execution, dynamic or active programs
