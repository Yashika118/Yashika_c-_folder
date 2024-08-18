#include<stdio.h>
struct students
{
 int roll;
 char name[20];
 float cgpa;
};
int main()
{
  struct students stu1;
  printf("Enter student Roll No.:");
  scanf("%d",&stu1.roll);
  printf("Enter student Name:");
  scanf("%s",stu1.name);
  printf("Enter student CGPA:");
  scanf("%f",&stu1.cgpa);
  printf("\nStudent Roll No.:%d",stu1.roll);
  printf("\nStudent Name : %s",stu1.name);
  printf("\nStudent CGPA:%f",stu1.cgpa);
  return 0;
}