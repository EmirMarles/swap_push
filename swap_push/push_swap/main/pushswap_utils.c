/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:36:58 by emarles           #+#    #+#             */
/*   Updated: 2025/04/21 15:09:17 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while ((str[i] == '-' || str[i] == '+') && (str[i + 1] != '+' && str[i
				+ 1] != '-'))
	{
		if (str[i] == '-')
			sign = (sign * -1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_isalpha(int a)
{
	if ((a >= 0 && a <= 44) || (a >= 58 && a <= 127))
		return (1);
	return (0);
}

char	*ft_strchr(const char *str, int search_str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)search_str)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (search_str == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}

// size_t	ft_amount_of_elements(char **argv)
// {
// 	size_t	size;
// 	while (argv)
// 	{
// 		argv++;
// 		size++;
// 	}
// }