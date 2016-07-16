/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "rank.h"

void swap(ArrayList *L,int i,int j)
{
    int temp;
    temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

/*
 * 获取随机数0~100的一个。
 */
int generate_rand_number_(int from,int to){
    int num;
    num = rand()%(to-from)+from;
    return num;
}

void generate_random_list(ArrayList *L,int length)
{
    int i;
    L->length = length;
    srand((unsigned int)(time(NULL))); // call this onetime
    for(i=1;i <= L->length;i++)
    {
        L->r[i] = generate_rand_number_(RAND_NUM_FROM,RAND_NUM_TO);
    }
}

void tranverse_arraylist(ArrayList *L)
{
    int i;
    for(i=1;i <= L->length;i++)
    {
        printf("%5d",L->r[i]);
        if(i%ITEM_PER_NUM == 0)
        {
            printf("\n");
        }
    }
}

void BubbleSort(ArrayList *L)
{
    //采用降序排序
    int i,j;
    int ordered = 0;
    for(i = 1 ;i <= L->length && !ordered;i++)
    {
        ordered = 1;
        for(j = 1 ; j <= L->length -i ;j++)
        {
            if(L->r[j+1] < L->r[j])
            {
                //后面一个数更小
                swap(L,j+1,j);
                ordered = 0;
            }
            //把最小的放最后
            printf("[%d]",i);
            tranverse_arraylist(L);
            printf("\n");
        }
    }
}

void SelectSort(ArrayList *L)
{
    int min,i,j,index;
    for(i = 1;i <= L->length ; i++)
    {
        min = L->r[i];
        for(j=i;j <= L->length; j++)
        {
            if(L->r[j] < min )
            {
                min = L->r[j]; 
                index = j;
            }
        }
        swap(L,i,index);
    }
}

void StraightInsertSort(ArrayList *L)
{
       
}

void ShellSort(ArrayList *L)
{
    
}

void HeapSort(ArrayList *L)
{
    
}

void MergingSort(ArrayList *L)
{
    
}

void QuickSort(ArrayList *L)
{
    
}