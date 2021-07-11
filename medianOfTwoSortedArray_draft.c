

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    
    double liRslt = 0;
    int liMergedOrigin [2000];
    
    int *liMergedNums;
    int liMergedLength = 0;
    
    memset(liMergedOrigin, 0x00, sizeof(liMergedOrigin));
    
    if( nums1Size == 0 && nums2Size == 0 )
    {
        return 0;
    }
    else if( nums1Size == 0 )
    {
        liMergedNums = nums2;
        liMergedLength = nums2Size;
    }
    else if( nums2Size == 0 )
    {
        liMergedNums = nums1;
        liMergedLength = nums1Size;
    }
    else
    {
        int i =0; // index of nums1
        int j =0; // index of nums2
        int k =0; // index of merged
        int liNums1EndYn = 0;
        int liNums2EndYn = 0;
        while(1)
        {   
            //nums1 [1,3]
            //nums2 [2]
            int liNum1=0;
            int liNum2=0;
            
            if( i >= nums1Size && j >= nums2Size )
            {
                break;
            }
            
            if( i >= nums1Size )
            {
                liNum1 = 999999;
            }
            else
            {
                liNum1 = nums1[i];
            }
            
            if( j >= nums2Size )
            {
                liNum2 = 999999;
            }
            else
            {
                liNum2 = nums2[j];
            }
            
            if( liNum1 == liNum2 )
            {
                liMergedOrigin[k++] = liNum1;
                liMergedOrigin[k++] = liNum2;
                i++;
                j++;
            }
            else if( liNum1 > liNum2 )
            {
                liMergedOrigin[k++] = liNum2;
                j++;
            }
            else
            {
                liMergedOrigin[k++] = liNum1;
                i++;
            }
            
        }
        
        liMergedNums = liMergedOrigin;
        liMergedLength = k;
    }
    
    int liMiddleIdx = 0;
    liMiddleIdx = liMergedLength / 2;
    if( liMiddleIdx * 2 == liMergedLength )
    {
        liRslt = ( liMergedNums[liMiddleIdx-1] + liMergedNums[liMiddleIdx] ) / 2.0;
    }
    else
    {
        liRslt = liMergedNums[liMiddleIdx];
    }
    
    return liRslt;
}

