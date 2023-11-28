#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    char address[50];
};

void displayStudent(struct Student student, int studentNumber) {
    printf("Student %d Information:\n", studentNumber);
    printf("Id: %d\n", student.id);
    printf("Name: %s\n", student.name);
    printf("Address: %s\n\n", student.address);
}

void writeToFile(struct Student *students, int numStudents, const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%d %s %s\n", students[i].id, students[i].name, students[i].address);
    }

    fclose(file);
}

void readFromFile(struct Student *students, int numStudents, const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file for reading.\n");
        exit(1);
    }

    for (int i = 0; i < numStudents; i++) {
        fscanf(file, "%d %s %s", &students[i].id, students[i].name, students[i].address);
    }

    fclose(file);
}

void modifyStudent(struct Student *student) {
    printf("Enter the new name: ");
    scanf("%s", student->name);

    printf("Enter the new address: ");
    scanf(" %s", student->address);
}

int main() {
    const int MAX_STUDENTS = 2;

    struct Student students[MAX_STUDENTS];

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Enter student ID, name, and address for student %d: ", i + 1);
        scanf("%d %s %s", &students[i].id, students[i].name, students[i].address);
    }

    writeToFile(students, MAX_STUDENTS, "students.txt");

    for (int i = 0; i < MAX_STUDENTS; i++) {
        displayStudent(students[i], i + 1);
    }

    readFromFile(students, MAX_STUDENTS, "students.txt");

    int studentToModify;
    printf("Enter the student number to modify (1-%d): ", MAX_STUDENTS);
    scanf("%d", &studentToModify);

    if (studentToModify >= 1 && studentToModify <= MAX_STUDENTS) {
        modifyStudent(&students[studentToModify - 1]);
    } else {
        printf("Invalid student number.\n");
    }

    for (int i = 0; i < MAX_STUDENTS; i++) {
        displayStudent(students[i], i + 1);
    }

    return 0;
}
