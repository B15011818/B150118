/*li12_1.c*/
#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"student.h"

void printHead( )      /*打印学生信息的表头*/
{
printf("%6s%10s%6s%10s%6s%10s%12s%16s\n","药品名称","药品类型","规格","库存数量","价格","入库时间","药品保质期","保质期到期时间");
}

void menu( )         /*顶层菜单函数*/
{
		printf("******** 1. 药品库存信息 ********\n");
		printf("******** 2. 药品进出库记录 ********\n");
		printf("******** 3. 药品进出库管理 ********\n");
		printf("******** 4. 其他信息 ********\n");
        printf("******** 5. 根据条件查询 ********\n");
		printf("******** 0. 退出         ********\n");
}

void menuBase( )     /*2、药品进出库记录菜单函数*/
{
		printf("%%%%%%%% 1. 药品入库记录 %%%%%%%%\n");
		printf("%%%%%%%% 2. 药品出库记录 %%%%%%%%\n");
		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");
}

void menuScore( )     /*3、药品进出库管理菜单函数*/
{
		printf("@@@@@@@@ 1. 药品入库 @@@@@@@@\n");
		printf("@@@@@@@@ 2. 药品出库 @@@@@@@@\n");
        printf("@@@@@@@@ 3. 修改库存信息 @@@@@@@@\n");
        printf("@@@@@@@@ 4. 删除药品 @@@@@@@@\n");
		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");
}
 
void menuCount( )    /*4、其他信息菜单函数*/
{
		printf("&&&&&&&& 1. 药品总价 &&&&&&&&\n");
		printf("&&&&&&&& 2. 即将到期药品 &&&&&&&&\n");
		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");
}

void menuSearch()    /*5、根据条件查询菜单函数*/
{
		printf("######## 1. 按药品名称查询   ########\n");
		printf("######## 2. 按药品类型查询   ########\n");
		printf("######## 3. 按入库时间查询   ########\n");
		printf("######## 0. 返回上层菜单 ########\n");
}


int baseManage(Student stu[],int n)    	     /*该函数完成基本信息管理*/
/*按学号进行插入删除修改，学号不能重复*/
{  
		int choice,t,find[NUM];
     Student s;
do
	    {   
menuBase( );                  /*显示对应的二级菜单*/
printf("choose one operation you want to do:\n");
		     scanf("%d",&choice);	          /*读入选项*/
		     switch(choice)
		     {
			   case 1:	 readStu(&s,1);       /*读入一条待插入的学生记录*/
					 n=insertStu(stu,n,s);   /*调用函数插入学生记录*/
					 break;
			   case 2:  printf("Input the number deleted\n");
					 scanf("%ld",&s.num);  /*读入一个待删除的学生学号*/
					 n=deleteStu(stu,n,s);   /*调用函数删除指定学号的学生记录*/
					 break;
			   case 3:  printf("Input the number modified\n");
					 scanf("%ld",&s.num);  /*读入一个待修改的学生学号*/
				      t=searchStu(stu,n,s,1,find) ; /*调用函数查找指定学号的学生记录*/
				      if (t)                 /*如果该学号的记录存在*/
					 {
						  readStu(&s,1);   /*读入一条完整的学生记录信息*/
					      stu[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					 
					  }					 
					 else                 /*如果该学号的记录不存在*/ 
 printf("this student is not in,can not be modified.\n"); /*输出提示信息*/
					 break;
			    case 0: break;
		    }
	}while(choice);
return n;                             /*返回当前操作结束后的实际记录条数*/
}

void scoreManage(Student stu[],int n)          /*该函数完成学生成绩管理功能*/
{  
	int choice;
	do
	{
		menuScore( );                        /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);	                 /*读入二级选项*/
		switch(choice)
		{
			case 1:   calcuTotal(stu,n);         /*求所有学生的总分*/
					  break;
			case 2:   calcuRank(stu,n);         /*根据所有学生的总分排名次*/
				      break;		
			case 0:   break;
		}
	}while(choice);
}

void printMarkCourse(char *s,double m[3][3],int k)   /*打印分数通用函数，被countManage 调用*/
{                 /*形式参数k代表输出不同的内容，0、1、2分别对应最高分、最低分、平均分*/
int i;
    printf(s);                                  /*这里的s传入的是输出分数的提示信息*/
    for (i=0;i<3;i++)                           /*i控制哪一门课*/
		  printf("%10.2lf",m[i][k]);
	   printf("\n");
}

void countManage(Student stu[],int n)               /*该函数完成考试成绩统计功能*/
{
		int choice;
		double mark[3][3];
		do
		{
			menuCount( );                        /*显示对应的二级菜单*/
			calcuMark(mark,stu,n);                 /*调用此函数求三门课的最高、最低、平均值*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printMarkCourse("三门课的最高分分别是:\n",mark,0);  /*输出最高分*/
				      break;
				case 2:   printMarkCourse("三门课的最低分分别是:\n",mark,1);  /*输出最低分*/
				      break;
				case 3:   printMarkCourse("三门课的平均分分别是:\n",mark,2);  /*输出平均分*/
				      break;
				case 0:   break;
			}
		}while (choice);
}

void searchManage(Student stu[],int n)               /*该函数完成根据条件查询功能*/
{
    int i,choice,findnum,f[NUM];
Student s;
	   do
{
			menuSearch( );                         /*显示对应的二级菜单*/
			printf("choose one operation you want to do:\n");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:   printf("Input a student\'s num will be searched:\n");
				      scanf("%ld",&s.num);         /*输入待查询学生的学号*/
					  break;
				case 2:   printf("Input a student\'s name will be searched:\n");
				      scanf("%s",s.name);	          /*输入待查询学生的姓名*/		  
				      break;   
				case 3:   printf("Input a rank will be searched:\n");
				      scanf("%d",&s.rank);          /*输入待查询学生的名次*/
					  break;
				case 0:   break;
			}
		 	if (choice>=1&&choice<=3)
			{ 
				findnum=searchStu(stu,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/
				if (findnum)				     /*如果查找成功*/
				{
			   		 printHead( );                  /*打印表头*/
					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/
	      	 printStu(&stu[f[i]],1);      /*每次输出一条记录*/
				}
		    		else
			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/
		     }		
	    }while (choice);
}

int runMain(Student stu[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/
{
		switch(choice)
		{
			case 1: printHead( );           /* 1. 显示基本信息*/
				 sortStu(stu,n,1);         /*按学号由小到大的顺序排序记录*/ 
          	 printStu(stu,n);          /*按学号由小到大的顺序输出所有记录*/
					break;
			case 2: n=baseManage(stu,n);    /* 2. 基本信息管理*/
			   	     break;
			case 3: scoreManage(stu,n);     /* 3. 学生成绩管理*/
					break;
			case 4: countManage(stu,n);     /* 4. 考试成绩统计*/
					break;
			case 5: searchManage(stu,n);     /* 5. 根据条件查询*/
				     break;
          case 0: break;
		}
		return n;
}

int main( )
{
		Student stu[NUM];                /*定义实参一维数组存储学生记录*/
      int choice,n;
	 n=readFile(stu);                  /*首先读取文件，记录条数返回赋值给n*/
	 if (!n)                          /*如果原来的文件为空*/
	     {
		    n=createFile(stu);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
}	 	 
	do
	     {
	         menu();                      /*显示主菜单*/
	         printf("Please input your choice: ");
	         scanf("%d",&choice);
	         if (choice>=0&&choice<=5)
	              n=runMain(stu,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
	         else 
		          printf("error input,please input your choice again!\n");
	} while (choice);
	sortStu(stu,n,1);                   /*存入文件前按学号由小到大排序*/ 
	     saveFile(stu,n);                   /*将结果存入文件*/
      return 0;
}





/*②student.c文件的完整内容*/
#include "student.h"
#include <stdio.h>

int readStu(Student  *stu , int n)          /*读入学生记录值，学号为0或读满规定条数记录时停止*/
{
	int i,j;
	for (i=0;i<n;i++)
	{
		printf("Input one medcine\'s information\n");
		printf("num:  ");
	     scanf("%ld", &stu[i].num);
		if (stu[i].num==0) break;
		printf("name: ");
		scanf("%s",stu[i].name);	
		printf("sex:  ");
		scanf("%s",stu[i].sex);
    	     stu[i].total=0;                /*总分需要计算求得，初值置为0*/
		printf("Input three courses of the student:\n");
		for (j=0;j<3;j++)
	    {
		    scanf("%d",&stu[i].score[j]);	
		}
		stu[i].rank=0;                 /*名次需要根据总分来计算，初值置为0*/
	}
	return i;                         /*返回实际读入的记录条数*/
}

void printStu ( Student  *stu , int n)       /*输出所有学生记录的值*/
{
    int i,j;
	for (i=0;i<n;i++)
	{
		printf("%8ld  ", stu[i].num);
		printf("%8s", stu[i].name);
		printf("%8s", stu[i].sex);
		for (j=0;j<3;j++)
		   printf("%6d",stu[i].score[j]);
	    printf("%7d",stu[i].total);
	    printf("%5d\n",stu[i].rank);
	}
}

int equal(Student s1,Student s2,int condition)  /*如何判断两个Student记录相等*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较学号*/
		return s1.num==s2.num;
	else if (condition==2)                /*如果参数condition的值为2，则比较姓名*/
     {
	     if (strcmp(s1.name,s2.name)==0) 	return 1;
		else return 0;
     }
 else if (condition==3)                /*如果参数condition的值为3，则比较名次*/
	     return s1.rank==s2.rank;
 else if (condition==4)                /*如果参数condition的值为4，则比较总分*/
		return s1.total==s2.total;
	else return 1;                       /*其余情况返回1*/
} 

int larger(Student s1,Student s2,int condition)  /*根据condition条件比较两个Student记录的大小*/
{
	if (condition==1)                    /*如果参数condition的值为1，则比较学号*/
		return s1.num>s2.num;
	if (condition==2)                    /*如果参数condition的值为2，则比较总分*/
		return s1.total>s2.total;	
	else return 1; /*其余情况返回1*/
}

void reverse(Student stu[],int n)             /*数组元素逆置*/
{
	int i;
	Student temp;
	for (i=0;i<n/2;i++)                   /*循环次数为元素数量的一半*/
	{
		temp=stu[i];
		stu[i]=stu[n-1-i];
		stu[n-1-i]=temp;
	}
}

void calcuTotal(Student stu[],int n)         /*计算所有学生的总分*/
{
	int i,j;
	for (i=0;i<n;i++)                    /*外层循环控制所有学生记录*/
	{
		stu[i].total =0;
		for (j=0;j<3;j++)               /*内层循环控制三门功课*/
			stu[i].total +=stu[i].score[j];
	}	
}

void calcuRank(Student stu[],int n)          /*根据总分计算所有学生的排名，成绩相同者名次相同*/
{
	int i ;                       
	sortStu(stu,n,2);                     /*先调用sortStu算法，按总分由小到大排序*/
	reverse(stu,n);                      /*再逆置，则按总分由大到小排序了*/
	stu[0].rank=1;                      /*第一条记录的名次一定是1*/
	for (i=1;i<n;i++)                     /*从第二条记录一直到最后一条进行循环*/
	{
		if (equal(stu[i],stu[i-1],4))         /*当前记录与其相邻的前一条记录如果总分相等*/
			stu[i].rank=stu[i-1].rank;     /*当前记录名次等于其相邻的前一条记录名次*/ 
	    else
			stu[i].rank=i+1;             /*不相等时当前记录名次等于其下标号+1*/
	}
}

void calcuMark(double m[3][3],Student stu[],int n) /*求三门课的最高、最低、平均分*/
/*其中形式参数二维数组m的第一维代表三门课，第二维代表最高、最低、平均分*/
{
	int i,j;
	for (i=0;i<3;i++)                 /*求三门课的最高分*/		
	{ 
		m[i][0]=stu[0].score[i];     
		for (j=1;j<n;j++)
			if (m[i][0]<stu[j].score[i])
				m[i][0]=stu[j].score[i];
	}
	for (i=0;i<3;i++)                  /*求三门课的最低分*/
	{ 
		m[i][1]=stu[0].score[i];      
		for (j=1;j<n;j++)
			if (m[i][1]>stu[j].score[i])
				m[i][1]=stu[j].score[i];
	}
	for (i=0;i<3;i++)                 /*求三门课的平均分*/
	{ 
		m[i][2]=stu[0].score[i];     
		for (j=1;j<n;j++)
			m[i][2]+=stu[j].score[i];
		m[i][2]/=n;
	}
}

void sortStu(Student stu[],int n,int condition)  /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;                      /*minpos用来存储本趟最小元素所在的下标*/
	Student t;
	for (i=0;i<n-1;i++)                  /*控制循环的n-1趟*/
	{
		minpos=i;
		for (j=i+1;j<n;j++)             /*寻找本趟最小元素所在的下标*/
			if (larger(stu[minpos],stu[j],condition))
				minpos=j;
		if (i!=minpos)                 /*保证本趟最小元素到达下标为i的位置*/
		{
			t=stu[i];
			stu[i]=stu[minpos];
			stu[minpos]=t;
		}
	}
}

int searchStu(Student stu[],int n,Student s,int condition,int f[ ])  /*在stu数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for (i=0;i<n;i++)                                 /*待查找的元素*/
		if (equal(stu[i],s,condition))  
		{
			f[j++]=i;                          /*找到了相等的元素，将其下标放到f数组中*/
			find++;	                        /*统计找到的元素个数*/                              
		}
	 return find;                                /*返回find，其值为0则表示没找到*/ 
}

int insertStu(Student stu[],int n,Student s)              /*向stu数组中依学号递增插入一个元素s*/
{
	int i;
	sortStu(stu,n,1);                              /*先按学号排序*/
	for (i=0;i<n;i++)
	{
		if (equal(stu[i],s,1))                      /*学号相同不允许插入，保证学号的唯一性*/
		{
		    printf("this record exist,can not insert again!\n");
		    return n;
		}
	}
	for (i=n-1;i>=0;i--)                          /*按学号从小到大有序*/
	{
		if (!larger(stu[i],s,1))                    /*如果s大于当前元素stu[i]，则退出循环*/
		break;
		stu[i+1]=stu[i];                         /*否则元素stu[i]后移一个位置*/
	}
	stu[i+1]=s;                                /*在下标i+1处插入元素s*/                                   
	n++;                                     /*元素个数增加1*/
	return n;                                  /*返回现有元素个数*/
}

int deleteStu(Student stu[],int n,Student s)            /*从数组中删除指定学号的一个元素*/
{
	int i,j;
	for (i=0;i<n;i++)                           /*寻找待删除的元素*/
		if (equal(stu[i],s,1))   break;            /*如果找到相等元素则退出循环*/
	if (i==n)                                 /*如果找不到待删除的元素*/
	{
		printf("This record does not exist!\n");    /*给出提示信息然后返回*/
		return n;
	}
	for (j=i; j<n-1; j++)                        /*此处隐含条件为i<n且equal(stu[i],s,1)成立*/ 
		stu[j]=stu[j+1];                       /*通过移动覆盖删除下标为i的元素*/
                                                                            
	n--;                                      /*元素个数减少加1*/
	return n;                                  /*返回现有个数*/
}

