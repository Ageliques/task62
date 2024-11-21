// contact_list.h
#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 100
#define MAX_SOCIAL_LENGTH 100

typedef struct Contact {
    char first_name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    char work[MAX_NAME_LENGTH];
    char position[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char social[MAX_SOCIAL_LENGTH];
    struct Contact* next;
    struct Contact* prev; // Добавляем указатель на предыдущий элемент
} Contact;

// Функции для работы со списком
Contact* create_contact();
void add_contact(Contact** head, Contact* new_contact);
void edit_contact(Contact* head, const char* first_name, const char* surname);
void delete_contact(Contact** head, const char* first_name, const char* surname);
void print_contacts(Contact* head); // Прототип функции для вывода контактов
void free_contacts(Contact* head);

#endif // CONTACT_LIST_H
