/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * Function that add two numbers consisted of linked list
 * Assume that all allocated memory will be free by caller
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
  
    /* The number of nodes in each linked list is in the range 1-100
       val in ListNode is in the range 1-9
    */
    
    /* Adding two numbers of linked list is very simillar with a way we normally sum two numbers 
       Start from units to higher. 
       When place value after adding is higher than 9, use carry 
    */
    
    /* Declare struct pointers will be used in loop */
    struct ListNode* ltNext1=l1;
    struct ListNode* ltNext2=l2;
    struct ListNode* ltRslt = malloc(sizeof(struct ListNode)); // pointer for return
    struct ListNode* ltPrev; // previous node for setting next pointer
    
    memset(ltRslt, 0x00, sizeof(struct ListNode));
    
    /* Declare variables will be used in loop */
    int liCnt = 0;
    int liCarry = 0; // carry for sum
    int liVal1 = 0; // l1's node value
    int liVal2 = 0; // l2's node value
    int liSum = 0;  // sum of each node's value for result
    
    while(liCnt < 100 )  // max node will be 100 
    {
        if( ltNext1 == 0x00 && ltNext2 == 0x00 && liCarry == 0 )
        {
            /* break if all nodes are null and there's no carry to sum */
            break;
        }
        
        liVal1 = 0;
        if( ltNext1 != 0x00 )
        {
            /* set list1 node's value and change ltNext1 for next loop */
            liVal1 = ltNext1->val;
            ltNext1 = ltNext1->next;
        }
        
        liVal2 = 0;
        if( ltNext2 != 0x00 )
        {
            /* set list2 node's value and change ltNext2 for next loop */
            liVal2 = ltNext2->val;
            ltNext2 = ltNext2->next;
        }
        
        liSum = liVal1 + liVal2 + liCarry;
        liCarry = 0; // set carry to 0 after using it
        if( liSum > 9 )
        {
            liSum = liSum - 10;
            liCarry = 1;
        }
        
        /* create node for result */
        if( liCnt == 0 )
        {
            ltRslt->val = liSum;
            ltPrev = ltRslt;
        }
        else
        {
            struct ListNode* ltTemp = malloc(sizeof(struct ListNode));
            memset(ltTemp, 0x00, sizeof(struct ListNode));
            
            ltPrev->next = ltTemp;
            ltTemp->val = liSum;
            
            ltPrev = ltTemp;
        }
        
        liCnt++;
    }
    
    return ltRslt;
    
}
