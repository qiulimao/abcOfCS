/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<stdio.h>
#include<stdlib.h>
#include "graphic.h"
#include "dijkstra.h"

void find_shortest_path_by_dijkstra(map *g,int v0,Dijkstra_Pathmatric *P,Dijstra_Distancetable *D)
{
	int v,w,k,min;
	int final[MAX_SIZE]; // ==1 表式这个点已经确定好了。
	/*初始化，*/
	for(v=0;v<g->vertex_num;v++)
	{
		(*P)[v] = 0;
		(*D)[v] = g->matric[v0][v];
		final[v] = 0;
	}
	(*P)[v0] = 0;
	final[v0] = 1;

	for(v=0;v<g->vertex_num;v++)
	{
		min = INFINITE;
		for(w=0;w<g->vertex_num;w++)
		{
			if(!final[w] && (*D)[w] < min ) 
			{//从U集合当中，选出一个代价最小的点。
				min = (*D)[w];
				k = w;
			}
		}

		final[k] = 1;//将这个点加到S集合当中

		for(w=0;w<g->vertex_num;w++)//修改链路权值。
		{
			if(!final[w] &&   (g->matric[k][w]+min < (*D)[w]) )
			{
				(*D)[w] = g->matric[k][w] + min;
				(*P)[w] = k;
			}
		}
	}
}

int dijstra_show_shortest_path(Dijstra_Distancetable *Path,int size,int target,int start)
{
	int path_indicator;
	int i;
	if(target > size-1)
	{
		return 0;
	}
	printf("the path indicator for[%d]:\n",start);
	for(i=0;i<size;i++)
	{
		printf("[%d]=%d |",i,(*Path)[i]);
	}
	printf("\n-----:\n %d->",target);

	path_indicator=(*Path)[target];

	
	while(path_indicator)
	{
            printf("%d->",path_indicator);
            path_indicator = (*Path)[path_indicator];
	}
	printf("%d....\n\n",start);
	return 0;
}