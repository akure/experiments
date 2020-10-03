#include <stdlib.h>
#include <stdio.h>

int gi = 2;
static int * gptr_j; 
//const int * const gptr_j = (const int * ) malloc( sizeof(int) );
// *gptr_j = 4;

void fun(int * iptr)
{ 
   printf("------fun------\n");
   printf("fun : &iptr = %p \n", &iptr);  
   printf("fun : iptr = %p \n", iptr);  
   iptr = &gi;	
   printf("fun : after assignment, iptr = %p \n", iptr);  
   printf("Exiting fun------\n");
}

void gun(int ** iptrptr)
{
    printf("------gun------\n");
    printf("gun : &iptrptr = %p \n", &iptrptr);  
    printf("gun : iptrptr = %p \n", iptrptr);  // address passed in is captured by iptrptr 
    printf("gun : *iptrptr = %p \n", *iptrptr); // nil 
    // printf("gun : **iptrptr = %d \n", **iptrptr);  // seg fault
 	*iptrptr = gptr_j; 
    printf("gun : gptr_j = %p \n", gptr_j);
    printf("gun : after assignment. \n");
    printf("gun : &iptrptr = %p \n", &iptrptr);  
    printf("gun : iptrptr = %p \n", iptrptr);  //  
    printf("gun : *iptrptr = %p \n", *iptrptr); //  
    printf("gun : **iptrptr = %d \n", **iptrptr);  
    printf("Exiting gun------\n");
}

int main()
{

	gptr_j = (int * ) malloc( sizeof(int) );
	printf(" gi = %d, &gi = %p \n", gi, &gi);	
	printf(" *gptr_j = %d, gptr_j = %p\n ", *gptr_j, gptr_j);	
	    
	int *ptr1 = NULL;
   	printf(" &ptr1 = %p \n", &ptr1);  
   	printf(" ptr1 = %p \n", ptr1);  
   	// printf(" *ptr1 = %p \n", *ptr1);  // seg fault
    // fun(ptr1);
   	// printf(" &ptr1 = %p \n", &ptr1);  
   	// printf(" ptr1 = %p \n", ptr1); // nil 
   	// printf(" *ptr1 = %d \n", *ptr1);  // seg fault 

	//printf("after fun: &ptr = %p ,  *ptr1 = %d, ptr1 = %p \n", &ptr1, *ptr1, ptr1);	
	
	gun(&ptr1);
   	printf(" &ptr1 = %p \n", &ptr1);  
   	printf(" ptr1 = %p \n", ptr1);  
   	printf(" *ptr1 = %d \n", *ptr1);  // seg fault
   
	
	return 0;
}
