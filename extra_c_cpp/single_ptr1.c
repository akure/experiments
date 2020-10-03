#include <stdlib.h>
#include <stdio.h>

int gi = 2;
int * gptr_j; 
//const int * const gptr_j = (const int * ) malloc( sizeof(int) );
// *gptr_j = 4;

void fun(int * iptr)
{ 
   printf("------fun------\n");
   printf("fun : &iptr = %p \n", &iptr);  
   printf("fun : iptr = %p \n", iptr);  
   iptr = &gi;	// Will not reflect outside of this function
   printf("fun : after assignment, iptr = %p \n", iptr);  
   printf("Exiting fun------\n");
}


int main()
{

	int * gptr_j = (int * ) malloc( sizeof(int) );
	printf(" gi = %d, &gi = %p \n", gi, &gi);	
	printf(" *gptr_j = %d, gptr_j = %p\n ", *gptr_j, gptr_j);	
	    
	int *ptr1 = NULL;
   	printf(" &ptr1 = %p \n", &ptr1);  
   	printf(" ptr1 = %p \n", ptr1);  
   	// printf(" *ptr1 = %p \n", *ptr1);  // seg fault
    fun(ptr1);
   	printf(" &ptr1 = %p \n", &ptr1);  
   	printf(" ptr1 = %p \n", ptr1); // nil 
   	// printf(" *ptr1 = %d \n", *ptr1);  // seg fault 

   
	
	return 0;
}
