/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:43:07 by emarles           #+#    #+#             */
/*   Updated: 2025/04/23 17:51:38 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
    int number;
    int index;
    struct node  *next;
} t_node;

typedef struct stack
{
    struct stack *head;
    // int value;
    int size;
    t_node  *node;
}   t_stack;
//utils
int	ft_atoi(const char *str);
int	ft_isalpha(int a);
char	*ft_strchr(const char *str, int search_str);
void    ft_exit_free(t_stack * a);

// input handle
void    ft_assign_indexes(t_stack *a, int size);

void    ft_handle_input(int argc, char **argv, t_stack *a);
void    ft_bubble_sort(t_node *a);

// simple sort
void sort_two(t_stack* a, t_stack* b);
void sort_three(t_stack* a, t_stack* b);
void sort_four(t_stack* a, t_stack* b);
void sort_five(t_stack* a, t_stack* b);
// radix sort
void    radix_sort(t_stack *a, t_stack *b);

#endif
