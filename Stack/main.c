//Viết hàm Push, pop, isemty, isfulll , size cho stack.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 5
typedef int type;
typedef struct Stack
{
    type data[SIZE];
    int count;
} Stack;

void InitStack(Stack *stack)
{
    for (int i = 0; i < SIZE; i++)
    {
        stack->data[i] = '\0';
    }
    stack->count = -1;
}
bool IsEmpty(Stack stack)
{
    return (stack.count == -1);
}
bool IsFull(Stack stack)
{
    return (stack.count == SIZE-1);
}
void Push(Stack *stack, type data)
{
    if (IsFull(*stack))
    {
        printf("Stack is full!!!\n"); 
        return;
    }
    else {
        stack->count++;
        stack->data[stack->count] = data;
    }
    
}
type Pop(Stack *stack)
{
    if (IsEmpty(*stack))
    {
        printf("Stack is empty!!!\n");
        return NULL;
    }
    else {
        type temp = stack->data[stack->count];
        stack->data[stack->count] = '\0';
        stack->count--;
        return(temp);
    }
}

Stack stack;
void main()
{
    InitStack(&stack);
    Push(&stack, 5);
    Push(&stack, 5);
    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    Push(&stack, 5);
    printf("%d",Pop(&stack));
    Pop(&stack);
    printf("%d",Pop(&stack));
}