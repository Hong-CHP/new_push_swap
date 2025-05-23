#include "push_swap.h"

int     get_real_pos(t_stack *stack_a, int num)
{
    t_node *cur;
    int pos;

    pos= 1;
    cur = stack_a->top;
    while (cur)
    {
        if (num == *(cur->value))
            break;
        pos++;
        cur = cur->next;
    }
    return (pos);
}

int     *pos_from_top_or_bottom(t_stack *stack_a, int pos, int *pos_obj, int index)
{
    if (pos <= (stack_a->size + 1) / 2)
        pos_obj[index] = pos - 1;
    else
        pos_obj[index] = stack_a->size - pos + 1;
    return (pos_obj);
}

//printf("pos_obj are : %d, %d, %d, %d\n", pos_obj[0], pos_obj[1], pos_obj[2], pos_obj[3]);
void    find_obj_node_pos(t_stack *stack_a, int *arr_asc, t_index times, t_unmarked *unmarked_nbs, int *pos_obj)
{
    t_node *cur;
    int index;
    int pos;
    int found;
    
    index = 0;
    while (times.start < times.end)
    {
        cur = stack_a->top;
        found = 0;
        while (cur)
        {
            if (arr_asc[times.start] == *(cur->value) && is_obj_unmarked(unmarked_nbs, arr_asc[times.start]))
            {
                pos = get_real_pos(stack_a, arr_asc[times.start]);
                pos_from_top_or_bottom(stack_a, pos, pos_obj, index);
                found = 1;
            }
            cur =cur->next;
        }
        if (!found)
            pos_obj[index] = -1;
        times.start++;
        index++;
    }
    printf("pos_obj are : %d, %d, %d, %d\n", pos_obj[0], pos_obj[1], pos_obj[2], pos_obj[3]);
}


t_obj   *not_found_value(t_obj *obj)
{
    obj->path = -1;
    return (obj);
}

t_obj find_shorter_path_rotate(int *arr_asc, t_unmarked *unmarked_nbs, int *pos_obj, t_index times)
{
    t_obj obj;
    int i;
    int shortest_index = -1;
    int len = times.end - times.start;
      //5 10 -1 -1
    i = 0; 
    while (i < len)
    {
        //pos[0] = 5 && (s_i == -1 || pos[0] < pos[-1]) : s_i = 0
        //pos[1] = 10 && (s_i == 0 || pos[1] < pos[0])
        //pos[2] = -1 pos[3] = -1
        if (pos_obj[i] != -1 && (shortest_index == -1 || pos_obj[i] < pos_obj[shortest_index]))
            shortest_index = i;
        i++;
    }
    if (shortest_index == -1)
        return (*not_found_value(&obj));
    obj.path = pos_obj[shortest_index];
    obj.value = arr_asc[shortest_index + times.start];
    //obj.path = pos[0]
    //obj.value = arr_asc[0 + 0]
    printf("shortest value is %d, shortest path is %d\n", obj.value, obj.path);
    return obj;
}


// t_obj   find_shorter_path_rotate(int *arr_asc, t_unmarked *unmarked_nbs, int *pos_obj, t_index times)
// {
//     t_obj   obj;
//     int i;
//     int shortest;
//     int obj_value;

//     i = 0;
//     while(i < (times.end - times.start) && pos_obj[i] == -1)
//         i++;
//     obj.path = pos_obj[i];
//     obj_value = i;
//     while (i < (times.end - times.start))
//     {
//         if (pos_obj[i] != -1 && obj.path > pos_obj[i])
//         {
//             while (i < (times.end - times.start)
//                 && !is_obj_unmarked(unmarked_nbs, arr_asc[i + times.start]))
//                 i++;
//             if (i == (times.end - times.start))
//                 return (*not_found_value(&obj));
//             obj.path = pos_obj[i];
//             obj_value = i;
//         }
//         i++;
//     }
//     obj.value = arr_asc[obj_value + times.start];
//     return (obj);
// }
