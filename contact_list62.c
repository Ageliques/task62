// contact_list.c
#include "contact_list.h"

Contact* create_contact() {
    Contact* new_contact = (Contact*)malloc(sizeof(Contact));
    if (new_contact == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return new_contact;
}

void add_contact(Contact** head, Contact* new_contact) {
    new_contact->next = NULL;
    new_contact->prev = NULL;

    if (*head == NULL) {
        *head = new_contact;
    } else {
        Contact* current = *head;
        while (current != NULL && strcmp(current->surname, new_contact->surname) < 0) {
            current = current->next;
        }
        if (current == *head) {
            new_contact->next = *head;
            (*head)->prev = new_contact;
            *head = new_contact;
        } else if (current == NULL) {
            Contact* last = *head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = new_contact;
            new_contact->prev = last;
        } else {
            new_contact->next = current;
            new_contact->prev = current->prev;
            current->prev->next = new_contact;
            current->prev = new_contact;
        }
    }
}

void edit_contact(Contact* head, const char* first_name, const char* surname) {
    Contact* current = head;

    while (current != NULL) {
        if (strcmp(current->first_name, first_name) == 0 && strcmp(current->surname, surname) == 0) {
            printf("Editing contact: %s %s\n", current->first_name, current->surname);

            printf("Enter a new phone number (leave it empty to save): ");
            fgets(current->phone, MAX_PHONE_LENGTH, stdin);
            current->phone[strcspn(current->phone, "\n")] = 0;

            printf("Enter a new email address (leave it empty to save): ");
            fgets(current->email, MAX_EMAIL_LENGTH, stdin);
            current->email[strcspn(current->email, "\n")] = 0;

            printf("Enter a new social network link (leave it empty to save): ");
            fgets(current->social, MAX_SOCIAL_LENGTH, stdin);
            current->social[strcspn(current->social, "\n")] = 0;

            printf("Contact updated successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Contact not found.\n");
}

void delete_contact(Contact** head, const char* first_name, const char* surname) {
    Contact* current = *head;

    while (current != NULL) {
        if (strcmp(current->first_name, first_name) == 0 && strcmp(current->surname, surname) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next; // Удаляем первый элемент
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            printf("Contact deleted successfully.\n");
            return;
        }
        current = current->next;
    }
    printf("Contact not found.\n");
}

void free_contacts(Contact* head) {
    Contact* current = head;
    while (current != NULL) {
        Contact* next_contact = current->next;
        free(current);
        current = next_contact;
    }
}

void print_contacts(Contact* head) {
    if (head == NULL) {
        printf("Contact list is empty.\n");
        return;
    }

    Contact* current = head;
    printf("Contacts:\n");
    while (current != NULL) {
        printf("Name: %s %s %s\n", current->first_name, current->surname, current->last_name);
        printf("Work: %s, Position: %s\n", current->work, current->position);
        printf("Phone: %s\n", current->phone);
        printf("Email: %s\n", current->email);
        printf("Social: %s\n", current->social);
        printf("-----------------------------\n");
        current = current->next;
    }
}
