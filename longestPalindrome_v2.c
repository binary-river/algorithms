/*
 * Function Description 
 * : Find longest palindromic substring in given string
 * 
 * example 1
 * input  : abcddca
 * output : cddc
 *
 * example 2
 * input  : ab
 * output : a
 *
 * constraint 
 * 1 <= s.length <= 1000 
 * s consist of only digits and English letter(upper/lower)
 */

/* Return longest palindromic substring
 * How it works.
 * 1. Start from 0 index of given s
 * 2. set start and end point for checking palindrome
 *    if next index character is same with current index character, then plus index and end point.
 * 3. minus start point and plus end point. then check both characters are same. 
 *
 * postscript
 * : This alogorithm is less intuitive, less easy to comprehend than longestPlaindrome.c
 *   But it's one of the fastest alogorithm finding palindromic substring. 
 */

ichar * longestPalindrome(char * s)
{
    int liLgstL = 1; // length of longest palindromic substring
    int liLgstS = 0; // start index of longest palindromic substring
    int liLgstE = 0; // end index of longest palindromic substring
    
    int liSLen = strlen(s);

    /* if length of palindromic substring is even number
       then there should be at least one couple of same character 
     */
    for(int i=0; i<liSLen; i++)
    {
        int iSt = i; /* start */
        int iEd = i; /* end   */
        
        /* Check same following characters */
        while( s[i] == s[i+1] && i+1 < liSLen )
        {
            i++;
            iEd++;
        }
        
        /* Check palindromic using iSt and iEd */
        while( iSt-1 >= 0 && iEd+1 < liSLen )
        {
            if( s[iSt-1] == s[iEd+1] )
            {
                iSt--;
                iEd++;
            }
        }
        
        /* Compare longer */
        if( iEd - iSt +1 > liLgstL )
        {
            liLgstL = iEd - iSt +1;
            liLgstS = iSt;
            liLgstE = iEd;
        }
    }
    
    char *lsRslt = malloc(liLgstL + 1);
    memcpy(lsRslt, &s[liLgstS], liLgstL);
    lsRslt[liLgstL] = 0x00;
    
    return lsRslt;
}

