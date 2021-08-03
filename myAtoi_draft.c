/* Function Description
 * : The algorithm for myAtoi(string s) is as follows:

    1.Read in and ignore any leading whitespace.
    2.Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
    3.Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
    4.Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
    5.If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 2^31 - 1 should be clamped to 2^31 - 1.
    6.Return the integer as the final result.
*/

int myAtoi(char * s){
    
    int  liNumsSz = 0;
    char lsNums [200+1];
    memset(lsNums, 0x00, sizeof(lsNums));
    
    int  liSLen = 0;
    int  liPlusMinus = 0;
    int  liNStrtYn = 0;
    liSLen = strlen(s);
    for(int i=0; i<liSLen; i++)
    {   
        /* ignore leading white space */
        if( lsNums[0] == 0x00 && s[i] == ' ' && liNStrtYn == 0 ) continue;
        
        /* get sign */
        if( lsNums[0] == 0x00 && liPlusMinus == 0 && liNStrtYn == 0 )
        {
            if( s[i] == '+' )
            {
                liPlusMinus = 1;
                liNStrtYn = 1;
                continue;
            }
            else if( s[i] == '-' )
            {
                liPlusMinus = -1;
                liNStrtYn = 1;
                continue;
            }
        }
        
        /* ignore leading 0 */
        if( lsNums[0] == 0x00 && s[i] == '0' )
        {
            liNStrtYn = 1;
            continue;
        }
        
        if( s[i] >= 0x30 && s[i] <= 0x39 )
        {
            lsNums[liNumsSz++] = s[i];
            liNStrtYn = 1;
        }
        else
        {
            break;
        }
    }
    
    if( liNumsSz == 0 ) return 0;
    
    if( liPlusMinus == 0 ) liPlusMinus = 1;
    
    /* compare value to max int, min int */
    if( liNumsSz > 10 )
    {
        if( liPlusMinus == 1 )
        {
            return INT_MAX;
        }
        else
        {
            return INT_MIN;
        }
    }
    
    /* compare value to max int, min int 2 */
    if( liNumsSz == 10 )
    {
        if( liPlusMinus == 1 && memcmp( lsNums, "2147483647", 10 ) >= 0 )
        {
            return INT_MAX;
        }
        
        if( liPlusMinus == -1 && memcmp( lsNums, "2147483648", 10 ) >= 0 )
        {
            return INT_MIN;
        }
    }
    
    int liRslt = 0;
    for(int i=0; i<liNumsSz; i++)
    {
        liRslt = liRslt * 10;
        liRslt += (int)lsNums[i] - 48;
    }
    
    return liRslt*liPlusMinus;
}

