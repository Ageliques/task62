// main.c
#include "contact_list.h"

int main() {
    Contact* head = NULL;
    int choice;
    char first_name[MAX_NAME_LENGTH], surname[MAX_NAME_LENGTH];

    while (1) {
        printf("1. Add Contact\n");
        printf("2. Edit Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Print Contacts\n"); // Новая опция для вывода контактов
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Для очистки буфера после scanf

        switch (choice) {
            case 1: {
                Contact* new_contact = create_contact();
                
                printf("Enter first name: ");
                fgets(new_contact->first_name, MAX_NAME_LENGTH, stdin);
                new_contact->first_name[strcspn(new_contact->first_name, "\n")] = 0;

                printf("Enter surname: ");
                fgets(new_contact->surname, MAX_NAME_LENGTH, stdin);
                new_contact->surname[strcspn(new_contact->surname, "\n")] = 0;

                printf("Enter last name: ");
                fgets(new_contact->last_name, MAX_NAME_LENGTH, stdin);
                new_contact->last_name[strcspn(new_contact->last_name, "\n")] = 0;

                printf("Enter work: ");
                fgets(new_contact->work, MAX_NAME_LENGTH, stdin);
                new_contact->work[strcspn(new_contact->work, "\n")] = 0;

                printf("Enter position: ");
                fgets(new_contact->position, MAX_NAME_LENGTH, stdin);
                new_contact->position[strcspn(new_contact->position, "\n")] = 0;

                printf("Enter phone number: ");
                fgets(new_contact->phone, MAX_PHONE_LENGTH, stdin);
                new_contact->phone[strcspn(new_contact->phone, "\n")] = 0;

                printf("Enter email address: ");
                fgets(new_contact->email, MAX_EMAIL_LENGTH, stdin);
                new_contact->email[strcspn(new_contact->email, "\n")] = 0;

                printf("Enter social network link: ");
                fgets(new_contact->social, MAX_SOCIAL_LENGTH, stdin);
                new_contact->social[strcspn(new_contact->social, "\n")] = 0;

                add_contact(&head, new_contact);
                break;
            }
            case 2:
                printf("Enter the first name of the contact to edit: ");
                fgets(first_name, MAX_NAME_LENGTH, stdin);
                first_name[strcspn(first_name, "\n")] = 0; // Удаляем символ новой строки

                printf("Enter the surname of the contact to edit: ");
                fgets(surname, MAX_NAME_LENGTH, stdin);
                surname[strcspn(surname, "\n")] = 0; // Удаляем символ новой строки

                edit_contact(head, first_name, surname);
                break;
            case 3:
                printf("Enter the first name of the contact to delete: ");
                fgets(first_name, MAX_NAME_LENGTH, stdin);
                first_name[strcspn(first_name, "\n")] = 0; // Удаляем символ новой строки

                printf("Enter the surname of the contact to delete: ");
                fgets(surname, MAX_NAME_LENGTH, stdin);
                surname[strcspn(surname, "\n")] = 0; // Удаляем символ новой строки

                delete_contact(&head, first_name, surname);
                break;
            case 4:
                print_contacts(head); // Вызов функции для вывода контактов
                break;
            case 5:
                free_contacts(head);
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
