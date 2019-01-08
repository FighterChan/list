/* 
 * list_sort.c
 * Original Author: chenwei3@ruijie.com.cn, 2019-01-08
 *
 * 
 * 
 *
 * History 
 * 
 *  

 */

#include "../list_sort/list.h"

/* 交换节点 */
static void
swap (struct list_head *a, struct list_head *b)
{
  struct list_head flag =
    { NULL, NULL };
  __list_add (&flag, b->prev, b);
  list_del (b);
  __list_add (b, a->prev, a);
  list_del (a);
  __list_add (a, flag.prev, &flag);
  list_del (&flag);
}

/* 插入排序 */
void
insert_sort (struct list_head *head, int
(*cmp) (struct list_head *a, struct list_head *b))
{

  struct list_head *i, *j, *temp;
  i = head->next->next;   //i指向第2个结点
  list_for_each_from (i, head)
    { //i从第2个结点开始遍历,因为第1个已经有序
      j = i->prev;  //j指向i的前一个结点

      if (cmp (j, i) <= 0) //从表头开始，按照升序排列
        continue;
      list_for_each_reverse_continue (j, head)
        {
          if (cmp (j, i) <= 0)
            break;
        }
      temp = i->next; //因为下文要删除i结点，所以记录i结点的下一个结点
      list_del (i);
      __list_add (i, j, j->next); //把i插入到j的后面
      i = temp->prev; //i指针归位
    }
}

/* 冒泡排序 */
void
bubble_sort (struct list_head *head, int
(*compar) (struct list_head *, struct list_head *))
{
  struct list_head *start = NULL;
  struct list_head *end = NULL;
  list_for_each_reverse (end, head)
    {
      list_for_each (start, head)
        {
          if (start == end)
            break;

          /* 升序排列 */
          if (compar (start, start->next) > 0)
            {
              swap (start, start->next);
              start = start->prev; //start归位
              if (start == end)
                end = end->next; //end归位
            }
        }
    }
}

/* 选择排序 */
void
select_sort (struct list_head *head, int
(*cmp) (struct list_head *a, struct list_head *b))
{
  struct list_head *i, *j, *min;

  list_for_each (i, head)
    {
      if (i == head->prev)
        break; //当i指向最后一个结点时，排序完成
      min = i; //用min指向最小的结点
      j = i->next;
      list_for_each_from (j, head)
        {
          if (cmp (j, min) < 0)
            {
              min = j;
            }
        }
      if (min != i)
        {
          swap (min, i);
          i = min; //i指针归位
        }
    }
}
