
/*
 * Function Description
 * : Find the length of the longest substring without repeating characters from s( character array )
 * example 1
 *  input: s = "abcabcbb"
 *  output : 3 ( abc is the longest substring in given string s )
 *
 * example 2
 *  input: s = "abcdefbg"
 *  output : 6 ( cdefbg is the longest substring in given string s )
 *
 */

int lengthOfLongestSubstring(char * s)
{
    
    /* Longest string length */
    int liLgstLen = 0;
    
    /* On process string information */
    int liPrgrLen = 0;
    int liPrgrStrtIdx = 0;
    int liPrgrEndIdx = 0;
    
    
    /* interate. Length of string will be under 50000 */
    for(int i=0; i< 50000; i++)
    {
        /* facing null */
        if( *(s+i) == 0x00 )
        {
            return liLgstLen;
        }
        
        /* first loop, not null, set 1 */
        if( i == 0 )
        {
            liPrgrLen = 1;
            liPrgrStrtIdx = 0;
            liPrgrEndIdx = 0;
            
            liLgstLen = liPrgrLen;
            continue;
        }
        
        
        /* search current(i) character in on process string */
        int liPrgrCharMatchedIdx = -1;
        for( int j=liPrgrStrtIdx; j<=liPrgrEndIdx; j++ )
        {
            if( *(s+j) == *(s+i) )
            {
                /* get last index of matched char in on process string */
                liPrgrCharMatchedIdx = j; 
            }
        }
        
        /* not found, add 1 to on process information */
        if( liPrgrCharMatchedIdx == -1 )
        {
            liPrgrLen++;
            liPrgrEndIdx++;
        }
        /* found, change on process information */
        else
        {
            liPrgrLen = i - liPrgrCharMatchedIdx;
            liPrgrStrtIdx = liPrgrCharMatchedIdx +1;
            liPrgrEndIdx = i;
        }
        
        
        if( liPrgrLen > liLgstLen )
        {
            liLgstLen = liPrgrLen;
        }
    }
      
    return liLgstLen;
}

