#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct shebei
{
 char ID[10];         
 char name[15];       
 char kind[15];           
 char over[15];           
 char  yesno[10];     
 char time[10];           
 char price[10];         
};
typedef struct node
{
 struct shebei data;
 struct node *next;        //建立一个链表。
}Node;
void Add(Node *equip) //添加记录
{
 Node *p,*r,*s;   
 char id[10];            //先用于输入ID,也用于判断是否跳出循环
 r=equip;
 s=equip->next;          //使s为第一个有用的结点
 while(r->next!=NULL)    //这个循环的作用是使r为最后一个有用的结点
 r=r->next;              //将指针置于最末尾
 while(1)
{
    printf(">>>>>>>>>>提示:输入0则返回主菜单!\n");
    printf("\n请你输入设备ID号:");     
    scanf("%s",id);               
    if(strcmp(id,"0")==0)  break;                   
    p=(Node *)malloc(sizeof(Node));  //申请空间
    strcpy(p->data.ID,id);
    printf("\n请输入设备名称:");
    scanf("%s",p->data.name);         
    printf("\n请输入设备种类:");
    scanf("%s",p->data.kind);
    printf("\n请输入报废日期:");
    scanf("%s",&p->data.over);
    printf("\n请输入设备是否报废:");
    scanf("%s",&p->data.yesno);
    printf("\n请输入设备购买时间:"); 
    scanf("%s",&p->data.time);
    printf("\n请输入设备价格:");
    scanf("%s",&p->data.price);
    printf(">>>>>>>>>>提示:已经完成一条记录的添加。\n");
    p->next=NULL;
    r->next=p;      //这一步是必需的,将p与先前的链表连起来构成一条新链表
    r=p;            //也是必需的.将r 又重设为新链的最后一个有用结点
}
}
void Modify(Node *equip)//修改
{
Node *p;
char find[20];
if(!equip->next)
{
    printf("\n>>>>>>>>>>提示:没有资料可以修改!\n");
    return;
}
printf("请输入要修改的设备ID号:"); 
scanf("%s",find);
    p=equip->next; 
    while(p!=NULL) 
    {
      if(strcmp(p->data.ID,find)==0)    //如果找到的话返回的是符合要求
      break;
      p=p->next;
    }
    if(p)    //若找到
    {
      int x;
      while(1)
      {
        printf("完成修改请输入0否则输入任意数再进行修改:");
        scanf("%d",&x);
        if(x==0)
        {break;}
          printf("请输入新设备号(原来是 %s ):",p->data.ID);
          scanf("%s",p->data.ID);
          printf("请输入新设备名称(原来是 %s ):",p->data.name);
          scanf("%s",p->data.name);
          printf("请输入新设备设备种类名称(原来是 %s ):",p->data.kind);
          scanf("%s",p->data.kind); 
          printf("请输入新设备报废日期名称(原来是 %s ):",p->data.over);
          scanf("%s",p->data.over); 
          printf("请输入新设备是否报废(原来是 %s ):",p->data.yesno);
          scanf("%s",p->data.yesno);
          printf("请输入新设备购买时间(原来是 %s ):",p->data.kind);
          scanf("%s",p->data.time);
          printf("请输入新设备价格(原来是 %s ):",p->data.price);
          scanf("%s",p->data.price);
          printf("\n>>>>>>>>>>提示:该项记录资料已经成功修改!\n");
    }
    }
    else    printf("\n>>>>>>>>>>提示:你要修改的信息不存在!\n");
}     
void Disp(Node *equip)//输出记录
{
Node *p;
p=equip->next;
if(!p)
{
    printf("\n>>>>>>>>>>提示:没有记录可以显示!\n");
    return;
}
    printf("\t\t\t\t显示结果\n");   
    printf("设备号  设备名称  设备种类  报废日期  是否报废  购买时间  价格\n");     
while(p)
{
    printf("\n%-13s%-11s%-7s%-10s%-13s%-10s%-5s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.yesno,p->data.time,p->data.price);
    p=p->next;
}
}
void Tongji(Node *equip)//统计
{
 Node *p;
 int sel;int flag2=0,ha=0;
 char find[20]; 
 p=equip->next;  
 if(!equip->next)    //若链表为空
 {
    printf("\n>>>>>>>>>>提示:没有资料可以统计分类!\n");
    return;
 }
 printf(">>>>>>>>>>提示:\n=====>0退出\n=====>1按设备号统计\n=====>2按设备名称统计\n");
 scanf("%d",&sel);
 if(sel==1)
 {
    printf("\n输入你要统计分类的设备号:");
    scanf("%s",find);
    while(p)
    { 
    if(strcmp(p->data.ID,find)==0)
    {
      flag2++;
    }
    if(flag2==1&&ha!=flag2)
    { printf("设备号  设备名称  设备种类  报废日期  是否报废  购买时间  价格\n");
      printf("\n%-13s%-11s%-7s%-10s%-13s%-10s%-5s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.yesno,p->data.time,p->data.price);
      ha=flag2;
    }
    else if(flag2>ha){printf("\n%-13s%-11s%-7s%-10s%-13s%-10s%-5s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.yesno,p->data.time,p->data.price);ha=flag2;
    p=p->next;
    }
    if(flag2)
    {
    printf("\n*************************按设备号%s统计分类的有%d条记录:*************************\n\n",find,flag2);
    }
    else {printf("\n按设备号%s统计的结果为0个\n\n",find);}
	}
 }
  if(sel==2)
 {
    printf("\n输入你要统计分类的设备名称:");
          scanf("%s",find);
    while(p)
    { 
    if(strcmp(p->data.name,find)==0)
    {
      flag2++;
    } 
    if(flag2==1&&ha!=flag2)
    { printf("设备号  设备名称  设备种类  报废日期  是否报废  购买时间  价格\n");
      printf("\n%-13s%-11s%-7s%-10s%-13s%-10s%-5s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.yesno,p->data.time,p->data.price);
      ha=flag2;
    }
    else if(flag2>ha)
	{printf("\n%-13s%-11s%-7s%-10s%-13s%-10s%-5s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.yesno,p->data.time,p->data.price);ha=flag2;}
    p=p->next;
	}
    if(flag2)
    {
    printf("\n******************按设备名称%s统计的有%d条记录:********************\n\n",find,flag2);
    }
    else {printf("\n按设备名称%s统计分类的结果为0个\n\n",find);}
  }	
 else if(sel==0) 
	 exit(0);
}

void main()
{
Node *equip;
FILE *fp;
int flag;
Node *p,*q;
    printf("\t\t\t\t设备管理系统\n");
    equip=(Node*)malloc(sizeof(Node));
    equip->next=NULL;
    p=equip;
    fp=fopen("设备管理系统","wb+");
    q=(Node*)malloc(sizeof(Node));
      if(fread(q,sizeof(Node),1,fp)) //将文件的内容放入接点中
      {
      q->next=NULL;
      p->next=q;
      p=q; //将该接点挂入链表中
      }
    fclose(fp); //关闭文件
    while(1)
    {
     printf("**************************************目录**************************************");
     printf("\n1添加记录\n");
     printf("\n2修改记录\n");
     printf("\n3显示记录\n");
     printf("\n4统计分类记录\n");
     printf("\n0*-EXIT-*\n");
     printf("请输入你要操作的序号:");
     scanf("%d",&flag);
     switch(flag)
	 {
      case 0:    printf("\n>>>>>>>>>>提示:已经退出系统,ByeBye!\n");break;
      case 1:    Add(equip);      break; //增加记录
      case 2:    Modify(equip);    break;//修改记录
      case 3:    Disp(equip);      break;//显示记录信息
      case 4:    Tongji(equip);    break;//统计记录
      default:    printf("\n>>>>>>>>>>提示:输入错误!\n"); break;
     }
    }
}

