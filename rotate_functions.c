/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 17:04:17 by dkramer       #+#    #+#                 */
/*   Updated: 2021/12/14 17:04:18 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf/libftprintf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include "push_swap.h"

/*shift evrything one up the stack*/
void	movefront(int *save, int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		save[i] = stack[i + 1];
		i++;
	}
}

/* shift up all elements of stack b by 1. The first element becomes
the last one*/
void	rotate(int *stack, int len)
{
	int	i;
	int	save;

	i = 0;
	save = stack[0];
	while (i < (len - 1))
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = save;
}

/* shift up all elements of stack b by 1. The first element becomes
the last one*/
void	rotatebmes(int *stackb, t_str *str)
{
	ft_printf("rb\n");
	rotate(stackb, str->lenb);
}

/* shift up all elements of stack a by 1. The first element becomes
the last one*/
void	rotateames(int *stacka, t_str *str)
{
	ft_printf("ra\n");
	rotate(stacka, str->lena);
}

/*ra and rb at the same time*/
void	rr(int *stacka, int *stackb, t_str *str)
{
	ft_printf("rr\n");
	rotate(stacka, str->lena);
	rotate(stackb, str->lenb);
}
