/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 16:31:24 by dkramer       #+#    #+#                 */
/*   Updated: 2022/01/19 18:34:02 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_str
{
	int	argc;
	int	lena;
	int	lenb;
	int	error;
	int	isminusone;
	int	extraminusorplus;
	int	highestnr;
	int	*cstacka;
	int	*p;
	int	a;
	int	i;
	int	beforelena;
	int	beforelenb;
}				t_str;

void	swapames(int *stacka, t_str *str);
void	swapbmes(int *stackb, t_str *str);
void	ss(int *stacka, int *stackb, t_str *str);
int		*pushb(int *stacka, int **stackb, t_str *str);
int		*pusha(int *stackb, int **stacka, t_str *str);
void	revrotateames(int *stacka, t_str *str);
void	revrotatea(int *stacka, t_str *str);
int		*moveback(int *stack, int len, t_str *str);
void	rrr(int *stacka, int *stackb, t_str *str);
void	revrotatebmes(int *stackb, t_str *str);
void	rr(int *stacka, int *stackb, t_str *str);
void	rotatebmes(int *stackb, t_str *str);
void	rotateames(int *stacka, t_str *str);
int		*errors(int *stacka, char **argv, t_str *str);
int		*returnft(t_str *str);
int		*ft_radixsort(int *stackb, int *stacka, t_str *str);
int		issorted(t_str *str, int *stacka);
int		*indexing(t_str *str, int *stacka, int len);
int		*sort_under5(int *stacka, int *stackb, t_str *str);
int		*sort_under3(int *stacka, t_str *str, int len);
int		extrachecks(long long int nmb, int a, t_str *str);
int		mainfunction(int **stacka, int *stackb, t_str *str, char **argv);
void	movefront(int *save, int *stack, int len);

#endif