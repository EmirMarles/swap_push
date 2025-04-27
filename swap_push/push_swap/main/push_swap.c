/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:39:02 by emarles           #+#    #+#             */
/*   Updated: 2025/04/27 16:45:10 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int    ft_is_string(char *word);

// Parsing functions :
// 1) ft_split and size determination
    // Input functions:
    // 1) function to check if there are duplicates
    // 2) function to check if stack is sorted
    // 3) function to clear memory in case of error || when finishing
// Sort functions:
// 1) Index assigning function
// 2) Radix sort
    // Pushswap functions:
    // 1) pa, pb, ra, rb, etc.

void    sort_stack(t_stack* a, t_stack* b)
{
    if (a->size == 2)
        sort_two(a, b);
    else if (a->size == 3)
        sort_three(a, b);
    else if (a->size == 4)
        sort_four(a, b);
    else if (a->size == 5)
        sort_five(a, b);
    else
        radix_sort(a, b);
}

int main(int argc, char* argv[])
{
    t_stack  *a;
    t_stack  *b;
    int i;

    a = malloc(sizeof(t_stack));
    a->head = NULL;
    b = malloc(sizeof(t_stack));
    b->head = NULL;
    
    if (argc == 1)
    {
        write(1, "Not enough arguments\n", 22);
        return (0);
    }
    ft_handle_input(argc, argv, a);
    t_node *current = a->head;
    while (current != NULL)
    {
        printf("The current value in the linked list : %i\n", current->number);
        current = current->next;
    }
    ft_assign_indexes(a, argc - 1);
    sort_stack(a, b);
    // ft_exit_free(a);
    // free everything;
    return (0);
}