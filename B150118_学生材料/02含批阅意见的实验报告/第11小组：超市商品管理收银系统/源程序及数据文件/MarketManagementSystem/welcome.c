#include<stdio.h>
#include<string.h>
//��¼����
int login(){
printf("��ӭ���볬����Ʒ������ϵͳ\n");
printf("���¼��\n");
printf("�������û�����");
char user_name[20];
char user_password[20];
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
    printf("\n����Ա���");
}
else{
        if(!strcmp(user_name,check)&& !strcmp(user_password,checkpassword))
        {
            printf("\n����Ա���");
        }
        else{
    printf("\n�û������������,�����µ�¼\n");
     printf("\n");
    login();
        }
}
return 0;
}

//����Ա����
int check()
{
    printf("hello word");


}

