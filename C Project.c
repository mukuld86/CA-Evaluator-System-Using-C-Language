#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void create_record();
void search_record();
void modify_record();
void delete_record();
void display_records();

struct student {
    char name[50];
    int id;
    char course[50];
    float ca_score;
};

int main() {
    int choice;
    while(1) {
        printf("\n\n \tCA EVALUATOR SYSTEM\t \n\n");
        printf("1. Create Record\n");
        printf("2. Search Record\n");
        printf("3. Modify Record\n");
        printf("4. Delete Record\n");
        printf("5. Display Records\n");
        printf("6. Exit\n");
        printf("Make a choice (1-6): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                create_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                modify_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                display_records();
                break;
            case 6:
                printf("\GoodBye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a valid choice (1-6).\n");
        }
    }
    return 0;
}

void create_record() {
    struct student s;
    FILE *fp;
    // Opening the file in read and append mode
    fp = fopen("ca_records.txt", "a+");
    // Taking the details as input from the user
    printf("\nEnter student ID: ");
    scanf("%d", s.id);
    printf("\nEnter student name: ");
    scanf("%s", s.name);
    printf("\nEnter course name: ");
    scanf("%s", s.course);
    printf("\nEnter CA score: ");
    scanf("%f", &s.ca_score);
    fprintf(fp, "%s %d %s %.2f\n", s.name, s.id, s.course, s.ca_score);
    printf("\nRecord created successfully!\n");
    fclose(fp);
}

void display_records() {
    struct student s;
    FILE *fp;
    // Opening the file in read mode
    fp = fopen("ca_records.txt", "r");

    printf("\n%-20s%-10s%-20s%-10s\n", "ID", "Name", "Course", "CA Score");
    while(fscanf(fp, "%s %d %s %f\n", s.name, &s.id, s.course, &s.ca_score) != EOF) { // EOF is a constant defined in standard library to denote End of file
        printf("%-20d%-10s%-20s%-10.2f\n", s.id, s.name, s.course, s.ca_score);
    }
    fclose(fp);
}

void delete_record() {
    struct student s;
    FILE *fp, *temp;
    int search_id;
    int found = 0;
    // Opening the file in read mode
    fp = fopen("ca_records.txt", "r");
    temp = fopen("temp.txt", "w");
    // Taking the Student Id as input
    printf("\nEnter the Id of the student to delete: ");
    scanf("%d",& search_id);
    while(fscanf(fp, "%s %d %s %f\n", s.name, &s.id, s.course, &s.ca_score) != EOF) {// EOF is a constant defined in standard library to denote End of file
        if(search_id == s.id) {
            found = 1;
            printf("\n%-20s%-10s%-20s%-10s\n", "Name", "ID", "Course", "CA Score");
            printf("%-20s%-10d%-20s%-10.2f\n", s.name, s.id, s.course, s.ca_score);
        } else {
            fprintf(temp, "%s %d %s %.2f\n", s.name, s.id, s.course, s.ca_score);
        }
    }
    if(!found) {
        printf("\nNo Record found!\n");
    } else {
        fclose(fp);
        fclose(temp);
        remove("ca_records.txt");
        rename("temp.txt", "ca_records.txt");
        printf("\nRecord deleted successfully!\n");
    }
}

void modify_record() {
    struct student s;
    FILE *fp, *temp;
    int search_id;
    int found = 0;
    // Opening the file in read mode
    fp = fopen("ca_records.txt", "r");
    // Opening a temporary file in write mode
    temp = fopen("temp.txt", "w");
    // Taking the Student id as input
    printf("\nEnter the ID of the student to modify: ");
    scanf("%d",&search_id);
    while(fscanf(fp, "%s %d %s %f\n", s.name, &s.id, s.course, &s.ca_score) != EOF) {// EOF is a constant defined in standard library to denote End of file
        if(search_id == s.id) {
            found = 1;
            printf("\n%-20s%-10s%-20s%-10s\n", "Name", "ID", "Course", "CA Score");
            printf("%-20s%-10d%-20s%-10.2f\n", s.name, s.id, s.course, s.ca_score);
            printf("\nEnter new CA score: ");
            scanf("%f", &s.ca_score);
        }
        fprintf(temp, "%s %d %s %.2f\n", s.name, s.id, s.course, s.ca_score);
    }
    if(!found) {
        printf("\nNo Record found!\n");
    } else {
        fclose(fp);
        fclose(temp);
        remove("ca_records.txt");
        rename("temp.txt", "ca_records.txt");
        printf("\Modified the record successfully!\n");
    }
}

void search_record() {
    struct student s;
    FILE *fp;
    int search_id;
    int found = 0;
    // Opening the file in read mode
    fp = fopen("ca_records.txt", "r");
    // taking the Student id as input
    printf("\nEnter the Id of the student to search: ");
    scanf("%d",&search_id);
    while(fscanf(fp, "%s %d %s %f\n", s.name, &s.id, s.course, &s.ca_score) != EOF) {// EOF is a constant defined in standard library to denote End of file
        if( search_id == s.id) {
            found = 1;
            printf("\n%-20s%-10s%-20s%-10s\n", "ID", "Name", "Course", "CA Score");
            printf("%-20d%-10s%-20s%-10.2f\n", s.id, s.name, s.course, s.ca_score);
            break;
        }
    }
    if(!found) {
        printf("\nNo Record found!\n");
    }
    fclose(fp);
}
