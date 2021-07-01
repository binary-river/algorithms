/*
 * Two Sum algorithms. 
 * Given an pointer of integers array and array size. 
 * Return indices of two numbers that add up to 'target'
 * Any two number that add up to 'target' would be okay even though there's many combination that add up to 'target'
 *
 */

/*
 * Brute force function
 * Assume that malloced pointer will be free() by caller
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
  
  int li_index[2];
  memset(&li_index, 0x00, sizeof(li_index));
    
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize; j++)
        {
           if( *(nums+i) + *(nums+j) == target )
           {
               li_index[0]=i;
               li_index[1]=j;
               break;
           }
        }
    }
    
    
    int* ii_return=malloc(sizeof(int)*2);
    
    *ii_return = li_index[0];
    *(ii_return+1) = li_index[1];
    
    *returnSize = 2;
    
    return ii_return;
}

