#include "push_swap.h"

// Push from stack B to stack A
void pa(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b || stack_b->size == 0)
        return;

    stack_a->stack[--stack_a->top] = stack_b->stack[stack_b->top++];
    stack_a->size++;
    stack_b->size--;
}

// Push from stack A to stack B
void pb(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b || stack_a->size == 0)
        return;

    stack_b->stack[--stack_b->top] = stack_a->stack[stack_a->top++];
    stack_b->size++;
    stack_a->size--;
}

// Swap the first two elements of a stack
void swap(t_stack *stack, char *op)
{
    if (!stack || stack->size < 2)
        return;

    int tmp = stack->stack[stack->top];
    stack->stack[stack->top] = stack->stack[stack->top + 1];
    stack->stack[stack->top + 1] = tmp;

    if (op)
        printf("%s\n", op);
}

// Swap the first two elements of stack A
void sa(t_stack *stack_a)
{
    swap(stack_a, "sa");
}

// Swap the first two elements of stack B
void sb(t_stack *stack_b)
{
    swap(stack_b, "sb");
}

// Swap the first two elements of both stacks
void ss(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a, NULL);
    swap(stack_b, NULL);
    printf("ss\n");
}

// Rotate a stack
void rotate(t_stack *stack, char *op)
{
    if (!stack || stack->size < 2)
        return;

    int hold = stack->stack[stack->size - 1];
    for (int i = stack->size - 1; i > stack->top; i--)
        stack->stack[i] = stack->stack[i - 1];
    stack->stack[stack->top] = hold;

    if (op)
        printf("%s\n", op);
}

// Rotate both stacks
void rr(t_stack *stack_a, t_stack *stack_b)
{
    rotate(stack_a, NULL);
    rotate(stack_b, NULL);
    printf("rr\n");
}

// Print an error message and exit
void exit_error(char *err)
{
    if (err)
        write(2, err, ft_strlen(err));
    exit(1);
}

// Convert a string to an integer
int ft_atoi(const char *nptr)
{
    size_t i = 0;
    int sign = 1;
    long res = 0;

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

// Join two arrays
char **joinArrEl(char **arr, char **split_arr)
{
    if (!split_arr)
        return arr;

    int i = 0, j = 0;
    while (arr && arr[i])
        i++;
    while (split_arr[j])
        j++;

    char **new_arr = malloc((i + j + 1) * sizeof(char *));
    if (!new_arr)
        return NULL;
    for (int k = 0; k < i; k++)
        new_arr[k] = arr[k];
    for (int k = 0; k < j; k++)
        new_arr[i + k] = split_arr[k];
    new_arr[i + j] = NULL;
    if (arr)
        free(arr);
    return new_arr;
}

// Check if the arguments are valid numbers
int isNumber(char **av)
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

// Function to check and process arguments
char **check_argv(char **av)
{
    if (!av)
        return NULL;

    char **arr = NULL;
    int i = 1;
    while (av[i])
    {
        char **split_arr = ft_split(av[i], ' ');
        arr = joinArrEl(arr, split_arr);
        if (split_arr)
            free(split_arr);
        if (!(isNumber(arr)))
            exit_error("Error\n");
        i++;
    }
    return arr;
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
// t_stack *fill_a(int ac, char **argv)
// {
//     if (!check_argv(argv))
//         exit_error("Error\n");

//     t_stack *stack = malloc(sizeof(t_stack));
//     if (!stack)
//         return NULL;

//     stack->stack = malloc(sizeof(int) * (ac - 1));
//     if (!stack->stack)
//     {
//         free(stack);
//         return NULL;
//     }

//     stack->top = 0;
//     stack->size = ac - 1;
//     for (int i = 0; i < ac - 1; i++)
//         stack->stack[i] = ft_atoi(argv[i + 1]);

//     if (!check_dup(stack->stack, ac - 1))
//         exit_error("Error\n");

//     return stack;
// }

// Initialize stack B
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
    stack_b->size = stack_a->size;
    stack_b->top = 0;
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

// Verify arguments
int verify_args(int ac, char **av)
{
    char **args = check_argv(av);
    if (args == NULL)
        return 0;
    return 1;
}

// Fill stack A with the input arguments
t_stack *fill_a(char **arr, int size)
{
    if (!arr)
        exit_error("Error\n");

    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL;

    stack->stack = malloc(sizeof(int) * size);
    if (!stack->stack)
    {
        free(stack);
        return NULL;
    }

    stack->top = 0;
    stack->size = size;
    for (int i = 0; i < size; i++)
        stack->stack[i] = ft_atoi(arr[i]);

    if (!check_dup(stack->stack, size))
        exit_error("Error\n");

    return stack;
}

int main(int argc, char *argv[])
{
    // Step 1: Check arguments and get processed array
    char **arr = check_argv(argv);
    if (!arr)
        return (-1);

    // Step 2: Determine the size of the array
    int arr_size = 0;
    while (arr[arr_size])
        arr_size++;

    // Step 3: Fill stack A using the processed array
    t_stack *stack_a = fill_a(arr, arr_size);
    t_stack *stack_b = initialize_b(stack_a);

    // Step 4: Example usage
    print_stack(stack_a, "stack_a");
    print_stack(stack_b, "stack_b");

    pa(stack_a, stack_b);
    print_stack(stack_a, "stack_a");


    return 0;
}
// Perform some operations
    // sa(stack_a);
    // pb(stack_a, stack_b);
    // rr(stack_a, stack_b);

    // print_stack(stack_a, "stack_a");
    // print_stack(stack_b, "stack_b");

    // // Free allocated memory
    // for (int i = 0; i < arr_size; i++)
    //     free(arr[i]);
    // free(arr);
    // free(stack_a->stack);
    // free(stack_a);
    // free(stack_b->stack);
    // free(stack_b);
    // TODO return err in this case --> ./a.out ""