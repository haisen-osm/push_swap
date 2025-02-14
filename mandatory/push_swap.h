/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhourss <okhourss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:57:20 by okhourss          #+#    #+#             */
/*   Updated: 2025/02/14 18:23:08 by okhourss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
	int	top;
	int	hold_size;
}	t_stack;

// push_swap
t_stack	*initialize_b(t_stack *stack_a);
t_stack	*fill_a(char **av);
void	fill_stack(t_stack *stack, char **arr);
// sort
void	sort_stacks(t_stack *stack_a, t_stack *stack_b);
void	push_back(t_stack *stack_a, t_stack *stack_b);
void	push_to_b(t_stack *stack_a, t_stack *stack_b, int *sortedArr);
// sort_utils
void	get_stack_info(t_stack *stack, int *max, int *max_pos);
void	push_num_to_b(int num, t_stack *stack_a, t_stack *stack_b);
void	push_num_to_b2(int num, t_stack *stack_a, t_stack *stack_b);
void	rotate_to_num(int num, t_stack *stack_a);
// sort_helpers
int		get_position(int nb, int *arr, int size);
int		get_max_range(t_stack *stack);
int		find_position(int num, t_stack *stack);
int		*sort_array(t_stack *stack);
int		ft_is_sorted(t_stack *stack);
// small_sort
void	sort5(t_stack *stack_a, t_stack *stack_b, int *sorted);
void	sort3(t_stack *stack);
// parsing_helpers
char	**join_arr(char **arr, char **split_arr);
int		get_size(char **arr);
int		is_number(char **av);
char	**check_argv(char **av);
int		check_dup(int *arr, int count);
int		ft_atoi(const char *nptr, char **arr, t_stack *stack);
// operations
void	write_op(char *op);
void	swap(t_stack *stack, char *op);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a, int display);
void	pa(t_stack *stack_a, t_stack *stack_b, int display);
void	ra(t_stack *stack_a, int display);
void	rb(t_stack *stack_b, int display);
void	rr(t_stack *stack_a, t_stack *stack_b, int display);
void	rra(t_stack *stack_a, int display);
void	rrb(t_stack *stack_b, int display);
void	rrr(t_stack *stack_a, t_stack *stack_b, int display);
// freeing and exiting
void	free_arr(char **arr);
void	exit_error(char *err, char **arr, t_stack *stack);
void	free_stack(t_stack *stack);
// others
void	*ft_memmove(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
