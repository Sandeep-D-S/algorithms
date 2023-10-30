#include <stdio.h>
struct student
{
    char name[50];
    int rollNo;
    float cgpa;
};
int main()
{
    int n;
    printf("Enter the number of students to be entered: ");
    scanf("%d", &n);
    struct student stu[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the student %d roll no: ", i + 1);
        scanf("%d", &(stu + i)->rollNo);
        printf("\nEnter the student %d cgpa: ", i + 1);
        scanf("%f", &(stu + i)->cgpa);
        printf("\nEnter the student %d name: ", i + 1);
        scanf("%s", &stu[i].name);
    }
    printf("\nNAME\tROLLNO\tCGPA\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%d\t%f\n", stu[i].name, stu[i].rollNo, stu[i].cgpa);
    }
}