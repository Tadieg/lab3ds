#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last,*secondlist,*list,*list_last;
void createList(int n,int s);
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtN(int data, int position);
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromN(int position);
void search();
void concatenate();
int main()
{
    int n, data, choice=1;
    head = NULL;
    last = NULL;
    while(choice != 0)
    {
        printf("1. Create List\n");
        printf("2. Insert node  at beginning\n");
        printf("3. Insert node  at the end\n");
        printf("4. Insert node  at any position\n");
        printf("5. delete node  at beginning\n");
        printf("6. delete node  at the end\n");
        printf("7. delete node  at any position\n");
        printf("8. to search an item\n");
        printf("9. to concatenate\n");
        printf("10. Display list\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        int s=0;
        switch(choice)
        {
            case 1:
            	
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n,s);
                break;
            case 2:
                printf("Enter data of first node : ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data of last node : ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                printf("Enter the position where you want to insert new node: ");
                scanf("%d", &n);
                printf("Enter data of %d node : ", n);
                scanf("%d", &data);
                insertAtN(data, n);
                break;
             case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                printf("Enter the node position which you want to delete: ");
                scanf("%d", &n);
                deleteFromN(n);
                break;
            case 8:
                search();
                break;
             case 9:
             	s=1;
                printf("how many nodes you want for the second list");
                scanf("%d", &n);
                createList(n,s);
                concatenate();
                break;
            case 10:
                displayList();
                break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-5");
        }

        printf("\n\n");
    }

    return 0;
}
void createList(int n,int s)
{
    int i, data;
    struct node *newNode;
    
    if(n >= 1&&s==0)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of 1 node: ");
        scanf("%d", &data);
        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        last = head;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of %d node: ", i);
            scanf("%d", &data);
            newNode->data = data;
            newNode->prev = last; 
            newNode->next = NULL;
            last->next = newNode;
            last = newNode;  
        }
        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }else{
        secondlist = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of 1 node: ");
        scanf("%d", &data);
         secondlist->data = data;
         secondlist->prev = NULL;
         secondlist->next = NULL;
         last = secondlist;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of %d node: ", i);
            scanf("%d", &data);
            newNode->data = data;
            newNode->prev = last; 
            newNode->next = NULL;
            last->next = newNode;
            last = newNode;  
        }
        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");	
	}
}
void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");
        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);
            n++;
            temp = temp->next;
        }
    }
}
void insertAtBeginning(int data)
{
    struct node * newNode;

    if(head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
    }
}
void insertAtEnd(int data)
{
    struct node * newNode;

    if(last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;

        last->next = newNode;
        last = newNode;

        printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST\n");
    }
}

void insertAtN(int data, int position)
{
    int i;
    struct node * newNode, *temp;
    if(head == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        temp = head;
        i=1;
        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }
        if(position == 1)
        {
            insertAtBeginning(data);
        }
        else if(temp == last)
        {
            insertAtEnd(data);
        }
        else if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = data;
            newNode->next = temp->next; 
            newNode->prev = temp;         

            if(temp->next != NULL)
            {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
    }
}
void deleteFromBeginning()
{
    struct node * toDelete;

    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;

        head = head->next; // Move head pointer to 2 node
        
        if (head != NULL)
            head->prev = NULL; // Remove the link to previous node

        free(toDelete); // Delete the first node from memory
        printf("SUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST.\n");
    }
}


/**
 * Delete or remove the last node of the doubly linked list
 */
void deleteFromEnd()
{
    struct node * toDelete;

    if(last == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = last;
        last = last->prev; 
        if (last != NULL)
            last->next = NULL; 
        free(toDelete); 
        printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
    }
}
void deleteFromN(int position)
{
    struct node *current;
    int i;
    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }
    if(position == 1)
    {
        deleteFromBeginning();
    }
    else if(current == last)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current); // Delete the n node
        printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", position);
    }
    else
    {
        printf("Invalid position!\n");
    }
}
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nitem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}  
void concatenate() {
   struct node *link;
   list = head;
   link = list;
   while(link->next!= NULL) {
      link = link->next;
   }
   link->next = secondlist;
   secondlist->prev = link;
   while(link->next!= NULL) {
      link = link->next;
   }
   list_last = link;  
}
