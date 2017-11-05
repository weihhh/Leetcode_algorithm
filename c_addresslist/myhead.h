#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义存储电话簿内容的结构体
struct date
{
    char no[9];//姓名
    char tele[12];  //手机号
};

typedef struct node
{
    struct date info;
    struct node *next;
}NODE;