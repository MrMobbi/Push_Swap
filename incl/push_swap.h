/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:57:44 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/05 18:26:37 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_tab {
	double	*a;
	int		len_a;
}			t_tab;

typedef struct s_list {
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_envi {
	t_list	*start_a;
	t_list	*start_b;
	int		count;
}			t_envi;

//		##### Ft_Init_Env.c ######
void	ft_init_env(t_envi *env, t_tab *check, int ac, char **av);
void	ft_add_number_in_list(t_envi *env, t_tab *check, int i);
void	ft_check_nbr_numbers(t_tab *check, char *str);
t_tab	*ft_init_check(t_tab *check, int ac, char **av);

//		###### Ft_One_String.c #####
t_tab	*ft_one_string(char *str);

//		##### Ft_Quick_Sort.c #####
int		ft_quick_sort(t_envi *env);

//		##### Ft_Add_Index.c #####
void	ft_add_index(t_tab *check, t_envi *env);
void	ft_sort_check(double *list, int start, int pivot);
void	ft_index_to_list(t_tab *check, t_envi *env);
void	ft_index(t_list *lst, int i, double nbr);
int		ft_check_pivot(double *list, int pivot);

//		##### Ft_Push_And_Swap.c #####

//		##### Ft_Rotate_And_Reverse.c #####

//		##### Utils.c #####
double	ft_atod(char *str);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(t_tab *check, int i);
char	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *str, size_t start, size_t len);

//		##### Utils.c #####
size_t	ft_strlen(const char *str);

//		##### Ft_Split.c #####
int		ft_count_word(const char *str, char c);
int		ft_strlen_c(const char *str, int index, char c);
int		ft_find_next_word(const char *str, int index, char c);
char	**ft_split(char const *str, char c);

//		##### Ft_Error.c #####
int		ft_error(t_tab *check, int ac, char **av);
int		ft_check_error(int ac, char **av);
int		ft_check_arg(char *str);
int		ft_check_double(double *tab, int len);
int		ft_check_int(double *tab, int len);

#endif
