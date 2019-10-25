template<class Object>
int MtfList<Object>::find( const Object &obj ) {
  DListNode<Object> *top = DList<Object>::header->next;
  DListNode<Object> *found = top;

  int i = 0;
  for ( ; found != NULL && found->item != obj;  found = found->next, i++ )
    ++DList<Object>::cost;
  
  if ( found == NULL )
    return -1; // not found

  if ( found == top )
    return 0;  // no need to move to front     
  //remove found from current position

  found->prev->next = found->next;
  if(found->next != NULL){
    found->next->prev = found->prev;
  }
  //place found between header and top
  found->next = top;
  top->prev = found;
  found->prev = DList<Object>::header;
  DList<Object>::header->next = found;
  top->prev = found;
  return i;
}
