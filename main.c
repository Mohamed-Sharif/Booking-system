#include<string.h>
#include "header.h"
int main(void)
{
    system("color Fc");
    client_list *list = NULL;
	u8 name[SIZE]={0};
	u8 age[SIZE]={0};
	u8 id[SIZE]={0};
	u8 address[SIZE]={0};
	u8 phone[SIZE]={0};
	u8 seat_class[SIZE]={0};
	u32 seat_no[SIZE]={0};
	u32 i=0, j=0,k=0,l=0,choice=0;
	list = CreateList();
	main_menu();
	while (1)
	{
	printf("What do you want to do? ");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
        ClientList(list);
        break;
    case 2:
        printf("Enter the Client name: ");
        fflush(stdin);
        scanf("%s",name);
        printf("Enter the client's age: ");
        scanf("%s",age);
        fflush(stdin);
        printf("Enter the Client's ID: ");
        scanf("%s",id);
        fflush(stdin);
        printf("Enter the client's address: ");
        scanf("%s",address);
        fflush(stdin);
        printf("Enter the client's Phone Number: ");
        scanf("%s",phone);
        fflush(stdin);
        printf("Enter the client's seat Class (A-B-C): ");
        scanf("%s",seat_class);
        fflush(stdin);
        printf("Enter the Client's Seat number: ");
        scanf("%s",seat_no);
        fflush(stdin);
        if(New_Client(list,name,age,id,address,phone,seat_class,seat_no) == RET_OK)
				{
					printf("Booking completed\n");
				}
        else
                {
					printf("Client was not added. Please, try again");
                }
        break;

    case 3:
        if(Delete_Client(list)==RET_OK)
            {
                printf("The Client has been deleted successfully\n");
            }
        else
            {
                printf("Please, try again later.\n");
            }
        break;
    case 4:
        if(Free_seats(list,&j)== RET_OK)
				{
					printf("The total registered clients are: %d\n",j);
                    printf("The total available seats are: %d seats\n",plane_size-j);
				}
        break;
    case 5:
        	if(Client_Edit(list,&k,&l)==RET_OK)
				{
					printf("Client info has been updated");
				}
        break;
    case 6:
        printf("Exiting....");
        free(list);
        exit(0);
        break;

case 7:
        main_menu();
        break;
    default:
        printf("You entered wrong number");
        break;
    }
}
}
