#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node *head = NULL;

struct user {
  char* name;
  int id;
  int* friends;
};

struct node {
  struct user user;
  struct node *next;
};

void addUser(int count)
{
    head = (struct node*) malloc(sizeof(struct node));
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    char* name;

    printf("Please enter a name");
    scanf(" %s", name);

    temp->next = (struct node*) malloc(sizeof(struct node));
    temp->next->user.id = count;
    strcpy(temp->next->user.name, name);
    temp->next->next = NULL;
}

int main(void)
{
    head = (struct node*) malloc(sizeof(struct node));
    if (head == NULL) {
    return 1;
    }
    head->user.id = 0;
    head->user.name = "";
    head->next = NULL;

    int count = 1;
    char choice = 'y';
    addUser(count);
    printf("xx%d %s", head->next->user.id, head->next->user.name);
}

/*
    while(choice == 'y')
    {
        printf("add a user\n");
        addUser(count);
        count++;
        printf("do you want to go again?\n");
        scanf(" %c", &choice);
    }
    printf("xx%d %s", head->next->next->user.id, head->next->next->user.name);*/