#include  <stdio.h>
    #include  <stdlib.h>
    void insert(int);  
    void delete();  
    struct node  
    {  
        int data;  
        struct node *next;  
    };  
    struct node *head;  
    void main ()  
    {  
        int choice,item;  
        do   
        {  
            printf("\n1.Insert a node\n2.Delete a node\n3.Exit\n4.Enter your choice?");  
            scanf("%d",&choice);  
            switch(choice)  
            {  
                case 1:  
                printf("\nEnter the item\n");  
                scanf("%d",&item);  
                insert(item);  
                break;   
                case 2:  
                delete();  
                break;   
                case 3:  
                exit(0);  
                break;    
                default:  
                printf("\nPlease enter a valid choice\n");  
            }

        }while(choice != 3);  
    }  
    void insert(int item)  
        {  
            struct node *ptr = (struct node *)malloc(sizeof(struct node *));  
            if(ptr == NULL)  
            {  
                printf("\nOVERFLOW\n");  
            }  
            else  
            {  
                ptr->data = item;  
                ptr->next = head;  
                head = ptr;  
                printf("\nNode inserted\n");  
            }  

        }  
    void delete()  
        {  
            struct node *ptr,*ptr1;  
            if(head == NULL)  
            {  
                printf("\nlist is empty");  
            }  
            else if(head -> next == NULL)  
            {  
                head = NULL;  
                free(head);  
                printf("\nOnly node of the list deleted ...");  
            }  

            else  
            {  
                ptr = head;   
                while(ptr->next != NULL)  
                    {  
                        ptr1 = ptr;  
                        ptr = ptr ->next;  
                    }  
                    ptr1->next = NULL;  
                    free(ptr);  
                    printf("\n Deleted Node from the last ...");  
                }     
            }