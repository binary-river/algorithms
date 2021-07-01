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
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{  
  int* ii_index = malloc(sizeof(int)*2);
  *returnSize = 2;
    
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=i+1;j<numsSize; j++)
        {
           if( *(nums+i) + *(nums+j) == target )
           {
               ii_index[0]=i;
               ii_index[1]=j;
               break;
           }
        }
    }

    return ii_index;
}
