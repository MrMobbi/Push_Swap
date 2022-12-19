/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:46:07 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/17 19:22:14 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"
# include "../gnl/get_next_line.h"

# define SA "sa"
# define SB "sb"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RRA "rra"
# define RRB "rrb"

//		##### Main_Bonus.c #####
void	ft_read_ter(int fd, t_envi *env);
void	ft_compare_instruction(char *ter, t_envi *env);

//		##### Ft3_Swap_And_Push.c #####
void	ft_check_swap_a(t_envi *env);
void	ft_check_swap_b(t_envi *env);
void	ft_check_push_a(t_envi *env);
void	ft_check_push_b(t_envi *env);
void	ft_check_ss(t_envi *env);

//		###### Ft3_Rotate.c #####
void	ft_check_rotate_a(t_envi *env);
void	ft_check_rotate_b(t_envi *env);
void	ft_check_rr(t_envi *env);

//		##### Ft3_Reverse.c #####
void	ft_check_reverse_a(t_envi *env);
void	ft_check_reverse_b(t_envi *env);
void	ft_check_rrr(t_envi *env);

//		##### Utils_Bonus.c #####
int		ft_strcmp(char *s1, char *s2);
void	ft_error_checker(void);

#endif
