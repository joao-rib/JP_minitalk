/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-rib <joao-rib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:33 by joao-rib          #+#    #+#             */
/*   Updated: 2024/05/14 15:01:20 by joao-rib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <signal.h>
//ft_printf
# define CONVERSION "cspdiuxX%"
# define FLAGS "-0# +"
# define DECIMAL "0123456789"
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UPP "0123456789ABCDEF"

//libft
bool	ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_print_error(char *str);

//ft_printf
int		ft_printf(const char *string, ...);
int		ft_putnbr_ubase_fd(unsigned int nbr, char *base, int fd);
int		ft_putnbr_lbase_fd(unsigned long nbr, char *base, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(long n, int fd);
int		ft_putstr_fd(char *str, int fd);

/*typedef struct s_stack
{
	int				num;
	int				order;
	int				final_order;
	int				cost_ra;
	int				cost_rra;
	int				cost_rb;
	int				cost_rrb;
	int				cost_rr;
	int				cost_rrr;
	int				cost_total;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

//Commands
void	swap(t_stack **stack, char stack_name);
void	push(t_stack **stack_src, t_stack **stack_dst, char name_dst);
void	rotate(t_stack **stack, char stack_name);
void	rev_rotate(t_stack **stack, char stack_name);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate_rr(t_stack **stack_a, t_stack **stack_b);

//Utils - Error Handling
void	error_exit(t_stack **stack);
bool	int_errors(char *str);
//Utils - Sorting
bool	check_sort(t_stack *stack);
void	min_to_top(t_stack **stack, char stack_name, int l);
void	sort_three(t_stack **stack, char stack_name);
void	sort_all(t_stack **stack_a, t_stack **stack_b);
//Utils - Finding
t_stack	*findmax_int(t_stack *stack);
t_stack	*findmin_int(t_stack *stack);
t_stack	*find_node_order(t_stack *stack, int order);
t_stack	*find_cheapest(t_stack *stack);
//Utils - Cataloguing
void	fill_the_order(t_stack *stack);
void	fill_desired_order(t_stack *stack, int l);
void	reset_cost(t_stack *stack);
void	total_cost(t_stack *stack);
//Utils - Pushing
void	push_it_bro(t_stack **stack_a, t_stack **stack_b, int len_a, int limit);
void	push_it_again(t_stack **stack_a, t_stack **stack_b);

//libft
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
long	ft_atol(const char *str);
bool	ft_isdigit(int c);
bool	ft_str_cmp(const char *s1, const char *s2);
bool	ft_rptcheck_str(char **str);
int		ft_smaller_int(int n1, int n2);

//libft (struct)
t_stack	*ft_lstnew_int(int num);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);*/

#endif
