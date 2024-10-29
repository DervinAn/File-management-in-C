#include <stdio.h>
#include <stdlib.h>




#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int age;
    char specialty[50];
};

int main() {

 int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct student students[numStudents];

    // Input student information
    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter information for student %d:\n", i + 1);
        printf("Enter student name: ");
        scanf("%s", students[i].name);

        printf("Enter student age: ");
        scanf("%d", &students[i].age);

        printf("Enter student specialty: ");
        scanf("%s", students[i].specialty);
    }

    // Open file for writing in binary mode
    FILE *file = fopen("students.bin", "ab");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Write student information to the file
    fwrite(students, sizeof(struct student), numStudents, file);

    // Close the file
    fclose(file);

FILE* infile;
infile = fopen("students.bin", "rb");
if (infile == NULL) {
    printf("there an issue in opening file");
}
struct student read_student;

  while (fread(&read_student, sizeof(struct student), 1, infile) == 1) {
    printf("\nName: %s\nAge: %d\nSpecialty: %s\n", read_student.name, read_student.age, read_student.specialty);
    }

    fclose(infile);

    return 0;
}
