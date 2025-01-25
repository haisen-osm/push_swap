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
int *bubble_sort(int *arr, int count);
int check_argv(char **av);
int check_dup(int *arr, int count);
t_stack *fill_a(int ac, char **argv);
void print_stack(t_stack *stack, char *name);

// Push from stack B to stack A
void pa(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b)
        return;
    if (stack_b->size == 0)
        return;
    stack_a->top--;
    stack_a->stack[stack_a->top] = stack_b->stack[stack_b->top];
    stack_a->size++;

    stack_b->top++;
    stack_b->size--;

}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b)
        return;
    if (stack_a->size == 0)
        return;
    stack_b->top--;
    stack_b->stack[stack_b->top] = stack_a->stack[stack_a->top];
    stack_b->size++;

    stack_a->top++;
    stack_a->size--;
}
// Swap the first two elements of stack A
void sa(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return;

    int tmp = stack->stack[stack->top];
    stack->stack[stack->top] = stack->stack[stack->top + 1];
    stack->stack[stack->top + 1] = tmp;

}

// Swap the first two elements of stack B
void sb(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return;

    int tmp = stack->stack[stack->top];
    stack->stack[stack->top] = stack->stack[stack->top + 1];
    stack->stack[stack->top + 1] = tmp;

}

// Swap the first two elements of both stacks
void ss(t_stack *a, t_stack *b)
{
    if (!a || !b)
        return;

    sa(a);
    sb(b);
}

// Print an error message and exit
void exit_error(char *err)
{
    write(2, err, 6);
    exit(1);
}

// Bubble sort an array
int *bubble_sort(int *arr, int count)
{
    int i = 0;
    int j = 0;
    int tmp = 0;

    while (i < count)
    {
        j = 0;
        while (j < count - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
    return arr;
}

void ra(t_stack *stack_a)
{
    int hold;
    int i = 0;
    
    hold = stack_a->stack[stack_a->size - 1];

    while (i < stack_a->size - 1)
    {
        stack_a->stack[stack_a->size - i - 1] = stack_a->stack[stack_a->size - i - 2];
        i++;
    }
    stack_a->stack[0] = hold;
}

int	ft_atoi(const char *nptr)
{
	size_t		i;
	int			sign;
	long			res;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
        if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
            exit_error("Error\n");
		i++;
	}
	return (sign * res);
}

// Check if the arguments are valid numbers
int check_argv(char **av)
{
    int i = 1;
    int j = 0;

    while (av[i])
    {
        j = 0;
        if (av[i][j] == '-' || av[i][j] == '+')
            j++;
        while (av[i][j])
        {
            if (!(av[i][j] >= '0' && av[i][j] <= '9'))
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

// Check for duplicates in an array
int check_dup(int *arr, int count)
{
    int i = 0;
    int j = 0;

    while (i < count)
    {
        j = i + 1;
        while (j < count)
        {
            if (arr[i] == arr[j])
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

// Fill stack A with the input arguments
t_stack *fill_a(int ac, char **argv)
{
    if (!check_argv(argv))
        exit_error("Error\n");

    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;

    stack->stack = malloc(sizeof(int) * (ac - 1));
    if (!stack->stack)
    {
        free(stack);
        return NULL;
    }

    stack->top = 0;
    stack->size = ac - 1;
    for (int i = 0; i < ac - 1; i++)
        stack->stack[i] = ft_atoi(argv[i + 1]);

    if (!check_dup(stack->stack, ac - 1))
        exit_error("Error\n");

    return stack;
}

t_stack *initialize_b(t_stack *stack_a)
{
    if (!stack_a)
        return NULL;
    t_stack *stack_b = malloc(sizeof(t_stack));
    if (!stack_b)
    exit_error("Error\n");
    stack_b->stack = malloc(sizeof(int) * stack_a->size);
    if (!stack_b->stack)
    {
        free(stack_b);
        exit_error("Error\n");
    }
    stack_b->size = 0;
    stack_b->top = stack_a->size;
    return stack_b;
}

// Print the elements of a stack
void print_stack(t_stack *stack, char *name)
{
    printf("%s: ", name);
    for (int i = stack->top; i < stack->size; i++)
        printf("%d ", stack->stack[i]);
    printf("\n");
}



int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        return -1;
    stack_a = fill_a(argc, argv);
    stack_b = initialize_b(stack_a);
    print_stack(stack_a, "he:  -> ");
    ra(stack_a);
    print_stack(stack_a, "he:  -> ");
}
