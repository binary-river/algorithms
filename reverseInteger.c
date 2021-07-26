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
 *  : This function is shorter and slightly faster than the code converting integer to string 
 *    and string to integer.
 *    
 */
int reverse(int x){
    // Integer range -2147483648  ~  2147483647
    int liIntA = INT_MAX/10;
    int liRest = x;
    int liRev = 0;
    
    while(liRest != 0)
    {   
	// compare if reverse integer is bigger than maximun integer size in 32-bit system
        if( abs(liRev) > liIntA ) return 0;
        if( liRev == liIntA && liRest % 10 > 7 ) return 0;
        if( liRev == liIntA*-1 && liRest % 10 < -8 ) return 0;            

        liRev = liRev * 10;
        liRev += liRest % 10;
        liRest = liRest/10;
    }
    
    return liRev;
}




