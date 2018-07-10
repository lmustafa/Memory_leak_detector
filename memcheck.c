#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List {

  void *mem_ptr;
  int line;
  char *file;
  struct List *next_ptr;
};

struct List *first_ptr = NULL;

void print_list(struct List *ptr)
{

  while(ptr){
  printf("memcheck error:  memory address %p which was allocated in file \"%s\", line %d, was never freed\n",ptr->mem_ptr,ptr->file,ptr->line);
  ptr = ptr->next_ptr;
  }

}

char *strdup2( char *str )
{
  char *new;
  new = malloc( strlen(str)+1 );
  if (new)
    strcpy( new, str );
  return new;
}

int memcheck_main();

int main()
{

  memcheck_main();

  print_list(first_ptr);

  return 0;
}

void *memcheck_malloc(int size, char *file, int line)
{

  struct List *new_list;

  void *mem_ptr2;

  mem_ptr2 = malloc(size);

  new_list = malloc(sizeof(struct List));

  new_list->mem_ptr = mem_ptr2;

  new_list->file = strdup2(file);

  new_list->line = line;

  new_list->next_ptr = first_ptr;

  first_ptr = new_list;

  return mem_ptr2;

}

void *memcheck_realloc(void *ptr, int size, char *file, int line)
{
  struct List *new_list;
  struct List *loop_ptr;


  void *mem_ptr2;

  /*Two cases: either the memory exists in one of the sturcts or does not, if
  it does you have to iterate through the linked list until you find that memeory and
  realloc more memory for that address, if the memory does not match then you have
  to create a new node and add it to the list*/

  loop_ptr = first_ptr;

  while(loop_ptr)
  {
  if(ptr == loop_ptr->mem_ptr)
  {
    loop_ptr->mem_ptr = realloc(loop_ptr->mem_ptr, sizeof(struct List));
    return loop_ptr->mem_ptr;
  }
  loop_ptr = loop_ptr->next_ptr;
  }

  mem_ptr2 = malloc(size);

  new_list = malloc(sizeof(struct List));

  new_list->mem_ptr = mem_ptr2;

  new_list->file = strdup2(file);

  new_list->line = line;

  new_list->next_ptr = first_ptr;

  first_ptr = new_list;

  return mem_ptr2;

}

void *memcheck_calloc(int nmemb, int size, char *file, int line)
{
  struct List *new_list;

  void *mem_ptr2;

  mem_ptr2 = calloc(nmemb, size);

  new_list = malloc(sizeof(struct List));

  new_list->mem_ptr = mem_ptr2;

  new_list->file = strdup2(file);

  new_list->line = line;

  new_list->next_ptr = first_ptr;

  first_ptr = new_list;

  return mem_ptr2;
}

void memcheck_free(void *ptr, char *file, int line)
{
  struct List **d_ptr;

  struct List *temp;

  d_ptr = &first_ptr;
    /*increment the double pointer until address matches*/
    while(*d_ptr)
  {
    if((*d_ptr)->mem_ptr == ptr)
    {
      free(ptr);
      temp = *d_ptr;
      *d_ptr = (*d_ptr)->next_ptr;
      free(temp);
      return;
    }
    d_ptr = &(*d_ptr)->next_ptr;
  }



  printf("memcheck error:  attempting to free memory address %p in file \"%s\", line %d.\n",ptr, file, line);

  return;
}
