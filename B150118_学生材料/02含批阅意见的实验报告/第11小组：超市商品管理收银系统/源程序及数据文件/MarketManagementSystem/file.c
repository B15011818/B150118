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
//д��������Ϣ����������
long neworder(){
    int id;
    srand( (unsigned)time( NULL ) );
    id = rand()%(9999999-1000000+1)+1000000; //�������������
    FILE *fp;
    if(fp = fopen(".\\2.txt","r")){
    while(!feof(fp)){
        fscanf(fp,"%s %s %lf %lf %d",read.code,read.name,&read.price,&read.chengben,&read.num);
        if(!strcmp(code,read.code))
            {
                fclose(fp);
                break;
            }
        }
    }
    else{
        printf("�ļ����ش����������ݿ��ļ�");
    }
}
