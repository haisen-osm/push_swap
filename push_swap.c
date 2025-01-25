#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
    int capacity;
    int *stack;
    int size;
    int top;
} t_stack;

// Function prototypes
void pa(t_stack *stack_a, t_stack *stack_b, int print);
void sa(t_stack *stack, int print);
void sb(t_stack *stack, int print);
void ss(t_stack *a, t_stack *b, int print);
void exit_error(char *err);
int *bubble_sort(int *arr, int count);
int check_argv(char **av);
int check_dup(int *arr, int count);
t_stack *fill_a(int ac, char **argv);
void print_stack(t_stack *stack, char *name);

// Push from stack B to stack A
void pa(t_stack *stack_a, t_stack *stack_b, int print)
{
    if (!stack_a || !stack_b)
        return;
    if (stack_b->size == 0)
        return;

    // Push the top element of stack B to stack A
    stack_a->top--;
    stack_a->stack[stack_a->top] = stack_b->stack[stack_b->top];
    stack_a->size++;

    // Pop the top element from stack B
    stack_b->top++;
    stack_b->size--;

    // Print "pa" if required
    if (print)
        write(1, "pa\n", 3);
}

// Swap the first two elements of stack A
void sa(t_stack *stack, int print)
{
    if (!stack || stack->size < 2)
        return;

    int tmp = stack->stack[stack->top];
    stack->stack[stack->top] = stack->stack[stack->top + 1];
    stack->stack[stack->top + 1] = tmp;

    // Print "sa" if required
    if (print)
        write(1, "sa\n", 3);
}

// Swap the first two elements of stack B
void sb(t_stack *stack, int print)
{
    if (!stack || stack->size < 2)
        return;

    int tmp = stack->stack[stack->top];
    stack->stack[stack->top] = stack->stack[stack->top + 1];
    stack->stack[stack->top + 1] = tmp;

    // Print "sb" if required
    if (print)
        write(1, "sb\n", 3);
}

// Swap the first two elements of both stacks
void ss(t_stack *a, t_stack *b, int print)
{
    if (!a || !b)
        return;

    sa(a, 0);
    sb(b, 0);

    // Print "ss" if required
    if (print)
        write(1, "ss\n", 3);
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

    stack->capacity = ac - 1;
    stack->stack = malloc(sizeof(int) * (ac - 1));
    if (!stack->stack)
    {
        free(stack);
        return NULL;
    }

    stack->top = 0;
    stack->size = ac - 1;

    for (int i = 0; i < ac - 1; i++)
        stack->stack[i] = atoi(argv[i + 1]);

    if (!check_dup(stack->stack, ac - 1))
        exit_error("Error\n");

    return stack;
}

// Print the elements of a stack
void print_stack(t_stack *stack, char *name)
{
	printf("\nthis is the top -> %d#\n",stack->top);
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
		return (-1);
	stack_a = fill_a(argc, argv);
	char *ag[] = {"a.out","5", "6", "7", "8", "9", NULL};
	stack_b = fill_a(5, ag);
	if(stack_a == NULL || stack_b == NULL)
		return 1;
	// stack_b->top = 0;
	// stack_b->size = 5;
	// stack_a->top = 0;
	// stack_a->size = argc - 1;
	// printf("Before sa: ");
    // for (int i = stack_a->top; i < stack_a->size; i++)
    //     printf("%d ", stack_a->stack[i]);
    // printf("\n");
	// 		printf("Before sb: ");
    // for (int i = stack_b->top; i < stack_b->size; i++)
    //     printf("%d ", stack_b->stack[i]);
    // printf("\n");
	// ss(stack_a, stack_b);
	// // sa(stack_a);
	// printf("after sa: ");
    // for (int i = stack_a->top; i < stack_a->size; i++)
    //     printf("%d ", stack_a->stack[i]);
    // printf("\n");
	// // ===-----------------------========
	// // sb(stack_b);
	// printf("after sb: ");
    // for (int i = stack_b->top; i < stack_b->size; i++)
    //     printf("%d ", stack_b->stack[i]);
    // printf("\n");
	// --------------------------------------------------
	////////// ? test pa;
	printf("stack b top element -> %d\n", stack_b->stack[stack_b->top]);
	// printf("stack a before pa: ");
	// for (int i = stack_a->top; i < stack_a->size; i++)
    //     printf("%d ", stack_a->stack[i]);
    // printf("\n");
	print_stack(stack_a, "stack a before pa");
	
	pa(stack_a, stack_b, 0);
	print_stack(stack_a, "stack a after  pa");
	printf("size = %d\n", stack_a->size);
	return 0;
}

// -------------------- testing -----------------------



// int main(int argc, char const *argv[])
// {
// 	int arr[] = {1, 3 ,5 ,2 ,9, 6,4};
// 	int *res = bable_sort(arr,7);
// 	for (size_t i = 0; i < 7; i++)
// 	{
// 		printf("%d",res[i]);
// 		if (i != 6)
// 		{
// 			printf(", ");
// 		}
// 	}
// 	return 0;
// }
