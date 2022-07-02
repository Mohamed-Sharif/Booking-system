#ifndef HEADER
#define HEADER
// Including the required files and libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdtype.h"
// defining the null pointer to 0 value
#ifndef NULL
#define NULL ((void *)0)
#endif
// defining size
#define SIZE		30
#define plane_size  287 // Airbus guidelines
// defining data structure for clients
// the data structure is doubly linked list
typedef struct node{
	u8 name[SIZE];
	u8 age[SIZE];
	u8 id[SIZE];
	u8 address[SIZE];
	u8 phone[SIZE];
    u8 seat_class[SIZE]; // either A, B, or C class
	u8 seat_no[SIZE];
	struct node *Next;
	struct node *Previous;
}node_t;


typedef struct List{
	u32 Size;
	node_t *Next_n;
	node_t *Previous_n;
}client_list;

typedef enum{
	LIST_EMPTY,
	LIST_NEMPTY
}ListState_t;

typedef enum{
	RET_NOK,
	RET_OK
}list_satus;

// defining function (main_menu) to show welcome screen and the targeted activities
void main_menu(void);
// creating list of clients
client_list *CreateList(void);
// displaying the list of the clients
list_satus ClientList(client_list *List);
// adding client to the list
list_satus New_Client(client_list *List, u8 *name, u8 *birth, u8 *identity,
                 u8 *address, u8 *phone, u8 *seat_class, u32 seat);
// checking the state of the list (empty or not)
static ListState_t List_Empty(client_list *List);
// deleting a client
list_satus Delete_Client(client_list *List);
// viewing the number of client
list_satus Free_seats(client_list *List, u32 *i);
// editing client
list_satus Client_Edit(client_list *List, u32 *k,u32 *l);


#endif
