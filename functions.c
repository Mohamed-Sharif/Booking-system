// including necessary libraries and files: string lib and the header file
#include<string.h>
#include"header.h"
// main_menu function for showing the targeted activities and the welcome screen
void main_menu(void)
{
    printf("\n\n\t\tThe Flight Booking System \n\n");
    printf("----------------------------------------------------------\n");
    printf("----------------------------------------------------------\n");
    printf("Welcome, pal.\nWhat would you like to do?\n");
    printf("Please, read the following points and type the corresponding number.\n");
    printf("Press:\n");
    printf("\t[1] to view all clients registered\n");
    printf("\t[2] to add a new client\n");
    printf("\t[3] to delete a client\n");
    printf("\t[4] to get the number of clients and the available seats\n");
    printf("\t[5] to edit a client\n");
    printf("\t[6] to exit and close the console\n");
    printf("\t[7] to go back the main menu\n");
}

// creating list of clients
client_list *CreateList(void)
{
	client_list *List = (client_list *)malloc(sizeof(client_list));
	if(NULL == List)
	{
		printf("Error: malloc failed to create your list !!!\n");
		return NULL;
	}
	else{
		List->Size = 0;
		List->Next_n = NULL;
		List->Previous_n = NULL;
	}
	return List;
}

// displaying the list of client
list_satus ClientList(client_list *List)
{
	list_satus ReturnStatus = RET_OK;
	if(NULL == List)
	{
		printf("You Passed a NULL. \n");
		ReturnStatus = RET_NOK;
	}
	else{
		if(0 == (List->Size))
		{
			printf("You have not added anyone yet, and the list is empty !!!\n");
			ReturnStatus = RET_NOK;
		}
		else{
				u32 i=0;
				node_t* temp= List->Next_n;
				for(i=0;i<List->Size;i++)
				{
					printf("Client No. :%d\n",i+1);
					printf("Client Name: %s\n",temp->name);
					printf("Client identity: %s\n",temp->id);
					printf("Client age: %s\n",temp->age);
					printf("Client phone: %s\n",temp->phone);
					printf("Client seat_Class: %s\n",temp->seat_class);
					printf("Client Seat number: %s\n",temp->seat_no);
					printf("--------------------------------\n");
					temp= temp->Next;
				}
		}
		return ReturnStatus;
	}
}
// adding a client
list_satus New_Client(client_list *List, u8 *name, u8 *age, u8 *id, u8 *address,
                   u8 *phone, u8 *seat_class, u32 seat_no)
{
    list_satus ReturnStatus = RET_OK;
	if(NULL == List)
	{
		printf("You Passed a NULL. \n");
		ReturnStatus = RET_NOK;
	}
	else
        {
		node_t *NodePtr = (node_t *)malloc(sizeof(node_t));
		if(NULL == NodePtr)
            {
                printf("Sorry, we couldn't add this client !!!\n");
                ReturnStatus = RET_NOK;
            }
		else if (List_Empty(List) ==  LIST_EMPTY)
			{
				List->Next_n = NodePtr;
				List->Previous_n = NodePtr;
				NodePtr->Previous = NULL;
			}
        else
            {
				NodePtr->Previous = List->Previous_n;
				List->Previous_n->Next = NodePtr;
				List->Previous_n = NodePtr;
			}
            strcpy(NodePtr->name, name);
			strcpy(NodePtr->age, age);
			strcpy(NodePtr->id, id);
			strcpy(NodePtr->address, address);
            strcpy(NodePtr->phone, phone);
			strcpy(NodePtr->seat_class, seat_class);
			strcpy(NodePtr->seat_no, seat_no);
			NodePtr->Next=NULL;
			List->Size++;
        }
    return ReturnStatus;
}
// Check if the list is empty or not
static ListState_t List_Empty(client_list *List)
{
    if(NULL == List)
	{
		printf("Empty list.!!!\n");
	}
	else
        {
		ListState_t ReturnState = LIST_NEMPTY;
		if(0 == (List->Size))
            {
                ReturnState = LIST_EMPTY;
            }
		return ReturnState;
	}
}
// delete a client
list_satus Delete_Client(client_list *List)
{
    list_satus ReturnStatus = RET_NOK;
	node_t *BufferPtr = NULL;
	if(NULL == List)
	{
		printf("Nothing to delete (Nothing was passed) !!!\n");

	}
	else{
		if(List_Empty(List) == LIST_EMPTY)
		{
			printf("Empty list, nothing to delete !!!!\n");
		}
		else{
			BufferPtr = List->Next_n;
			s32 i;
			printf("please enter Client Number you want to delete from (1 : %d): ",List->Size);
			scanf("%d", &i);
			if (i > List->Size || i<=0)
			{
				printf("This client number doesn't exist");
				fflush(stdin);
				scanf("%d", &i);
			}
			else if(1 == (List->Size))
			{
				List->Next_n = NULL;
				List->Previous_n = NULL;
			}
			else if (i == 1)//first
			{
				List->Next_n = List->Next_n->Next;
				List->Next_n->Previous = NULL;
			}
			else if(i == (List->Size))//last
			{
				BufferPtr=List->Previous_n;
				List->Previous_n= List->Previous_n->Previous;
				List->Previous_n->Next= NULL;
			}
			else{
				u32 j =0;
				for(j=0; j<i-1; j++)
				{
					BufferPtr=BufferPtr->Next;
				}
				BufferPtr->Previous->Next = BufferPtr->Next;
				BufferPtr->Next->Previous= BufferPtr-> Previous;
			}
			free(BufferPtr);
			List->Size--;
			ReturnStatus = RET_OK;
		}
		return ReturnStatus;
	}
}
// viewing client data
list_satus Free_seats(client_list *List, u32 *i)
{
    list_satus ReturnStatus = RET_OK;
	if(NULL == List)
	{
		printf("You passed nothing (Null entry) !!!\n");
		ReturnStatus = RET_NOK;
	}
	else
        {
            if(List_Empty(List) == LIST_EMPTY)
            {
                printf("There are no registered clients\n");
                printf("There are a total of %d available seats\n", plane_size);
                ReturnStatus = RET_NOK;
            }
            else
            {
                *i = List->Size;
            }
        }
	return ReturnStatus;
}
// Editing client data
list_satus Client_Edit(client_list *List, u32 *k,u32 *choice)
{
    list_satus ReturnStatus = RET_NOK;
	node_t *Buffer = NULL;
	if(NULL == List)
        {
            printf("You passed nothing (Null entry) !!!\n");
        }
    else if(List_Empty(List) == LIST_EMPTY)
        {
            printf("Empty list, nothing to edit !!!!\n");
        }
    else
        {
            Buffer = List->Next_n;
			s32 i;
			printf("Which client number do you want to edit? range is (1 : %d): ",List->Size);
			scanf("%d", &i);
			if (i > List->Size || i<=0)
                {
				printf("This client number doesn't exist");
				fflush(stdin);
				scanf("%d", &i);
                }
            else{
                    u32 j=0;
                    node_t* Buffer= List->Next_n;
                   for(j=0;(j<List->Size)&&(choice);j++)
                        {
                        printf("[1] Enter the name please \n");
                        printf("[2] Enter the identity please \n");
                        printf("[3] Enter the phone please \n");
                        printf("[4] Enter the age please \n");
                        printf("[5] Enter the seat Class please \n");
                        printf("[6] Enter the seat number please \n");
                        printf("[any other number] Exit \n");
                        printf("Enter the corresponding number:");
                        scanf("%d",&choice);

                        if(choice == 1)
                            {
                                fflush(stdin);
                                printf("The Client's new name is: ");
                                gets(Buffer->name);
                            }
                        else if(choice == 2)
                            {
                                fflush(stdin);
                                printf("The client's new identity is: ");
                                gets(Buffer->id);
                            }
                        else if(choice == 3)
                            {
                                fflush(stdin);
                                printf("The client's new phone is: ");
                                gets(Buffer->phone);
                            }
                        else if(choice == 4)
                            {
                                fflush(stdin);
                                printf("The client's new age is: ");
                                gets(Buffer->age);
                            }
                        else if(choice == 5)
                            {
                                fflush(stdin);
                                printf("The client's new seat class is: ");
                                gets(Buffer->seat_class);
                            }
                        else if(choice == 6)
                            {
                                fflush(stdin);
                                printf("The client's new seat number is: ");
                                gets(Buffer->seat_no);
                            }
                        else
                        {
                            break;
                        }
                      }
		}
	}	return ReturnStatus;
}
