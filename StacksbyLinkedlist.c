#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
struct node* top=NULL;
int isEmpty(struct node* top){
    if (top==NULL)
    {
        return 1;
    }
    return 0;   
}
int isFull(struct node* top){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL)
    {
        return 1;
    }
    return 0;   
}
void display_Stack(struct node *ptr){
   while (ptr!=NULL)
    {
        printf("element is: %d\n",ptr->data);
        ptr=ptr->next;
    }   
}
struct node* push_Stack(struct node* ,int);
int pop_Stack(struct node*);
int peek_Stack(int);
int Stack_top(struct node*);
int Stack_bottom(struct node*);



int main()
{
    int choice,peek,data,res,pos,topmost,lowest;
    while (1)
    {
        printf("enter 1 to push a data into stack\n");
        printf("enter 2 to pop a data from stack\n");
        printf("enter 3 to display a value at any position in the stack\n");
        printf("enter 4 to display top value of the stack\n");
        printf("enter 5 to display bottom value stack\n");
        printf("enter 6 to exit\n");
        scanf("%d",&choice);
            switch (choice)
            {
                case 1:
                printf("enter data to push\n");
                scanf("%d",&data);
                top=push_Stack(top,data);
                display_Stack(top);
                break;
                case 2:
                res=pop_Stack(top);
                printf("%d popped from stack\n",res);
                display_Stack(top);
                break;
                case 3:
                printf("enter position to return the value at that position\n");
                scanf("%d",&pos);
                peek=peek_Stack(pos);
                printf("value at %d is %d\n",pos,peek);
                display_Stack(top);
                break;
                case 4:
                topmost=Stack_top(top);
                printf("topmost value is:%d\n",topmost);
                display_Stack(top);
                break;
                 case 5:
                lowest=Stack_bottom(top);
                printf(" value at last is:%d\n",lowest);
                display_Stack(top);
                break;
                case 6:
                exit(0);
                break;
                default:
                printf("invalid choice\n");
                break;
            }    
    }
 return 0;
}

struct node* push_Stack(struct node* top ,int x){
    struct node* newnode;
    if (!isFull(top))
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=top;
        top=newnode;
    }
    else{
        printf("stack overflow\n");
    }
}

int pop_Stack(struct node* tp){
    if (isEmpty(tp))
    {
        printf("Stack underflow cannot pop\n");
        return -1;
    }
    else{
        struct node* n=(tp);
        (top)=(tp)->next;
        int x=n->data;
        free(n);
        return  x;
    }
    
}

int peek_Stack(int pos ){
  struct node* ptr=top;
  int i=0;
  while (i<pos-1 && ptr!=NULL)
  {
    ptr=ptr->next;
    i++;
  }
    if (ptr!=NULL)
    {
        return ptr->data;
    }
    else{
        return -1;
    }  
}

int Stack_top(struct node* ptr){
    return ptr->data;
}
int Stack_bottom(struct node* ptr){
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    return ptr->data;
    
}


