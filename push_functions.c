/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 16:30:01 by dkramer       #+#    #+#                 */
/*   Updated: 2021/12/14 16:31:02 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf/libftprintf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include "push_swap.h"

/*shift evrything one down the stack*/
int	*moveback(int *stack, int len, t_str *str)
{
	int	i;
	int	saveint;
	int	save2;
	int	*save;

	save = malloc(sizeof(int) * (len));
	if (!save)
		return (returnft(str));
	i = 0;
	while (i < (len - 1))
		i++;
	if (i > 0)
	{
		saveint = len - 1;
		save2 = stack[saveint - 1];
		while (i > 0)
		{
			save[i] = stack[i - 1];
			i--;
		}
		save[saveint] = save2;
		save[0] = 0;
	}
	free (stack);
	return (save);
}

int	*pushanonmes(int *stack1, int **stack2, t_str *str)
{
	int	*save;

	save = 0;
	if (!*stack2)
	{
		*stack2 = malloc(sizeof(int) * (str->lena));
		if (!*stack2)
			return (returnft(str));
	}
	if (str->lena > 1)
	{
		*stack2 = moveback(*stack2, str->lena, str);
		if (!*stack2)
			return (0);
	}
	*stack2[0] = stack1[0];
	if (str->lenb >= 1)
	{
		save = malloc(sizeof(int) * (str->lenb));
		if (!save)
			return (returnft(str));
		movefront(save, stack1, str->lenb);
	}
	free (stack1);
	return (save);
}

int	*pushbnonmes(int *stack1, int **stack2, t_str *str)
{
	int	*save;

	save = 0;
	if (!*stack2)
	{
		*stack2 = malloc(sizeof(int) * (str->lenb));
		if (!*stack2)
			return (returnft(str));
	}
	if (str->lenb > 1)
	{
		*stack2 = moveback(*stack2, str->lenb, str);
		if (!*stack2)
			return (0);
	}
	*stack2[0] = stack1[0];
	if (str->lena >= 1)
	{
		save = malloc(sizeof(int) * (str->lena));
		if (!save)
			return (returnft(str));
		movefront(save, stack1, str->lena);
	}
	free (stack1);
	return (save);
}

/*take the first element at the top of b and put it at the top of a. Do
nothing if b is empty*/
int	*pusha(int *stackb, int **stacka, t_str *str)
{
	int	*save;

	save = 0;
	if (stackb)
	{
		str->lenb--;
		str->lena++;
		save = pushanonmes(stackb, stacka, str);
		if (str->error == 1)
			return (0);
		ft_printf("pa\n");
	}
	return (save);
}

/*take the first element at the top of a and put it at the top of b. Do
nothing if a is empty*/
int	*pushb(int *stacka, int **stackb, t_str *str)
{
	int	*save;

	save = 0;
	if (stacka)
	{
		str->lena--;
		str->lenb++;
		save = pushbnonmes(stacka, stackb, str);
		if (str->error == 1)
			return (0);
		ft_printf("pb\n");
	}
	return (save);
}
