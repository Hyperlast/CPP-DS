/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    
    SinglyLinkedListNode* Previous = llist;
    SinglyLinkedListNode* Current = llist->next;
    SinglyLinkedListNode* Node = new SinglyLinkedListNode(data);
    if(position == 1)
    {
        Node->next = Previous;
        llist = Node;
    }
    
    for(int i=1;i<position;++i)
    {
        if(Current->next != nullptr)
        {
            Previous = Previous->next;
            Current = Current->next;
        }
        else{
            return nullptr;
        }
    } 
        Previous->next = Node;
        Node->next=Current;    
    
    return llist;
    
}