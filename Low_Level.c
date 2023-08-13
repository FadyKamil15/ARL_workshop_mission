#include <stdlib.h>
#include <stdio.h>

//Creating a static variable in the function
// that is, this variable is initialized one time and keeps its
// value during the whole program
int calls_count (void)
{
    static int x = 0;
    x++;
    return x;
}


//passing the to-be-swapped pointers to double pointers
//so that when dereferencing the double pointers we access
//the value inside the passed pointers which is the addresses
//they're pointing to, and then swapping them
void pointers_swap (int** x, int** y)
{
    int* temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
//example call
int x =5, y=7;
int *ptrx = &x;
int *ptry = &y;
pointers_swap(&ptrx, &ptry);
//now ptrx points to y and ptry points to x


//creating a double pointer and allocating a space for 3 pointers
int ** arr = (int**) malloc(3*sizeof(int *));

//allocating space for 3 integers for each pointer(row)
for (int index = 0; index < 3; ++index)
{
    arr[index] = (int*)malloc(3 * sizeof(int));
}

}