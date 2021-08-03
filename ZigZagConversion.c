
/*
 * Function Description
 * : The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * P A H N
 * APLSIIG
 * Y I R
 * And then read line by line: "PAHNAPLSIIGYIR"
 */


char * convert(char * s, int numRows){
    
    int liLen = strlen(s);
    int liColSz = 1;

    char* lsRslt = malloc( sizeof(char) * (liLen+1) );
    memset(lsRslt, 0x00, sizeof(char) * (liLen+1) );
    
    if( numRows == 1 )
    {
        memcpy(lsRslt, s, liLen);
        lsRslt[liLen] = 0x00;
        return lsRslt;
    }
    
    int liLenT = liLen - numRows;
    int liEven = -1;
    while(liLenT > 0)
    {
        liLenT = liLenT - (numRows-1);
        liEven = liEven * -1;
        
        if( liEven != 1 ) continue;
        liColSz = liColSz + (numRows-1);
    }
    
    char lsRows[numRows][liColSz];
    memset(lsRows, 0x00, sizeof(lsRows));
    int liR = 0;
    int liC = 0;
    int liV = 0;
    
    lsRows[liR][liC] = s[0];
    for(int i=1; i<liLen; i++)
    {
        if( liV == 0 ) liR++;
        if( liV == 1 )
        {
            liR--;
            liC++;
        }
        
        lsRows[liR][liC] = s[i];
            
        if( liR == numRows-1 ) liV = 1;
        if( liR == 0 ) liV = 0;
    }
    
    int liIdx = 0;
    for(int i=0; i<numRows; i++)
    {
        for(int j=0; j<liColSz; j++)
        {
            if( lsRows[i][j] != 0x00 && lsRows[i][j] != 0x20 )
            {
                lsRslt[liIdx++] = lsRows[i][j];
            }
        }
    }
    
    lsRslt[liLen] = 0x00;
    
    return lsRslt;
}

