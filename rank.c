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

void tranverse_arraylist(ArrayList *L,int emphasize)
{
    int i;
    for(i=1;i <= L->length;i++)
    {
        i == emphasize ? printf("%5d<-",L->r[i]):printf("%5d",L->r[i]);
        if(i%ITEM_PER_NUM == 0)
        {
            printf("\n");
        }
    }
}

/**
 * 
 * @param L 待排序的数组
 */
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
            tranverse_arraylist(L,0);
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

/**
 * 基本思想是：将一个记录插入到已经排好序的有序表中，
 * 从而得到一个新的，记录数增1的有序表
 * @param L
 */
void StraightInsertSort(ArrayList *L)
{
    int i,j;
    for(i=2;i<= L->length ; i++)
    {
        if(L->r[i] < L->r[i-1])
        {//要是后面一个数比前面一个小
            L->r[0] = L->r[i]; 
            for(j= i-1;L->r[j] > L->r[0];j--)
            {//循环的条件： 
                //这里其实很隐藏，j最终可能到0,但是r[0] > r[0] 为false，
                //最终这个循环终将结束。但是如果自己引入一个中间变量，仅仅依靠这个条件
                //不足以结束这个循环
                L->r[j+1] = L->r[j];                
            }
                
//            printf("\n");
//            tranverse_arraylist(L,i-1);              
            L->r[j+1] = L->r[0];
          
        }

    }
}

/**
 * 将数组当中的等间隔的数做排序
 * @param L
 * @param offset
 * @param step
 */
void PartSortByStaightInsert(ArrayList *L,int offset,int step)
{
    //还有一个问题没有解决，要是长度不是刚好为倍数的情况
    int i,j;
    int r0;
    //array_length = L->length / step; // 13/4=3....1
    for(i=offset+step;i<= L->length ; i += step)
    {

        if(L->r[i] < L->r[i-step])
        {//要是后面一个数比前面一个小
            r0 = L->r[i]; 
            for(j= i-step;L->r[j] > r0 && j >= offset;j -= step)
            {//循环的条件： 
                //printf("\ncurrent i=%d;j=:%d\n",i,j);
                //tranverse_arraylist(L,i-step); 
                L->r[j+step] = L->r[j];
                               
            }            
            L->r[j+step] = r0;
        }

    }    
}

/**
 * 先取一个小于n的整数d1作为第一个增量，把文件的全部记录分成d1个组。
 * 所有距离为dl的倍数的记录放在同一个组中。
 * 先在各组内进行直接插人排序；
 * 然后，取第二个增量d2<d1重复上述的分组和排序，
 * 直至所取的增量dt=1(dt<dt-l<…<d2<d1)，
 * 即所有记录放在同一组中进行直接插入排序为止。
 * @param L
 */
void ShellSort(ArrayList *L)
{
    int step,i,reduce_factor;

    reduce_factor = 2;    
    step = L->length / reduce_factor;

    while(step>1)
    {
        
        //printf("current step is :%d\n",step);
        for(i=1;i<=step;i++)
        {
           PartSortByStaightInsert(L,i,step); 
        }
        //tranverse_arraylist(L,0);
        step = step / reduce_factor ;
    }
    PartSortByStaightInsert(L,1,1);
}

void __heapAdjust(ArrayList *L,int s,int m)
{
    int temp,j;
    temp = L->r[s]; 
    for(j=2*s ; j<= m;j *= 2)
    {
        if(j<m && L->r[j] < L->r[j+1])
        {
            j ++;
        }
        
        if(temp >= L->r[j])
        {
            break;
        }
        
        L->r[s] = L->r[j];
        L->r[j] = temp;
        s = j;
    }
    //L->r[s] = temp;//这句话我感觉是多余的。
    
}

/**
 * 1)将初始待排序关键字序列(R1,R2....Rn)构建成大顶堆，此堆为初始的无须区；
 * 2)将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1,R2,......Rn-1)和新的有序区(Rn),且满足R[1,2...n-1]<=R[n];
 * 3)由于交换后新的堆顶R[1]可能违反堆的性质，
 * 因此需要对当前无序区(R1,R2,......Rn-1)调整为新堆，
 * 然后再次将R[1]与无序区最后一个元素交换，
 * 得到新的无序区(R1,R2....Rn-2)和新的有序区(Rn-1,Rn)。
 * 不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。
 * @param L
 */
void HeapSort(ArrayList *L)
{
    int i;
    for(i = L->length / 2 ; i > 0;i--)
    {
        __heapAdjust(L,i,L->length);
    }
    
    for(i = L->length; i > 1;i--)
    {
        swap(L,1,i);
        __heapAdjust(L,1,i-1);
    }
}



void __merge(int from[],int to[],int start,int middle,int end)
{
    int pointer1,pointer2,index;
    pointer1 = start;
    pointer2 = middle + 1;
    index=start;  //在这个位置上犯了错误，导致我调试了很久无果。
    while(pointer1 <= middle && pointer2 <=end)
    {
        if(from[pointer1] <= from[pointer2])
        {
            to[index] = from[pointer1];
            index ++;
            pointer1 ++;
        }
        else
        {
            to[index] = from[pointer2];
            index ++;
            pointer2 ++;            
        }
    }
    
    while(pointer1 <= middle)
    {
       to[index] = from[pointer1];
       index ++;
       pointer1 ++;       
    }
    while(pointer2 <= end)
    {
       to[index] = from[pointer2];
       index ++;
       pointer2 ++;           
    }

}

void __msort(int origin[],int swap[],int start,int end)
{
    int m;
    int temp[LIST_SIZE+1];
    if(start == end)
    {
        swap[start]=origin[start];
        return;
    }
    m = (start + end)/2;
    
    __msort(origin,temp,start,m);
    __msort(origin,temp,m+1,end);
    __merge(temp,swap,start,m,end);
    
}
void MergingSort(ArrayList *L)
{
    
    __msort(L->r,L->r,1,L->length);
    
}

/**
 * 选取一个关键字，然后将它放到一个位置，是的左边的值都比他小，右边的值都比他大并返回他的位置
 * @param L
 * @param low
 * @param high
 */
int __partion(ArrayList *L,int low,int high)
{
    int center_val;
    center_val = L->r[low];
    
    while(low < high)
    {
        //有没有可能 low不加，high不减的情况?
        while(low < high && L->r[high] >= center_val)
        {
            high -- ;
        }
        swap(L,low,high);
        while(low < high && L->r[low] <= center_val) 
        {
            low ++;
        }
        swap(L,low,high);
    }
    
    return high;
    
}

void __Qsort(ArrayList *L,int low,int high)
{
    int middle;
    if(low < high)
    {
        middle = __partion(L,low,high);
        __Qsort(L,low,middle-1);
        __Qsort(L,middle+1,high);
    }
}

/**
 * 通过一趟排序将要排序的数据分割成独立的两部分，
 * 其中一部分的所有数据都比另外一部分的所有数据都要小，
 * 然后再按此方法对这两部分数据分别进行快速排序，
 * 整个排序过程可以递归进行，
 * 以此达到整个数据变成有序序列。
 * @param L
 */
void QuickSort(ArrayList *L)
{
    __Qsort(L,1,L->length);
}

/**
 * 检查排序的结果是否正确
 * @param L
 * @return boolean 
 */
int TestSortResult(ArrayList *L)
{
   int order,current_order;
   int i;
   order = L->r[2] >= L->r[1] ? 1 : 0;
   for(i=2;i<=L->length;i++)
   {
       current_order = L->r[i] >= L->r[i-1] ? 1 : 0;
       
       if(current_order != order)
           return 0;
   }
   
   return 1;
}