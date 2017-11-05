#include "myhead.h"

void clear_sdtin()
{
    //存在的问题是当输入缓存区为空时会阻塞，未解决，暂时用提示多回车一次
    //考虑使用select解决
    char ch;
    while((ch=getchar())!='\n'&&ch!=EOF);
}


//读取dat文件中的联系人,返回一个链表头，其后为文件中的联系人节点
NODE * load()
{
    int i=0;//用于计数
    NODE *head,*tail,*p;
    head=tail=(NODE *)malloc(sizeof(NODE));

    tail->next=NULL;
    
    //打开文件的正确过程
    FILE *fp;
    fp=fopen("list.dat","r");
    //判断是否打开失败
    if ((fp=fopen("list.dat","r"))==NULL)
    {
        printf("文件打开失败！\n");
        return NULL;//函数返回值为NODE *,指针，所以返回NULL指针
    }
    //判断是否到结尾,feof函数的陷阱！！！
    while(!feof(fp))//未读到结尾
    {
        p=(NODE *)malloc(sizeof(NODE));
        //读取结构体大小字节到p内存中
        //此时读入的还不能断定是不是eof
        fread(p,sizeof(p->info),1,fp);
        //上面的fread已经进一个，如果接下来的feof判断为eof
        //则表明现在指针指在eof后一个位置
        if(feof(fp)){
            free(p);
            break;
        }
        printf("正在读取第%d个数据\n",i);

        //链接链表
        p->next=NULL;
        tail->next=p;
        tail=p;    
        i++;
    }
    fclose(fp);
    return head;
}

NODE *create()
{
    NODE *head,*tail;
    head=tail=(NODE *)malloc(sizeof(NODE));
    tail->next=NULL;
    while(1)
    {
        //输入数据，存在问题：如果姓名输入为9或者以上，则会造成
        //姓名字符串后没有/0，则打印时会将之后内存中的内容输出
        //通过scanf中设置长度解决
        NODE *p=(NODE *)malloc(sizeof(NODE));
        printf("enter first!\n");
        clear_sdtin();
        printf("请输入姓名：\n");
        scanf("%8s",p->info.no);
        printf("请输入手机号：\n");
        clear_sdtin();
        scanf("%11s",p->info.tele);

        //链接链表
        p->next=NULL;
        tail->next=p;
        tail=p;
        printf("是否继续添加？<y/n>\n");
        clear_sdtin();
        if(getchar()=='n') break;

    }
    return head;

}

int view(NODE *head)
{
    NODE *p1;
    p1=head;
    if(head->next==NULL)
    {
        printf("链表为空！\n");
        return 0;
    }
    printf("------------------\n");
    printf("姓名        手机号码\n");
    printf("------------------\n");
    p1=head->next;
    while(p1!=NULL)
    {
        printf("%-11s  %s\n",p1->info.no,p1->info.tele );
        p1=p1->next;
    }
    return 0;
}   

int search(NODE *head)
{
    if(head->next==NULL)
    {
        printf("链表为空\n");
        return 0;
    }
    NODE *p1,*p2;
    p1=head->next;
    p2=head;

    int i=0;
    printf("姓名？手机号查找？(y=姓名，n=手机号\n");
    clear_sdtin();
    char type_search=getchar();
    if(type_search=='y')
    {
        printf("输入姓名：\n");
        char name[9];
        clear_sdtin();
        scanf("%8s",name);
        while(p1!=NULL)
        {
            if(strcmp(p1->info.no,name)==0)
            {
                printf("\n");
                printf("%-11s  %s\n",p1->info.no,p1->info.tele );
                i=1;
            }
    
            p2=p1;
            p1=p1->next;
        }
        if(i==0)
        {
            printf("没有找到相关信息！\n");
            return 0;
        }
        return 0;
    }
    else if(type_search=='n')
    {
        printf("请输入手机号：\n");
        char tele[12];
        clear_sdtin();
        scanf("%11s",tele);
        i=0;
        while(p1!=NULL)
        {
            if(strcmp(p1->info.tele,tele)==0)
            {
                printf("\n");
                printf("%-11s %s\n",p1->info.no,p1->info.tele );
                i==1;
            }
            p2=p1;
            p1=p1->next;
        }
        if(i==0)
        {
            printf("没有找到相关信息！\n");
            return 0;
        }
        return 0;
    }
    return 0;
}


int add(NODE *head)
{
    printf("是否需要添加联系人？y=yes,n=no\n");
    char ch;
    clear_sdtin();
    ch=getchar();
    if(ch=='y')
    {
        NODE *p1;
        while(ch=='y')
        {
            p1=(NODE*)malloc(sizeof(NODE));
            printf("姓名：\n");
            clear_sdtin();
            scanf("%8s",p1->info.no);
            printf("请输入手机号:\n");
            clear_sdtin();
            scanf("%11s",p1->info.tele);

            p1->next=head->next;
            head->next=p1;

            printf("是否继续添加：y/n\n");
            clear_sdtin();
            ch=getchar();
        }
        return 0;
    }
    return 0;
}

int del(NODE *head)
{
    if(head->next==NULL)
    {
        printf("链表为空\n");
        printf("\n");
        return 0;
    }
    NODE *p1,*p2;
    p1=head->next;
    p2=head;
    printf("姓名or手机号？y==姓名，n==手机号\n");
    clear_sdtin();
    char ch=getchar();
    if(ch=='y')
    {
        printf("姓名：\n");
        char name[9];
        clear_sdtin();
        scanf("%8s",name);
        while(p1!=NULL)
        {
            if(strcmp(p1->info.no,name)==0)
            {
                printf("\n");
                printf("%-11s %s\n",p1->info.no,p1->info.tele );
                printf("是否删除以上信息？y/n\n");
                clear_sdtin();
                ch=getchar();
                if(ch=='y')
                {
                    
                    p2->next=p1->next;
                    free(p1);
                    p1=p2->next;
                    continue;
                }
            }
            p2=p1;
            p1=p1->next;
        }

    }
    else if(ch=='n')
    {
        printf("手机号：\n");
        char tele[12];
        clear_sdtin();
        scanf("%11s",tele);
        while(p1!=NULL)
        {
            if(strcmp(p1->info.tele,tele)==0)
            {
                printf("\n");
                printf("%-11s %s\n",p1->info.no,p1->info.tele );
                printf("是否删除以上信息？y/n\n");
                clear_sdtin();
                ch=getchar();
                if(ch=='y')
                {
                    
                    p2->next=p1->next;
                    free(p1);
                    p1=p2->next;
                    continue;
                }
            }
            p2=p1;
            p1=p1->next;
        }
    }
}

int freelist(NODE *head)
{
    NODE *p1,*p2;
    p1=p2=head;
    //空链表，则只是删除头结点即可
    if(head->next=NULL)
    {
        free(head);
        return 0;
    }
    //不空，则删除前一个指针即可
    p1=p1->next;
    while(p1!=NULL)
    {
        free(p2);
        p2=p1;
        p1=p1->next;

    }
    free(p2);
    return 0;
}

int save(NODE *head)
{
    NODE *p1;
    p1=head->next;
    if(p1==NULL)
    {
        printf("链表为空！\n");
        return 0;
    }
    FILE *fp;
    fp=fopen("list.dat","w");
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        return 0;
    }
    while(p1!=NULL)
    {
        fwrite(p1,sizeof(p1->info),1,fp);
        p1=p1->next;
    }
    fclose(fp);
    printf("存盘成功\n");
    return 0;
}

int clearlist(NODE *head)
{
    //一键清空链表，只保留头结点，返回1表示清空成功，返回0表示清空失败
    int i=0;
    NODE *p1,*p2;
    p1=p2=head->next;
    while(p2!=NULL)
    {
        i=1;
        //删除链表
        p1=p1->next;
        free(p2);
        p2=p1;
    }
    if(i) head->next=NULL;
    return(i);
}

void menu()
{
    NODE *head;
    printf("读取本地数据，请稍等。。。\n");
    head=load();
    if(head==NULL)
    {
        printf("读取失败\n");
    }
    else
    {
        printf("读取成功\n");
    }
    while(1)
    {
        printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
        printf("            通讯录管理系统\n");
        printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
        printf("欢迎进入本系统!");
        printf("请选择：\n");
        printf("(1)-----浏览通讯录\n");
        printf("(2)-----查找联系人\n");
        printf("(3)-----增加联系人\n");
        printf("(4)-----删除联系人\n");
        printf("(5)-----通讯录存盘\n");
        printf("(6)-----删除所有联系人\n");
        //退出系统之前需要释放内存!!!!!!!!!!!
        printf("(7)-----退出本系统\n");//!!!!!!!!
        
        int s;
        scanf("%d",&s);
        switch(s)
        {
            printf("here\n");
            case 1:view(head);break;
            case 2:search(head);break;
            case 3:add(head);break;
            case 4:del(head);break;
            case 5:save(head);break;
            case 6:
                {
                    if(clearlist(head))
                        printf("删除所有联系人成功!\n");
                    else printf("删除所有联系人失败!\n");
                }break;
            case 7:freelist(head);exit(0);
            default:printf("error!请重新输入!\n");
        }

    }
}

int main(int argc, char const *argv[])
{
    menu();
    // NODE * head;
    // head=create();
    // view(head);
    // return 0;
}
