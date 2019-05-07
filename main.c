#include "memcheck.h"
#include <stdio.h>
#include <stdlib.h>

/*struct strlst_struct *new_item( char character )
{
    struct strlst_struct *return_ptr;

    return_ptr = malloc(sizeof(struct strlst_struct));
    return_ptr->character = character;
    (*return_ptr).next = NULL;

    return return_ptr;
}
char free_item( struct strlst_struct *ptr )
{
    char character;

    character = ptr->character;
    free(ptr);

    return character;
}
void push( struct strlst_struct **list_ptr, struct strlst_struct *item_ptr )
{
    item_ptr->next = *list_ptr;
    *list_ptr = item_ptr;

}

struct strlst_struct *pop( struct strlst_struct **list_ptr )
{
    struct strlst_struct *item;

    item = *list_ptr;

    *list_ptr = item->next;

    item->next = NULL;

    return item;
}

int main()
{
    char letter;
    char *string = "dlrow olleh\n";
    struct strlst_struct *item_ptr, *list_ptr;

    list_ptr = NULL;

    for (;*string;string++)
    {
        item_ptr = new_item( *string );
        push( &list_ptr, item_ptr );
    }

    while (list_ptr)
    {
        item_ptr = pop( &list_ptr );
        free(item_ptr);
        letter = free_item( item_ptr );
        printf( "%c", letter );
    }
    printf( "\n" );

    return 0;
}*/


int main()
{

  char *ptr1, *ptr2, *ptr3, *ptr4, *ptr5, *ptr6, *ptr7;

  ptr1= malloc( 27 );

  ptr2 = malloc( 31 );

  ptr7 = malloc(100);

  ptr5 = calloc(30, sizeof(char));

  ptr3 = malloc( 37 );

  ptr4 = calloc(30, sizeof(char));

  ptr1 = realloc(ptr1, 30);

  ptr6 = realloc(ptr6,30);

  free( NULL );
  free( ptr3 );
  free( ptr1 );
  free(ptr4);
  free(ptr6);

  free(ptr2);

  free(ptr5);

  return 100;
}
