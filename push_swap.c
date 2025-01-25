// // #include <stdio.h>
// // #include <stdlib.h>

// // int check_is_number(char *arg)
// // {
// // 	int i = 0;
// // 	while (arg[i])
// // 	{
// // 		if (!(arg[i] >= '0' && arg[i] <= '9'))
// // 			return 0;
// // 		i++;
// // 	}
// // 	return 1;
// // }
// // void print_arr(int *arr, int size)
// // 	{
// // 		int i = 0;
// // 		// int size = sizeof(arr) / sizeof(int);
// // 		while (i < size)
// // 		{
// // 			printf("arr[%d] -- > %d\n", i ,arr[i]);
// // 			i++;
// // 		}
// // 	}
// // int main(int argc, char *argv[])
// // {
// // 	// printf("%d\n",check_is_number("78"));
// // 	int i = 0;

// //     int *arr = malloc((argc - 1) * sizeof(int));
// // 	if (arr == NULL)
// // 		exit(1);
// // 	while (i < argc - 1)
// // 	{
// // 		// printf("%s\n",argv[i + 1]);
// // 		if (!check_is_number(argv[i + 1]))
// // 		{
// // 			free(arr);
// // 			exit(0);
// // 		}
// // 		arr[i] = atoi(argv[i + 1]);
// // 		i++;
// // 	}
// // 	// printf("\n\n%d\n", arr[0]);
// // 	printf("start printing the arr\n\n");
// // 	print_arr(arr, i);
// // 	return 0;
// // }

// //size
// //capacity
// //elements
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct{
// 	int *elements;
// 	int capacity;
// 	int size;
// } Stack;

// void print_elements(Stack *stack)
// {
// 	if (!stack) return ;
// 	printf("hello\n");
// }

// int main(int argc, char const *argv[])
// {
// 	Stack *fir = malloc(sizeof(Stack));
// 	fir->elements = malloc(sizeof(int) * 5);
// 	fir->capacity = 5;
// 	fir->size = 0;
// 	printf("%d\n", fir->capacity);
// 	print_elements(fir);
// 	return 0;
// }

//-----------------------------------------------of-----------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int capacity;
	int *stack;
	int size;
}				t_stack;

void exit_error(char *err)
{
	
}

int *bable_sort(int *arr, int count)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if (arr[i] < arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return arr;
}

int check_argv(char **av)
{
	int i = 1;
	int j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return 0;
			j++;
		}
		i++;
	}
	return (1);
}
	
int check_dup(int *arr, int count)
{
	int i = 0;
	int j = 0;
	int temp;
	while (i < count)
	{
		j = 0;
		temp = arr[i];
		while (j + 1 < count)
		{
			if (temp == arr[j + i+ 1])
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

t_stack *fill_a(int ac, char **argv)
{
	int i = ac - 1;
	if (!check_argv(argv)){
		printf("not only int");
		exit(1);
	}
	t_stack *stack = malloc(sizeof(t_stack));
	if (!stack)
		return NULL;
	stack->capacity = ac - 1;
	stack->stack = malloc(sizeof(int) * ac - 1);
	if (stack->stack == NULL)
		return NULL;
	int j = 0;
	while (j < i)
	{
		stack->stack[j] = atoi(argv[j + 1]);
		j++;
	} 
	if (check_dup(stack->stack,ac -1) == 1)
	{
		printf("no dup\n");
	}else {
		printf("there is dup\n");
		exit(1);
	}
	return stack;
}
int main(int argc, char *argv[])
{
	t_stack *stack_a;
	if (argc < 2)
		return (-1);
	stack_a = fill_a(argc, argv);
	if(stack_a == NULL)
		return 1;
	bable_sort(stack_a->stack, argc - 1);
	int i = 0;
	while (i < argc - 1)
	{
		printf("%d, ", stack_a->stack[i]);
		i++;
	}
	
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
