/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   revrotate_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 17:04:07 by dkramer       #+#    #+#                 */
/*   Updated: 2021/12/14 17:04:08 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf/libftprintf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include "push_swap.h"

void	revrotate(int *stack, int len)
{
	int	i;
	int	save;

	i = 0;
	while (i < (len - 1))
		i++;
	if (i > 0)
		save = stack[len - 1];
	else
		save = 0;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = save;
}

/*shift down all elements of stack b by 1. The last element
becomes the first one*/
void	revrotatebmes(int *stackb, t_str *str)
{
	ft_printf("rrb\n");
	revrotate(stackb, str->lenb);
}

/*shift down all elements of stack a by 1. The last element
becomes the first one*/
void	revrotateames(int *stacka, t_str *str)
{
	ft_printf("rra\n");
	revrotate(stacka, str->lena);
}

/*rra and rrb at the same time*/
void	rrr(int *stacka, int *stackb, t_str *str)
{
	ft_printf("rrr\n");
	revrotate(stacka, str->lena);
	revrotate(stackb, str->lenb);
}
