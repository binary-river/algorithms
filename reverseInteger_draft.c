/*
 * Function Description
 * : Revese given integer x
 *  example 1
 *  : input  = 123
 *  : output = 321
 *
 *  example 2
 *  : input  = -291
 *  : output = -192
 *
 *  example 3
 *  : input  = 0
 *  : output = 0
 *
 *  constraint 
 *  : Make sure function works in 32-bit system without overflow.
 *
 *  Post script
 *  : This function works by converting interger to string, string to integer.
 *    code is longer than the code using % and / algorithms, but it's easy to imagine
 *    Faster algorithm(using % and / ) is in reverseInteger.c
 */

int reverse(int x){
    
    // Integer range in 32-bit system :  -2147483648  ~  2147483647
    char lsItoA [12];
    int  liItoASz = 0;
    memset(lsItoA, 0x00, sizeof(lsItoA));
    
    // convert to string
    if( x >= 0 )
    {
        lsItoA[0] = ' ';
        sprintf(&lsItoA[1], "%d", x);  
    }
    else
    {
        sprintf(lsItoA, "%d", x);
    }
    
    // get size of lsItoA
    while(lsItoA[liItoASz] != 0x00 ) liItoASz++;
    
    //reverse string
    char lsRev [12];
    int  liRevSz = 1;
    memset(lsRev,0x00, sizeof(lsRev));
    
    lsRev[0] = lsItoA[0];
    for(int i=liItoASz-1; i>=1; i--)
    {
        lsRev[liRevSz++] = lsItoA[i];
    }
    
    
    //check if reversed value is over 32bit unsigned integer maximum.
    if( (x >= 0 && liItoASz == 11 && memcmp(&lsRev[1], "2147483647", 10 ) > 0)
        ||
        (x < 0 && liItoASz == 11 && memcmp(&lsRev[1], "2147483648", 10 ) > 0 )
    )
    {
       return 0;   
    }
    else
    {
        return atoi(lsRev);
    }
    
}


