#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int dat;
    struct node *next_ptr;
} *node;

node NodeCreate(int val)
{
    node temp_node;
    temp_node = (struct node*)malloc(sizeof(struct node));
    temp_node->dat = val;
    temp_node->next_ptr=NULL;
    return temp_node;
}

void AddNode(node *head_node, int val)
{
    node temp_node = NodeCreate(val);
    node ptr = NULL;
    if (*head_node == NULL) 
    {
        *head_node =temp_node;
    }
    else 
    {
        ptr = *head_node;
        while (ptr->next_ptr != NULL)
        {
            ptr = ptr->next_ptr;
        }
        ptr->next_ptr = temp_node;  
    }
    
}

int GetVal(node head_node, int idx)
{
    int i=0;
    node ptr = head_node;

    while (ptr->next_ptr != NULL && i != idx)
    {
        ptr = ptr->next_ptr;
        i++;
    }
    return (ptr->dat);
}
 node node1 = NULL;
 void main()
 {
    
    AddNode(&node1,5);
    AddNode(&node1,6);
    AddNode(&node1,7);

    printf("%d\n",GetVal(node1, 0));
    
 }