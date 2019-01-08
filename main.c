/* 
 * main.c
 * Original Author: chenwei3@ruijie.com.cn, 2018-11-22
 *
 * 
 * 
 *
 * History 
 * 
 *  
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../list_sort/list.h"
#include "../list_sort/list_sort.h"

struct person
{
  int age;
  int index;
  char name[20];
  struct list_head list;
};

int num[] =
  { 5, 41, 3, 22, 11, 29, 18, 77, 22, 22, 45, 41, 22, 29, 22, 23, 23, 23, 22,
      22, 25, 22, 22, 56, 22, 3, 4, 5, 6, 3, 4, 3, 4, 3, 5, 3, 3, 4, 3, 3 };

LIST_HEAD(head);

int
cmp_age (struct list_head *a, struct list_head *b)
{
  struct person *pa = list_entry(a, struct person, list);
  struct person *pb = list_entry(b, struct person, list);
  return (pa->age - pb->age);
}

int
cmp_name (struct list_head *a, struct list_head *b)
{
  struct person *pa = list_entry(a, struct person, list);
  struct person *pb = list_entry(b, struct person, list);
  if(pa->age == pb->age)
    {
      return (strcmp(pa->name,pb->name));
    }
  else
    {
      return 0;
    }
}

int
list_add_sort (struct person *new)
{
  list_add_tail (&new->list, &head);

  bubble_sort(&head,cmp_age);
  bubble_sort(&head,cmp_name);

  return 0;
}

int
main (int argc, char* argv[])
{
  struct person *data;
  int len;
  len = sizeof(num) / sizeof(int);
  int i;
  for (i = 0; i < len; ++i)
    {
      data = (struct person *) malloc (sizeof(struct person));
      if (data == NULL)
        {
          return -1;
        }
      data->age = num[i];
      data->index = rand () % len;
      sprintf(data->name,"%dchen%d",rand()%10,rand()%10);
      list_add_sort (data);
    }

  struct person *p, *n;
  list_for_each_entry_safe(p,n,&head,list)
    {
      printf ("%d,%s\n", p->age, p->name);
    }
  printf ("\n---------------------------------------\n");

  list_for_each_entry_safe(p,n,&head,list)
    {
      list_del_init (&p->list);
      free (p);
    }
}
