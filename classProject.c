#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct Student{
    char name[20];
    int id;
    int grade;
};

void add_student(){
    struct Student new_student;

    printf("Enter Name: ");
    fgets(new_student.name, 20, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = 0;

    printf("Enter ID: ");
    scanf("%d", &new_student.id);

    printf("Enter Grade: ");
    scanf("%d", &new_student.grade);
    getchar();

    // STEP 2
    FILE *f = fopen("classdata.txt", "a");

    if(f == NULL){
        printf("ERROR: Student details could not be created\n");
    }

    fprintf(f, "%s %d %d\n", new_student.name, new_student.id, new_student.grade);
    fclose(f);

    printf("Student details saved successfully\n");
}

void view_all(){
    struct Student temp;
    FILE *f = fopen("classdata.txt", "r");

    if(f == NULL){
        printf("ERROR: No data found. Please add student first\n");
        return;
    }

    printf("\n\t\t-----> CLASS ROSTER <-----\n");
    printf("Name\t|Student ID\t|Student Grade\n\n");


    while( fscanf(f, "%s %d %d", temp.name, &temp.id, &temp.grade) != EOF){
        printf("%s\t|%d\t|%d\n", temp.name, temp.id, temp.grade);
    }

    fclose(f);
    printf("\n\t\t* * * * * * * * * *\n\n");
}

void find_top_student(){
    
    struct Student temp;
    struct Student best;

    best.grade = -100;

    FILE *f = fopen("classdata.txt", "r");

    if(f == NULL){
        printf("\t\t(No data found ...)");
        return;
    }

    printf("\t\tBEST OVERALL STUDENT\n\n");

    while(fscanf(f,"%s %d %d", temp.name, &temp.id, &temp.grade) != EOF){

        if(temp.grade > best.grade){
            best.grade = temp.grade;
            strcpy(best.name, temp.name);
            best.id = temp.id;
        }

    }

    fclose(f);

    printf("Name\t|Student ID\t|Student Grade\n");
    printf("%s\t|%d\t|%d%%\n\n",best.name, best.id, best.grade);
}

int main(){
    int choice;

    while(1){
        printf("\t\tCLASSROOM MANAGER\n");
        printf("1. Add Student\n");
        printf("2. View All Grades\n");
        printf("3. Find Top Student\n");
        printf("0. Exit\n\n");
        printf("Select: ");

        scanf("%d",&choice);
        getchar();

        if (choice == 1) add_student();
        else if(choice == 2) view_all();
        else if(choice == 3) find_top_student();
        else if(choice == 0) break;
    }
    return 0;
}