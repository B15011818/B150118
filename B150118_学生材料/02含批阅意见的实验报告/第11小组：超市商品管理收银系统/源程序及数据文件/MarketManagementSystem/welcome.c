#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//��¼����
int login(){
printf("��ӭ���볬����Ʒ������ϵͳ\n");
printf("���¼��\n");
printf("�������û�����");
char user_name[200];
char user_password[200];
int c=0,i=0;
scanf("%s",&user_name);
printf("���������룺");
  while ((c=getch()) != '\r') //ʹ���������ʱ����ʾ*��
  {
       user_password[i++] = c;
       putchar('*');
  }
  user_password[i] = '\0';
  char admin[] = "root";
  char adminpassword[] = "123456";
  char check[] = "check";
  char checkpassword[] = "123456";
if(!strcmp(user_name,admin)&& !strcmp(user_password,adminpassword))
{
        system("cls");
    printf("\n����Ա���");
}
else{
        if(!strcmp(user_name,check)&& !strcmp(user_password,checkpassword))
        {
                system("cls");
            printf("\n����Ա���");
        }
        else{

    printf("\n�û������������,�밴�س����µ�¼\n");
    getchar();
    getchar();
    system("cls");
    login();
        }
}
return 0;
}

//����Ա����


