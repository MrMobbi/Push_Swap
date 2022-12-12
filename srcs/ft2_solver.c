/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:32:01 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/12 19:26:19 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_step1(t_envi *env);
void	ft_solve_a(t_envi *env);
int		ft_lstlast_nbr(t_list *lst, int old);
int		ft_search_path(t_list *list, int value);

void	ft_solve_2nbr(t_envi *env)
{
	if (ft_check_sort(env) == 1)
	{
		ft_rotate_a(env);
		ft_printf("ra\n");
	}
}

void	ft_solve_5nbr(t_envi *env)
{
	int	i;

	i = 1;
	while (i < 3)
	{
		if (env->st_a->index == i)
		{
			ft_push_b(env);
			ft_printf("pb\n");
			i++;
		}
		else if (ft_search_path(env->st_a, i) <= 2)
		{
			ft_rotate_a(env);
			ft_printf("ra\n");
		}
		else
		{
			ft_reverse_a(env);
			ft_printf("rra\n");
		}
	}
	ft_solve_a(env);
	ft_push_a(env);
	ft_printf("pa\n");
	ft_push_a(env);
	ft_printf("pa\n");
}

int	ft_solver(t_envi *env)
{
	if (ft_check_sort(env) == 0)
		return (0);
	if (env->max_index == 2)
	{
		ft_solve_2nbr(env);
		return (0);
	}
	if (env->max_index == 5)
	{
		ft_solve_5nbr(env);
		return (0);
	}
	ft_step1(env);
	ft_solve_a(env);
	while (ft_check_sort(env) == 1 || env->st_b != NULL)
	{
		while (env->st_b->index != env->st_a->index - 1 && env->st_b != NULL)
		{
			if (ft_search_path(env->st_b, env->st_a->index - 1) < env->st_a->index / 2)
			{
				if (env->st_b->index < env->st_a->index - 2 && env->st_b->index > env->under_a)
				{
					env->under_a = env->st_b->index;
					ft_push_a(env);
					ft_rotate_a(env);
					ft_printf("pa\nra\n");
					env->rotate++;
				}
				else
				{
					ft_rotate_b(env);
					ft_printf("rb\n");
				}
			}
			else
			{
				if (env->st_b->index < env->st_a->index - 2 && env->st_b->index > env->under_a)
				{
					env->under_a = env->st_b->index;
					ft_push_a(env);
					ft_rotate_a(env);
					ft_printf("pa\nra\n");
					env->rotate++;
				}
				else
				{
					ft_reverse_b(env);
					ft_printf("rrb\n");
				}
			}
		}
		ft_push_a(env);
		ft_printf("pa\n");
		if (env->rotate > 0 && env->under_a == env->st_a->index - 1)
		{
			while (env->st_a->index - 1 == env->under_a && env->rotate > 0)
			{
				ft_reverse_a(env);
				ft_printf("rra\n");
				env->rotate--;
				env->under_a = ft_lstlast_nbr(env->st_a, env->under_a);
			}
		}
	}
	return (0);
}

int	ft_lstlast_nbr(t_list *lst, int old)
{
	int		nbr;
	t_list	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	nbr = tmp->index;
	if (old < nbr)
		return (0);
	return (nbr);
}

int	ft_search_path(t_list *list, int value)
{
	int		i;
	t_list	*path;

	path = list;
	i = 0;
	while (1)
	{
		if (path == NULL)
			return (i);
		if (path->index == value)
			break ;
		path = path->next;
		i++;
	}
	return (i);
}

void	ft_solve_a(t_envi *env)
{
	t_list	*check;
	int		i;

	i = env->max_index;
	while (ft_check_sort(env) == 1)
	{
		while (env->st_a->index != env->max_index)
		{
			if (ft_search_path(env->st_a, i) < 2)
			{
				ft_rotate_a(env);
				ft_printf("ra\n");
			}
			else
			{
				ft_reverse_a(env);
				ft_printf("rra\n");
			}
		}
		ft_rotate_a(env);
		ft_printf("ra\n");
		check = env->st_a->next;
		if (check->index != env->max_index - 1)
		{
			ft_swap_a(env);
			ft_printf("sa\n");
		}
	}
}

void	ft_step1(t_envi *env)
{
	env->pi += env->chonk;
	while (env->len_a > 3)
	{
		if (env->index_chonk == env->pi)
			env->pi += env->chonk;
		if (env->st_a->index <= env->limit && env->st_a->index <= env->pi)
		{
			if (env->st_a->index <= env->limit && env->st_a->index <= env->pi / 2)
			{
				ft_push_b(env);
				ft_rotate_b(env);
				env->index_chonk++;
				ft_printf("pb\nrb\n");
			}
			else
			{
				ft_push_b(env);
				env->index_chonk++;
				ft_printf("pb\n");
			}
		}
		else
		{
			ft_rotate_a(env);
			ft_printf("ra\n");
		}
	}	
}

int	ft_check_sort(t_envi *env)
{
	t_list	*tmp;
	int		check;

	tmp = env->st_a;
	check = tmp->value;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->value < check)
			return (1);
		check = tmp->value;
	}
	return (0);
}
