#include <stdio.h>
#include <stdlib.h>

void addStudent() {
    int roll;
    char name[50];

    FILE *fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", name);

    fprintf(fp, "%d %s\n", roll, name);
    fclose(fp);

    printf("Student added successfully!\n");
}

void markAttendance() {
    int roll;
    char status;

    FILE *fp = fopen("attendance.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("Enter Attendance (P/A): ");
    scanf(" %c", &status);

    fprintf(fp, "%d %c\n", roll, status);
    fclose(fp);

    printf("Attendance marked successfully!\n");
}

void viewAnalytics() {
    int roll, total = 0, present = 0;
    char status;

    FILE *fp = fopen("attendance.txt", "r");
    if (fp == NULL) {
        printf("No attendance data found!\n");
        return;
    }

    while (fscanf(fp, "%d %c", &roll, &status) != EOF) {
        total++;
        if (status == 'P' || status == 'p') {
            present++;
        }
    }

    fclose(fp);

    if (total == 0) {
        printf("No records available.\n");
        return;
    }

    printf("\n--- Attendance Analytics ---\n");
    printf("Total Records: %d\n", total);
    printf("Present Count: %d\n", present);
    printf("Attendance Percentage: %.2f%%\n",
           ((float)present / total) * 100);
}

int main() {
    int choice;

    printf("\n=============================\n");
    printf(" AttendX - Attendance System\n");
    printf("=============================\n");
    printf("1. Add Student\n");
    printf("2. Mark Attendance\n");
    printf("3. View Analytics\n");
    printf("0. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            markAttendance();
            break;
        case 3:
            viewAnalytics();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
