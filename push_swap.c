/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:39:02 by emarles           #+#    #+#             */
/*   Updated: 2025/04/23 17:47:44 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_is_string(char *word);
    // Input functions:
    // 1) function to check if there are duplicates
    // 2) function to check if stack is sorted
    // 3) function to clear memory in case of error || when finishing

// Sort functions:
// 1) Index assigning function
// 2) Radix sort

// Pushswap functions:
// 1) pa, pb, ra, rb, etc.
void    ft_handle_input(int argc, char **argv, t_stack *a)
{
    t_node  *new_node;
    t_node  *head;
    t_node  *current;
    
    head = NULL;
    current = NULL;
    argc--;
    while (argc > 0)
    {
        if (ft_is_string(argv[argc]))
        {
            write(1, "Error\n", 7);
            exit(EXIT_FAILURE);
        }
        new_node = malloc(sizeof(t_node));
        if (!new_node)  
        {
            write(1, "Malloc failure\n", 16);
            exit(EXIT_FAILURE);
        }
        new_node->number = ft_atoi(argv[argc]);
        new_node->next = NULL;
        if (!head) // start of the list;
        {
            head = new_node;
            current = head;
        }
        else 
        {
            current->next = new_node;
            current = current->next;
        }
        argc--;
        // printf("Added number in the list: %d\n", new_node->number);
    }
    a->node = head; // head should always be saved in a separate value;
}

int    ft_is_string(char *word)
{ 
    int i;

    i = 0;
    while (word[i] != '\0')
    {
        if (ft_isalpha(word[i]))
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char* argv[])
{
    t_stack  *a; //head
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
    t_node *current = a->node;
    while (current != NULL)
    {
        printf("The current value in the linked list : %i\n", current->number);
        current = current->next;
    }
    ft_assign_indexes(a, argc - 1);
    // ft_exit_free(a);
    free(a);
    free(b);
    return (0);
}