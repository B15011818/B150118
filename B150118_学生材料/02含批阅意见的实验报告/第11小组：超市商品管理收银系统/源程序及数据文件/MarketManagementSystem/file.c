#include<stdio.h>
#include "welcome.h"
#include<stdlib.h>
#include <time.h>
//ɨ�� ���ز�ѯ����������Ϣ
struct goods readcode(char code[]){
    goods read;
    FILE *fp;
    if(fp = fopen(".\\1.txt","r")){
        while(!feof(fp)){
            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);
            if(!strcmp(code,read.code))
            {
                fclose(fp);
                break;
            }
        }
        printf("û������������Ʒ");
    }
    else{
        printf("�ļ����ش����������ݿ��ļ�");
    }
    return read;
}
//��ʾ���е�ȫ����Ʒ
void showgoods(){
    goods read;
    FILE *fp;
    if(fp = fopen(".\\1.txt","r")){
            printf("   ����           ����       �ۼ�      �ɱ�     ����   \n");
        while(!feof(fp))
        {

            fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);
            printf("%10s   %10s %10.2f %10.2f   %10d\n",read.code,read.name,read.price,read.chengben,read.num);
        }
    }else{
        printf("�ļ����ش����������ݿ��ļ�");
    }

}
//����µ���Ʒ
int addgoods(char code[],char name[],double price,double chengben,int num){
        FILE *fp;
         if(fp = fopen(".\\1.txt","a+")){
            fprintf(fp,"%s %s %lf %lf %d",code,name,price,chengben,num);
            fclose(fp);
            return 1;
         }else{
        printf("�ļ����ش����������ݿ��ļ�");
        return 0;
         }
}







//д��������Ϣ����������
long neworder(){
    int id;
    goods read;
    srand( (unsigned)time( NULL ) );
    id = rand()%(9999999-1000000+1)+1000000; //�������������

}

struct goods * readorder(char orderid[]){
    FILE *fp;
    if(fp = fopen(".\\2.txt","r"))
    {

    }else{
        printf("�ļ����ش����������ݿ��ļ�");
    }
};
