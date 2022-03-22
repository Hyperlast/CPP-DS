// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    SinglyLinkedListNode* temp1 = head1;
    SinglyLinkedListNode* temp2 = head2;
    while(temp1)
    {
        while(temp2)
        {
            if(&temp1->next == &temp2->next)
            {
                return temp1->data;
            }
            temp2 = temp2->next;
        }
        temp2 = head2;
        temp1 = temp1->next;
    }

    return temp1->data;
}