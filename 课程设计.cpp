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
 struct node *next;        //����һ������
}Node;
void Add(Node *equip) //��Ӽ�¼
{
 Node *p,*r,*s;   
 char id[10];            //����������ID,Ҳ�����ж��Ƿ�����ѭ��
 r=equip;
 s=equip->next;          //ʹsΪ��һ�����õĽ��
 while(r->next!=NULL)    //���ѭ����������ʹrΪ���һ�����õĽ��
 r=r->next;              //��ָ��������ĩβ
 while(1)
{
    printf(">>>>>>>>>>��ʾ:����0�򷵻����˵�!\n");
    printf("\n���������豸ID��:");     
    scanf("%s",id);               
    if(strcmp(id,"0")==0)  break;                   
    p=(Node *)malloc(sizeof(Node));  //����ռ�
    strcpy(p->data.ID,id);
    printf("\n�������豸����:");
    scanf("%s",p->data.name);         
    printf("\n�������豸����:");
    scanf("%s",p->data.kind);
    printf("\n�����뱨������:");
    scanf("%s",&p->data.over);
    printf("\n�������豸�Ƿ񱨷�:");
    scanf("%s",&p->data.yesno);
    printf("\n�������豸����ʱ��:"); 
    scanf("%s",&p->data.time);
    printf("\n�������豸�۸�:");
    scanf("%s",&p->data.price);
    printf(">>>>>>>>>>��ʾ:�Ѿ����һ����¼����ӡ�\n");
    p->next=NULL;
    r->next=p;      //��һ���Ǳ����,��p����ǰ����������������һ��������
    r=p;            //Ҳ�Ǳ����.��r ������Ϊ���������һ�����ý��
}
}
void Modify(Node *equip)//�޸�
{
Node *p;
char find[20];
if(!equip->next)
{
    printf("\n>>>>>>>>>>��ʾ:û�����Ͽ����޸�!\n");
    return;
}
printf("������Ҫ�޸ĵ��豸ID��:"); 
scanf("%s",find);
    p=equip->next; 
    while(p!=NULL) 
    {
      if(strcmp(p->data.ID,find)==0)    //����ҵ��Ļ����ص��Ƿ���Ҫ��
      break;
      p=p->next;
    }
    if(p)    //���ҵ�
    {
      int x;
      while(1)
      {
        printf("����޸�������0���������������ٽ����޸�:");
        scanf("%d",&x);
        if(x==0)
        {break;}
          printf("���������豸��(ԭ���� %s ):",p->data.ID);
          scanf("%s",p->data.ID);
          printf("���������豸����(ԭ���� %s ):",p->data.name);
          scanf("%s",p->data.name);
          printf("���������豸�豸��������(ԭ���� %s ):",p->data.kind);
          scanf("%s",p->data.kind); 
          printf("���������豸������������(ԭ���� %s ):",p->data.over);
          scanf("%s",p->data.over); 
          printf("���������豸�Ƿ񱨷�(ԭ���� %s ):",p->data.yesno);
          scanf("%s",p->data.yesno);
          printf("���������豸����ʱ��(ԭ���� %s ):",p->data.kind);
          scanf("%s",p->data.time);
          printf("���������豸�۸�(ԭ���� %s ):",p->data.price);
          scanf("%s",p->data.price);
          printf("\n>>>>>>>>>>��ʾ:�����¼�����Ѿ��ɹ��޸�!\n");
    }
    }
    else    printf("\n>>>>>>>>>>��ʾ:��Ҫ�޸ĵ���Ϣ������!\n");
}     
void Disp(Node *equip)//�����¼
{
Node *p;
p=equip->next;
if(!p)
{
    printf("\n>>>>>>>>>>��ʾ:û�м�¼������ʾ!\n");
    return;
}
    printf("\t\t\t\t��ʾ���\n");   
    printf("�豸��  �豸����  �豸����  ��������  �Ƿ񱨷�  ����ʱ��  �۸�\n");     
while(p)
{
    printf("\n%-13s%-11s%-7s%-10s%-13s%-10s%-5s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.yesno,p->data.time,p->data.price);
    p=p->next;
}
}
void Tongji(Node *equip)//ͳ��
{
 Node *p;
 int sel;int flag2=0,ha=0;
 char find[20]; 
 p=equip->next;  
 if(!equip->next)    //������Ϊ��
 {
    printf("\n>>>>>>>>>>��ʾ:û�����Ͽ���ͳ�Ʒ���!\n");
    return;
 }
 printf(">>>>>>>>>>��ʾ:\n=====>0�˳�\n=====>1���豸��ͳ��\n=====>2���豸����ͳ��\n");
 scanf("%d",&sel);
 if(sel==1)
 {
    printf("\n������Ҫͳ�Ʒ�����豸��:");
    scanf("%s",find);
    while(p)
    { 
    if(strcmp(p->data.ID,find)==0)
    {
      flag2++;
    }
    if(flag2==1&&ha!=flag2)
    { printf("�豸��  �豸����  �豸����  ��������  �Ƿ񱨷�  ����ʱ��  �۸�\n");
      printf("\n%-13s%-11s%-7s%-10s%-13s%-10s%-5s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.yesno,p->data.time,p->data.price);
      ha=flag2;
    }
    else if(flag2>ha){printf("\n%-13s%-11s%-7s%-10s%-13s%-10s%-5s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.yesno,p->data.time,p->data.price);ha=flag2;
    p=p->next;
    }
    if(flag2)
    {
    printf("\n*************************���豸��%sͳ�Ʒ������%d����¼:*************************\n\n",find,flag2);
    }
    else {printf("\n���豸��%sͳ�ƵĽ��Ϊ0��\n\n",find);}
	}
 }
  if(sel==2)
 {
    printf("\n������Ҫͳ�Ʒ�����豸����:");
          scanf("%s",find);
    while(p)
    { 
    if(strcmp(p->data.name,find)==0)
    {
      flag2++;
    } 
    if(flag2==1&&ha!=flag2)
    { printf("�豸��  �豸����  �豸����  ��������  �Ƿ񱨷�  ����ʱ��  �۸�\n");
      printf("\n%-13s%-11s%-7s%-10s%-13s%-10s%-5s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.yesno,p->data.time,p->data.price);
      ha=flag2;
    }
    else if(flag2>ha)
	{printf("\n%-13s%-11s%-7s%-10s%-13s%-10s%-5s\n",p->data.ID,p->data.name,p->data.kind,p->data.over,p->data.yesno,p->data.time,p->data.price);ha=flag2;}
    p=p->next;
	}
    if(flag2)
    {
    printf("\n******************���豸����%sͳ�Ƶ���%d����¼:********************\n\n",find,flag2);
    }
    else {printf("\n���豸����%sͳ�Ʒ���Ľ��Ϊ0��\n\n",find);}
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
    printf("\t\t\t\t�豸����ϵͳ\n");
    equip=(Node*)malloc(sizeof(Node));
    equip->next=NULL;
    p=equip;
    fp=fopen("�豸����ϵͳ","wb+");
    q=(Node*)malloc(sizeof(Node));
      if(fread(q,sizeof(Node),1,fp)) //���ļ������ݷ���ӵ���
      {
      q->next=NULL;
      p->next=q;
      p=q; //���ýӵ����������
      }
    fclose(fp); //�ر��ļ�
    while(1)
    {
     printf("**************************************Ŀ¼**************************************");
     printf("\n1��Ӽ�¼\n");
     printf("\n2�޸ļ�¼\n");
     printf("\n3��ʾ��¼\n");
     printf("\n4ͳ�Ʒ����¼\n");
     printf("\n0*-EXIT-*\n");
     printf("��������Ҫ���������:");
     scanf("%d",&flag);
     switch(flag)
	 {
      case 0:    printf("\n>>>>>>>>>>��ʾ:�Ѿ��˳�ϵͳ,ByeBye!\n");break;
      case 1:    Add(equip);      break; //���Ӽ�¼
      case 2:    Modify(equip);    break;//�޸ļ�¼
      case 3:    Disp(equip);      break;//��ʾ��¼��Ϣ
      case 4:    Tongji(equip);    break;//ͳ�Ƽ�¼
      default:    printf("\n>>>>>>>>>>��ʾ:�������!\n"); break;
     }
    }
}

