/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if(position==0)
    {
        llist = llist->next;
        return llist;
    }
    
    SinglyLinkedListNode* temp1 = llist;
    SinglyLinkedListNode* temp2 = llist->next;
    
    
    
    for(int i = 1; i<position;++i)
    {
        if(temp2->next!=nullptr)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {
            return nullptr;
        }
    }
    
   
    
    temp1->next=temp2->next;
    
    delete[] temp2;
    
    
    return llist;
}