/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:57:44 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/08 16:09:37 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_tab {
	double	*tab;
	int		len;
}			t_tab;

typedef struct s_list {
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_envi {
	t_list	*st_a;
	t_list	*st_b;
	int		max_index;
	int		len_a;
	int		limit;
	int		pi;
	int		chonk;
	int		index_chonk;
}			t_envi;

//		##### Utils.c #####
double	ft_atod(char *str);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(t_tab *check, int i);
char	*ft_substr(char const *str, size_t start, size_t len);
char	*ft_calloc(size_t count, size_t size);

//		##### Utils_2.c #####
size_t	ft_strlen(const char *str);
void	ft_free_and_exit(t_envi *env, t_tab *check);
void	ft_free(t_envi *env, t_tab *check);
void	ft_free_list(t_list *list);

//		##### Ft1_Init_Env.c ######
void	ft_init_env(t_envi *env, t_tab *check, int ac, char **av);
void	ft_init_chonk(t_envi *env);
void	ft_check_nbr_numbers(t_tab *check, char *str);
void	ft_add_number_in_list(t_envi *env, t_tab *check, int i);
t_tab	*ft_init_check(t_tab *check, int ac, char **av);

//		##### Ft1_Add_Index.c #####
void	ft_add_index(t_tab *check, t_envi *env);
void	ft_index_to_list(t_tab *check, t_envi *env);
void	ft_index(t_list *lst, int i, double nbr);
void	ft_sort_check(double *list, int start, int pivot);
int		ft_check_pivot(double *list, int pivot);

//		###### Ft1_One_String.c #####
t_tab	*ft_one_string(char *str, t_tab *check);
int		ft_count_numbers(char **str);
t_tab	*ft_init_check_one(t_tab *check, int count, char **av);
void	ft_free_one_string(char **str);

//		##### Ft1_Split.c #####
int		ft_count_word(const char *str, char c);
int		ft_strlen_c(const char *str, int index, char c);
int		ft_find_next_word(const char *str, int index, char c);
char	**ft_split(char const *str, char c);

//		##### Ft1_Error.c #####
int		ft_error(t_envi *env, t_tab *check, int ac, char **av);
int		ft_check_error(int ac, char **av);
int		ft_check_arg(char *str);
int		ft_check_double(double *tab, int len);
int		ft_check_int(double *tab, int len);

//		##### Ft2_Solver.c #####
int		ft_solver(t_envi *env);
int		ft_check_sort(t_envi *env);

//		##### Ft2_Push_And_Swap.c #####
void	ft_swap_a(t_envi *env);
void	ft_swap_b(t_envi *env);
void	ft_push_a(t_envi *env);
void	ft_push_b(t_envi *env);

//		##### Ft2_Rotate_And_Reverse.c #####	
void	ft_rotate_a(t_envi *env);
void	ft_rotate_b(t_envi *env);
void	ft_reverse_a(t_envi *env);
void	ft_reverse_b(t_envi *env);

#endif
