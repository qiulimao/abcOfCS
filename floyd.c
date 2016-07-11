/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<stdio.h>
#include<stdlib.h>
#include "graphic.h"
#include "flody.h"


/*
 使用floyd 算法查找最短路径。
 * 输入参数：
 *      g:图的地址
 *      Pathmatric : 路径的地址
 *      DistanceTable: 路径的权值
 */
void find_shortest_path_by_floyd(map *g,Pathmatric *P,DistanceTable *D)
{
    int i,j,k;
    //这个循环初始化
    for(i=0;i< g->vertex_num ; i++)
    {
        for(j=0;j < g->vertex_num ; j++)
        {
            (*D)[i][j] = g->matric[i][j];
            (*P)[i][j] = j;
        }
    }
    
    //开始迭代
    for(k=0;k < g->vertex_num ; k++)
    {// k循环所有的点。
        for(i=0;i< g->vertex_num ; i++)
        {
            for(j=0;j < g->vertex_num ; j++)
            {
                if( (*D)[i][j] > (*D)[i][k] + (*D)[k][j] )
                {
                    (*D)[i][j]  =  (*D)[i][k] + (*D)[k][j];
                    (*P)[i][j]  =  (*P)[i][k];// 这里我没有搞明白。为什么是 (*P)[i][k]
                    // P 的含义是： 经过的中间节点。/						
                }
            }
        }		
    }
}

/*
 * 查看最短的路径
 * 
 */
void show_shortest_path(Pathmatric *P,DistanceTable *D,int from ,int to)
{
	int next;
	next = from;
	while(next != to)
	{
            printf("%d -> ", next);
            next = (*P)[next][to];
		
	}
	printf("%d\n",to);
}

/*
 * 查看所有的路径
 **/
void show_all_path(Pathmatric *P,DistanceTable *D,int size)
{
	int i,j;
	for(i = 0;i < size ;i++)
	{
            for(j = 0;j < size ;j ++)
            {	
                printf("from [%d]->[%d]:",i,j);
                show_shortest_path(P,D,i,j);
            }
	}
}