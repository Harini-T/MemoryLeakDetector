/* 

1. For a given C structure as below, write a C program which prints the size and offset of each field of this structure

typedef struct emp_{
	char emp_name[30];
	unsigned int emp_id;
	unsigned int age;
	struct emp_ *mgr;
	float salary;
}emp_t;


2. Given the below structure, create an array of objects of this structure type

typedef struct _student{
	char stud_name[32];
	int rollno;
	int age;
}strudent_t;
*/


#include <stdio.h>
#include<stddef.h>

typedef struct emp_{
	char emp_name[30];
	unsigned int emp_id;
	unsigned int age;
	struct emp_ *mgr;
	float salary;
}emp_t;

int main(){
		emp_t obj;
		printf("Size of 'emp_name' is %ld and offset is %ld\n",sizeof(obj.emp_name),offsetof(emp_t,emp_name));
		printf("Size of 'emp_id' is %ld and offset is %ld\n",sizeof(obj.emp_id),offsetof(emp_t,emp_id));
		printf("Size of 'age' is %ld and offset is %ld\n",sizeof(obj.age),offsetof(emp_t,age));
		printf("Size of '*mgr' is %ld and offset is %ld\n",sizeof(obj.mgr),offsetof(emp_t,mgr));
		printf("Size of 'salary' is %ld and offset is %ld\n",sizeof(obj.salary),offsetof(emp_t,salary));
}
