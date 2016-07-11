/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "graphic.h"



typedef int Pathmatric[MAX_SIZE][MAX_SIZE];
typedef int DistanceTable[MAX_SIZE][MAX_SIZE];

int generate_rand_number(){
    int num;
    //srand((unsigned int)(time(NULL)));
    num = rand()%100+1;
    //printf("the rand number is :%d\n", num);
    return num;
}

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
