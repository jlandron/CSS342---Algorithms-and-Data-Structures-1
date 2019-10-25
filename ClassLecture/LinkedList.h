#ifndef _LLIST_CPP_
#define _LLIST_CPP_

#include <iostream>

using namespace std;

template<class Object>
struct LListNode{
    Object item;
    LListNode *next;
};

template<class Object>
class LList{
public:
    LList<Object>::LList(){
        LListNode *header = new LListNode;
        header->next = NULL;
    }
    LList(const LList &rhs);
    ~LList();

    bool isEmpty() const;
    void clear();
    void insert(const Object &x, int index);
    int find(const Object &x);
    const LList &operator=(const LList &rhs); //copy list

private:
    LListNode<Object> *head;

    LListNode<Object> *findByIndex(int index) const;    
    LListNode<Object> *findPrevious(int Object &x) const;   
};

#endif
//Task, Job, Process are all terms for programs in execution, dynamic or active programs
