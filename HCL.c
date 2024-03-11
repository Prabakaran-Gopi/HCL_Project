#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    float salary;
    char work[50];
    char email[50];
    char phone[15];
    char dateOfJoining[15];
};

struct Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

void displayMenu();
void addEmployee();
void displayAllEmployees();
void deleteEmployee();
void updateEmployee();
void searchEmployee();
void displayEmployee(int index);
int isDateValid(char* date);
void showError(char* message);

int main() {
    displayMenu();
    return 0;
}

void displayMenu() {
    int choice;

    do {
        printf("+--------------------------------------+\n");
        printf("|             Menu Options             |\n");
        printf("+--------------------------------------+\n");
        printf("| 1. Add Employee                      |\n");
        printf("| 2. Display All Employees             |\n");
        printf("| 3. Delete Employee                   |\n");
        printf("| 4. Update Employee Profiles          |\n");
        printf("| 5. Search Employee Record            |\n");
        printf("| 6. Exit                              |\n");
        printf("+--------------------------------------+\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayAllEmployees();
                break;
            case 3:
                deleteEmployee();
                break;
            case 4:
                updateEmployee();
                break;
            case 5:
                searchEmployee();
                break;
            case 6:
                printf("Exiting... Thank you!\n");
                break;
            default:
                showError("Invalid choice. Please try again.");
        }
    } while (choice != 6);
}

void addEmployee() {
    struct Employee newEmployee;

    printf("\nEnter employee ID: ");
    scanf("%d", &newEmployee.id);

    printf("Enter employee name: ");
    scanf("%s", newEmployee.name);

    printf("Enter employee salary: ");
    scanf("%f", &newEmployee.salary);

    printf("Enter employee work: ");
    scanf("%s", newEmployee.work);

    printf("Enter employee email: ");
    scanf("%s", newEmployee.email);

    printf("Enter employee phone number: ");
    scanf("%s", newEmployee.phone);

    printf("Enter date of joining (YYYY-MM-DD): ");
    scanf("%s", newEmployee.dateOfJoining);

    employees[numEmployees++] = newEmployee;

    printf("\nEmployee added successfully!\n");
}

void displayAllEmployees() {
    printf("+----+----------------------+------------+----------------------+----------------------+----------------------+----------------------+\n");
    printf("| ID | Name                 | Salary     | Work                 | Email                | Phone                | Date of Joining     |\n");
    printf("+----+----------------------+------------+----------------------+----------------------+----------------------+----------------------+\n");

    for (int i = 0; i < numEmployees; i++) {
        printf("| %-2d | %-20s | %-10.2f | %-20s | %-20s | %-20s | %-20s |\n", employees[i].id, employees[i].name, employees[i].salary, employees[i].work, employees[i].email, employees[i].phone, employees[i].dateOfJoining);
    }

    printf("+----+----------------------+------------+----------------------+----------------------+----------------------+----------------------+\n");
}

void deleteEmployee() {
    int empId;

    printf("\nEnter the ID of the employee to delete: ");
    scanf("%d", &empId);

    int found = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == empId) {
            found = 1;
            for (int j = i; j < numEmployees - 1; j++) {
                employees[j] = employees[j+1];
            }
            numEmployees--;
            printf("\nEmployee with ID %d deleted successfully.\n", empId);
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", empId);
    }
}

void updateEmployee() {
    int empId;

    printf("\nEnter the ID of the employee to update: ");
    scanf("%d", &empId);

    int found = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == empId) {
            found = 1;

            printf("\nEnter new ID: ");
            scanf("%d", &employees[i].id);

            printf("Enter new name: ");
            scanf("%s", employees[i].name);

            printf("Enter new salary: ");
            scanf("%f", &employees[i].salary);

            printf("Enter new work: ");
            scanf("%s", employees[i].work);

            printf("Enter new email: ");
            scanf("%s", employees[i].email);

            printf("Enter new phone number: ");
            scanf("%s", employees[i].phone);

            printf("Enter new date of joining (YYYY-MM-DD): ");
            scanf("%s", employees[i].dateOfJoining);

            printf("\nEmployee details updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", empId);
    }
}

void searchEmployee() {
    int empId;

    printf("\nEnter the ID of the employee to search: ");
    scanf("%d", &empId);

    int found = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == empId) {
            found = 1;
            displayEmployee(i);
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", empId);
    }
}

void displayEmployee(int index) {
    printf("\nEmployee Details:\n");
    printf("+----+----------------------+------------+----------------------+----------------------+----------------------+----------------------+\n");
    printf("| ID | Name                 | Salary     | Work                 | Email                | Phone                | Date of Joining     |\n");
    printf("+----+----------------------+------------+----------------------+----------------------+----------------------+----------------------+\n");
    printf("| %-2d | %-20s | %-10.2f | %-20s | %-20s | %-20s | %-20s |\n", employees[index].id, employees[index].name, employees[index].salary, employees[index].work, employees[index].email, employees[index].phone, employees[index].dateOfJoining);
    printf("+----+----------------------+------------+----------------------+----------------------+----------------------+----------------------+\n");
}

int isDateValid(char* date) {
    if (strlen(date) != 10) {
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (date[i] != '-') return 0;
        } else if (date[i] < '0' || date[i] > '9') {
            return 0;
        }
    }
    return 1;
}

void showError(char* message) {
    printf("\nError: %s\n", message);
}
