int palindromeValidator(char *sOri )
{
    int sOriLen = strlen(sOri);
    
    for(int i=0; i< sOriLen/2; i++)
    {
       if( sOri[i] != sOri[sOriLen-i] )
       {
          return 1;
       }
    }
    
    return 0;
}

/* 
 * 1 <= s.length <= 1000 
 * s consist of only digits and English letters (lower/upper)
 */
char * longestPalindrome(char * s)
{
    int sLen = strlen(s);
    
    int iLgstPalLen = 1;
    int iLgstPalStrtIdx = 0;
 
    char lsCmpStr[1000+1];
    memset(lsCmpStr, 0x00, sizeof(lsCmpStr));
    
    for(int i=0; i<sLen; i++)
    {
        for(int j=sLen-1; j>i; j--)
        {
            if( s[i] == s[j] )
            {
                memset(lsCmpStr, 0x00, sizeof(lsCmpStr));
                memcpy(lsCmpStr, &s[i], j-i+1);
                
                if( palindromeValidator(lsCmpStr) == 0 )
                {
                    if( iLgstPalLen < j-i+1 )
                    {
                        iLgstPalLen = j-i+1;
                        iLgstPalStrtIdx = i; 
                        break;
                    }

                }
            }
        }
        
        if( sLen -i-1 <= iLgstPalLen ) break;
    }
    
    char *sRslt = malloc( sizeof(char) * (iLgstPalLen+1) );
    memset(sRslt, 0x00, iLgstPalLen+1);
    
    memcpy(sRslt, &s[iLgstPalStrtIdx], iLgstPalLen );
    
    return sRslt;
}
