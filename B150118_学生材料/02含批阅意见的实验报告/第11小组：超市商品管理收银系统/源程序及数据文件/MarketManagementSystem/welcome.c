#include<stdio.h>
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

return 0;
}

