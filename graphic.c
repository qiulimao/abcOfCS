/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "graphic.h"

/*
 * 获取随机数
 */
int generate_rand_number(){
    int num;
    num = rand()%100+1;
    return num;
}

int init_graph(map *g,int size)
{
    if (size > MAX_SIZE)
    {
        return 0;
    }
    else
    {
        g->vertex_num = size;
        return 1;
    }
    
}

/*
 * 获取一张随机的图
 */
void get_random_graph(map *g)
{
    int i,j,random_number;
    srand((unsigned int)(time(NULL))); // call this onetime
    
    for(i=0;i<g->vertex_num;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(i==j){
                g->matric[i][j] = 0;
            }
            else
            {
                random_number = generate_rand_number();
                g->matric[i][j] = g->matric[j][i] = random_number>40 ? INFINITE : random_number;
            }
        }
    }
}

/*
 *遍历一张图
 */
void tranverse_graph(map *g){
	int i,j;
	printf("    ");
	for(i=0;i<g->vertex_num;i++){
		printf("%5d_",i);
	}
	printf("\n");
	for(i=0;i<g->vertex_num;i++)
	{
            printf("_%2d_",i);
            for(j=0;j<g->vertex_num;j++)
            {

                if(g->matric[i][j]==INFINITE){
                    printf("%5s|","#");
                }
                else{
                    printf("%5d|",g->matric[i][j]);
                }
            }
            printf("\n");
	}
}

/*
 *遍历一个二维数组
 */
void tranverse_two_matric(dimession2 *matric,int size)
{
	int i,j;
	printf("    ");
	for(i=0;i<size;i++){
		printf("%5d_",i);
	}
	printf("\n");
	for(i=0;i<size;i++)
	{
            printf("_%2d_",i);
            for(j=0;j<size;j++)
            {

                if((*matric)[i][j]==INFINITE){
                    printf("%5s|","#");
                }
                else{
                    printf("%5d|",(*matric)[i][j]);
                }
            }
            printf("\n");
	}
}