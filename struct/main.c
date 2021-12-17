#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[255];
    unsigned int id;
    double avg;
} Student;

void printStudent(Student ps){
    printf("\nNom : %s", ps.name);
    printf("Id : %u", ps.id);
    printf("\nMoyenne : %lf", ps.avg);
}

void inputStudent(Student *ps){
    fgets(ps->name, 255, stdin);
    if(ps->name[strlen(ps->name) - 1] == '\n')
        ps->name[strlen(ps->name) - 1] == '\0';
    scanf("%u", &ps->id);
    scanf("%lf", &ps->avg);
}

int addStudent(Student ps){
    FILE *fp;
    fp = fopen("students.txt", "ab");
    if(fp == NULL) return 1;

    fseek(fp, 0, SEEK_END);
    fwrite(&ps, sizeof(Student), 1, fp);

    fclose(fp);
    return 0;
}

int readStudent(){
    FILE *fp;
    Student ps;
    fp = fopen("students.txt", "rb");
    if(fp == NULL) return 1;

    fseek(fp, 0, SEEK_SET);
    while(fread(&ps, sizeof(Student), 1, fp)) {
        printStudent(ps);
    }
    fclose(fp);
    return 0;
}

int main() {
    Student s;
    inputStudent(&s);
    printStudent(s);
    addStudent(s);
    readStudent();
    return 0;
}