#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"welcome.h"
// ����Ա����
void adminabc()
{
    int a;
    char b;
    do
    {
        printf("��ӭ�������Աҳ��\n\n");
        printf("  1��Ʒ��Ϣ¼��\n  2��Ʒ�������б�\n  3�������󱨱�\n  4���ӯ����Ʒ�����ӯ����Ʒ\n\n\n");
        printf("���������");
        scanf("%d",&a);
        if(a!=1&&a!=2&&a!=3&&a!=4)
        {
            printf("������������������!\n\n\n");
        }
    }
    while(a!=1&&a!=2&&a!=3&&a!=4);

    switch (a)
    {
    case 1:
        break;
    case 2:
        printf("dddd");
        break;
    case 3:
        printf("xxxx");
        break;
    case 4:
        printf("rrrr");
        break    ;
    }


}



//��¼����
int login()
{
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
        printf("\n����Ա���\n");
        adminabc();
    }
    else
    {
        if(!strcmp(user_name,check)&& !strcmp(user_password,checkpassword))
        {
            system("cls");
            printf("\n����Ա���\n");
        }
        else
        {

            printf("\n�û������������,�밴�س����µ�¼\n");
            getchar();
            getchar();
            system("cls");
            login();
        }
    }
    return 0;
}
// ¼�뺯��
void inputgoods()
{printf("��ֱ������Ʒ��Ϣ��code��*�Կո����*");




}


//����Ա����



