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
 * 获取随机数0~100的一个。
 */
int generate_rand_number(){
    int num;
    num = rand()%100+1;
    return num;
}

/*
 * 初始化一张用邻接矩阵标示的图。
 */
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
 * direct 标示该图是否有方向性 1标示有，0标示无
 * max_weigth:最大的权值，随机产生1~100，超过max_weight记为不可达INFINTE
 */
void get_random_graph(map *g,int direct,int max_weight)
{
    int i,j,random_number1,random_number2;
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
                random_number1 = generate_rand_number();
                random_number2 = generate_rand_number();
                if(direct)
                {
                    g->matric[i][j] = random_number1 > max_weight ? INFINITE : random_number1;
                    g->matric[j][i] = random_number2 > max_weight ? INFINITE : random_number2;
                }
                else
                {
                    g->matric[i][j] = g->matric[j][i] = random_number1 > max_weight ? INFINITE : random_number1;
                }
                
            }
        }
    }
}

/*
 *遍历一张图，输入参数为邻接矩阵图的指针
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
 * 数组的指针，和数组的大小
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


/*
 *向图的一个顶点添加一条边。
 * 输入参数：
 *      顶点 vertex
 *      起始点 from
 *      尾节点 to
 *      边的权值 weight
 **/
void addEdge(vertex *v,int from,int to,int weight)
{
    edge *e,*last_edge;
    e = (edge *)malloc(sizeof(edge));
    e->from = from;
    e->to = to;
    e->weight = weight;
    e->next = NULL;

    
    last_edge = v->first_out;
    if(last_edge==NULL)
    {
        //当前还没有边，那么直接添加上
        v->first_out = e;
        return;
    }
    while(last_edge!=NULL && last_edge->next!=NULL)
    {
        last_edge = last_edge->next;
    }
    last_edge->next = e;
    
}

/*
 * 删除一条边
 */
void deleteEdge(vertex *v,int pos)
{
    edge *e,*next,*before,*target;
    int i;
    if(pos == 0)
    {
        e  = v->first_out;
        if(e->next)
        {
            v->first_out = e->next;
            e->next = NULL;
            free(e);
        }
        else
        {
            v->first_out = NULL;
        }
    }
    
    before = v->first_out;
    i= 0;
    while(before->next && i < pos-1)
    {
        i++;
        before = before->next;
    }
    
    target = before->next;
    
    if(target->next)
    {
        before->next = target->next;
        target->next = NULL;
        free(target);
    }
    else
    {
        before->next = NULL;
        free(target);
    }
    
}

/*
 * 将矩阵表示法 转化为出边表 标示法。
 */
int adaptMatricMap2ListMap(map *g,AdjacentListMap *G)
{
    int i,in,j;
    edge *e;
    for(i=0;i < g->vertex_num ;i ++)
    {
        //(*G)[i]
        in = 0;
        for(j=0;j< g->vertex_num;j++)
        {
            if(g->matric[j][i] != INFINITE && g->matric[j][i] != 0)
            {
                in += 1;
            }
        }
        (*G)[i].in = in;
        //以上统计入度
        (*G)[i].first_out = NULL;
    }
    
    for(i=0;i < g->vertex_num; i++)
    {
        
        for(j=0;j < g->vertex_num ;j++)
        {
            if(g->matric[i][j] != 0 && g->matric[i][j] != INFINITE)
            {//不是自己连自己，也不是不可达，添加出边表
                //这个错误主要错在 传递参数问题：
                // 总之还是指针没有搞清楚
                addEdge(&(*G)[i],i,j,g->matric[i][j]);
                //addEdge(G[i],i,j,g->matric[i][j]); //这种写法是错误的。
            }
        }
    }
    return g->vertex_num;
}

/*
 * 遍历图边表
 */
void tranverseListMap(AdjacentListMap *G,int size)
{
    int i;
    vertex v;
    edge *e;
    for(i=0;i<size;i++)
    {
        v = (*G)[i];
        printf("[#%d#in:%d]",i,v.in);
        if(v.first_out)
        {
            e = v.first_out;
            while(e) 
            {
                printf("--->");
                printf("(from:%2d,to:%2d,weigth:%2d)",e->from,e->to,e->weight);
                e = e->next;
            }
        }
        printf("\n");
    }
}
