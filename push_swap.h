#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
    int *stack;
    int size;
    int top;
} t_stack;

// Function prototypes
void pa(t_stack *stack_a, t_stack *stack_b);
void sa(t_stack *stack);
void sb(t_stack *stack);
void ss(t_stack *a, t_stack *b);
void exit_error(char *err);
char ** check_argv(char **av);
int check_dup(int *arr, int count);
t_stack *fill_a(char **arr, int size);
void print_stack(t_stack *stack, char *name);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t ft_strlen(const char *str);
char    *ft_strdup(const char *str);
char	**ft_split(char const *s, char c);