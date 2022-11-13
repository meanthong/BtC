#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
    int dat;
    struct node *next_ptr;
} *node;

//Tạo thêm node.
node NodeCreate(int val)
{
    node temp_node;
    temp_node = (struct node*)malloc(sizeof(struct node));
    temp_node->dat = val;
    temp_node->next_ptr=NULL;
    return temp_node;
}

//Để thêm một phần tử vào vị trí sau cùng của vector:
void push_back(node *head_node, int val)
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

//Để lấy ra phần tử vị trí thứ n của vector (đếm từ 0):
node at(node head_node, int idx)
{
    int i=0;
    node ptr = head_node;
    while (ptr->next_ptr != NULL && i != idx)
    {
        ptr = ptr->next_ptr;
        i++;
    }
    return (ptr);
}
//Để bỏ đi phần tử cuối cùng của vector:
void pop_back(node *head_node)
{
    node ptr = *head_node;
    if (ptr==NULL)
    {
        return;
    }
     else if (ptr->next_ptr == NULL)
    {
        *head_node=NULL;
        return;
    } 
    while (ptr->next_ptr->next_ptr != NULL)
    {
        ptr = ptr->next_ptr;
    }
    free(ptr->next_ptr->next_ptr);
    ptr->next_ptr = NULL;
}

//Để lấy ra phần tử đầu tiên của vector:
node front(node first_node)
{
    if(first_node == NULL)
    {
        printf("Khong co phan tu nao duoc tao! \n");
        return(NULL);
    }
    else
    return(first_node);
}

//Để bỏ đi tất cả các phần tử của vector:
void clear(node *head_node)
{
    node ptr = *head_node;
    while (ptr != NULL)
    {
        pop_back(head_node);
        ptr = *head_node;
    }
}

//Để lấy ra phần tử cuối cùng của vector:
node back(node head_node)
{
        node ptr = head_node;
    if (ptr==NULL)
    {
        printf("Khong co phan tu nao duoc tao! \n");
        return(NULL);
    }
    while (ptr->next_ptr != NULL)
    {
        ptr = ptr->next_ptr;
    }
    return(ptr);
}

//Để biết số lượng phần tử của vector:
int size(node head_node)
{
    node ptr = head_node;
    int i=0;
    if (ptr==NULL)
    {
        printf("Khong co phan tu nao duoc tao! \n");
        return(0);
    }
    while (ptr->next_ptr != NULL)
    {
        ptr = ptr->next_ptr;
        i++;
    }
    return(i+1);
}

//Để biết vector có phần tử hay không:
bool emty(node head_node)
{
    node ptr = head_node;
    if (ptr == NULL)
    {
        return true;
    }
    else 
    {
        return false;
    }
    
}
//Main
 node node1 = NULL;
 void main()
 {
    push_back(&node1,1);
    push_back(&node1,1);
    push_back(&node1,1);
    push_back(&node1,1);
    printf("%d",emty(node1));
 }