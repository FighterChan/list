/* /mycode/test/list_sort.h */
#ifndef _TEST_LIST_SORT_H_
#define _TEST_LIST_SORT_H_

#include "list.h"

void
insert_sort (struct list_head *head, int
(*cmp) (struct list_head *a, struct list_head *b));

void
bubble_sort (struct list_head *head, int
(*compar) (struct list_head *, struct list_head *));

void
select_sort (struct list_head *head, int
(*cmp) (struct list_head *a, struct list_head *b));

/* body of list_sort.h */
#endif /* _TEST_LIST_SORT_H_ */
