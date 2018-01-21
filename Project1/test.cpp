/*（1）问题描述
学生信息包括：学号，姓名，年龄，性别，出生年月，地址，电话，E - mail等。试设计一学生信息管理系统，使之能提供以下功能：
1.系统以菜单方式工作
2.学生信息录入功能（学生信息用文件保存）-- - 输入
3.学生信息浏览功能——输出
4.查询、排序功能——算法
1、按学号查询
2、按姓名查询
5.学生信息的删除与修改（可选项）
（2）功能要求
1.界面简单明了；
2.有一定的容错能力，比如输入的成绩不在0～100之间，就提示不合法，要求重新输入；
3.最好用链表的方式实现

界面：
-------------学生信息管理系统---------------
1. 学生信息录入
2. 学生信息浏览
3. 学生信息查询
1.按学号查询
2.按姓名查询
4. 学生信息的删除与修改
--------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
void menue();
int input_stu_xinxi();
/*
int check_stu_xinxi();
int browse_stu_xinxi();
int revise_stu_xinxi();
*/
struct stu
{
	char stu_no[16];
	char name[20];
	char age;
	char sex[2];
	char birth_date[20];
	char address[1024];
	char phone[16];
	char email[24];
};
int main()
{
	menue();
	getchar();
	system("pause");
	return 0;
}

void menue()
{
	int choose;
	printf("-------------学生信息管理系统-------------\n");
	printf("\t1.学生信息录入\n");
	printf("\t2.学生信息浏览\n");
	printf("\t3.学生信息查询\n");
	printf("\t4.学生信息删除与修改\n");
	printf("\t0.退出系统\n");
	printf("------------------------------------------\n");
	printf("请输入您的选测（0-4）: ");
	scanf_s("%d", &choose);
	switch (choose)
	{
		case 0: exit(0); break;
		case 1: input_stu_xinxi(); break;
		/*
	    case 2: browse_stu_xinxi(); break;
		case 3: check_stu_xinxi(); break;
		case 4: revise_stu_xinxi(); break;
		*/
	}
	while (choose > 4 || choose < 0)
	{
		printf("您输入了一个无效数字，请重新输入（0-4）: ");
		scanf_s("%d", &choose);
	}
}
int input_stu_xinxi()
{	
	int flag = 1;
	while (flag)
	{
		struct stu students;
		FILE *fp;
		fp = fopen("F:\stuinfo.txt", "w+");
		if (fp == NULL)
		{
			printf("文件打开错误\n");
			exit(0);
		}
		printf("学号:");
		scanf_s("%s",&students.stu_no);
		printf("\t姓名:");
		scanf_s("%s", &students.name);   
		printf("\t年龄:");
		scanf_s("%s", &students.age);
		printf("\t性别:");
		scanf_s("%s", &students.sex);
		printf("\t出生年月:");
		scanf_s("%s", &students.birth_date);
		printf("\t地址:");
		scanf_s("%s", &students.address);
		printf("\t电话:");
		scanf_s("%s", &students.phone);
		printf("\t邮件:");
		scanf_s("%s", &students.email);
		fwrite(&students, sizeof(students), 1, fp);
		fclose(fp);
	}
	return 0;
}
