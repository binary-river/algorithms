/*
 * return the median of the two sorted arrays ( nums1, nums2 )
 * example 1.
 * nums1 = [1,3], nums2 = [2]
 * return 2
 * 
 * example 2.
 * nums1 = [1,2], nums2 = [3,4]
 * return 2.5
 * 
 * example 3
 * nums1 = [0,0], nums2 = [0,0]
 * return 0
 * 
 * example 4
 * nums1 = [], nums2 = [1]
 * return 1
 * 
 * constraint
 * nums1Size, nums2Size are between 0 and 1000
 * at least one array should have non-zero length.
 * each element in arrays could be a number between -10^6 and 10^6
 */

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
        
    double ldRslt = 0.0;        // return value
    int liMergedSize = 0;     // merged array size
    int liMerging[2000];  // array for merging two sorted arrays
    
    memset(liMerging, 0x00, sizeof(liMerging));
    
    int i=0; // index of nums1
    int j=0; // index of nums2
    int k=0; // index of merged array
    int nums1N = 0; // element of nums1
    int nums2N = 0; // element of nums2
    
    /* all out of index, then break */
    while( i < nums1Size || j < nums2Size )
    {
        /* nums1 out of index, then set 9999999 */
        if( i >= nums1Size )
        {
            nums1N = 9999999;
        }
        else
        {
            nums1N = nums1[i];
        }
        
        if( j >= nums2Size )
        {
            nums2N = 9999999;
        }
        else
        {
            nums2N = nums2[j];
        }
        
        if( nums1N < nums2N )
        {
            liMerging[k++] = nums1N;
            i++;
        }
        else
        {
            liMerging[k++] = nums2N;
            j++;
        }
    }
    
    liMergedSize = k;
    
    int liMidIdx = liMergedSize / 2;
    
    if( liMergedSize % 2 == 0 )
    {
        ldRslt = ( liMerging[liMidIdx-1] + liMerging[liMidIdx] ) / 2.0;
    }
    else
    {
        ldRslt = liMerging[liMidIdx];
    }
    
    return ldRslt;
}

