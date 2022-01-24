/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 17:04:31 by dkramer       #+#    #+#                 */
/*   Updated: 2021/12/14 17:04:48 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf/libftprintf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include "push_swap.h"

/*swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements)*/
void	swap(int *stack, int len)
{
	int	save;

	save = 0;
	if (len >= 2)
	{
		save = stack[0];
		stack[0] = stack[1];
		stack[1] = save;
	}
}

/*swap the first 2 elements at the top of stack a. Do nothing if there is 
only one or no elements)*/
void	swapames(int *stacka, t_str *str)
{
	if (str->lena >= 2)
	{
		ft_printf("sa\n");
		swap(stacka, str->lena);
	}
}

/*swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements)*/
void	swapbmes(int *stackb, t_str *str)
{
	if (str->lenb >= 2)
	{
		ft_printf("sb\n");
		swap(stackb, str->lenb);
	}
}

/*sa and sb at the same time*/
void	ss(int *stacka, int *stackb, t_str *str)
{
	ft_printf("ss\n");
	swap(stacka, str->lena);
	swap(stackb, str->lenb);
}
