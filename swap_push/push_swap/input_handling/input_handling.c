/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:55:34 by emarles           #+#    #+#             */
/*   Updated: 2025/04/23 17:56:06 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main/push_swap.h"

static void assign_indexes(t_stack *a, int *array);

void    ft_assign_indexes(t_stack *a, int size)
{
    int i;
    int j; 
    int k;
    int temp;
    t_node *current;
    int *array;
    a->size = size;
    array = malloc(sizeof(int) * (size));
    
    i = size;
    current = a->node;
    while (current != NULL)
    {
        array[size - 1] = current->number;
        current = current->next;
        size--;    
    }
    j = 0;
    // assigning the indexes process;
    j = 0;
    while (j < i)
    {
        k = 0;
        while (k < i - 1)
        {
            if (array[k] > array[k + 1])
            {
                temp = array[k + 1];
                array[k + 1] = array[k];
                array[k] = temp;
            }
            k++;
        }
        j++;
    }
    assign_indexes(a, array);
    free(array);
}

static void assign_indexes(t_stack *a, int *array)
{
    t_node *current;
    t_node *new_current;
    int i;

    current = a->node;
    while (current != NULL)
    {
        i = 0; 
        while (i < a->size) // size goes here
        {
            if (current->number == array[i])
            {
                current->index = i;
                break;
            }
            i++;
        }
        current = current->next;        
    }
    // new_current = a->node;
    // while (new_current != NULL)
    // {
    //     printf("The values and their indexes : %i, %i\n", new_current->number, new_current->index);
    //     new_current = new_current->next;
    // }
}

void    ft_exit_free(t_stack * a)
{
    t_node *current; 

    current = a->node;
    while (current != NULL)
    {
        free(current);
        current = current->next;
    }
    free(current);
}