/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<stdio.h>
#include<stdlib.h>
#include "graphic.h"
#include "aov.h"

void deleteOutEdge(AdjacentListMap *G,vertex *v)
{
    edge *e,*to_delete;
    int index;
    if(v->first_out)
    {
        e = v->first_out;
        while(e)
        {
            index = e->to;
            (*G)[index].in --;
            //to_delete = e;
            e = e->next;
            //free(to_delete);
        }
    }
}

void topo_rank(AdjacentListMap *G,int size)
{
    int i;
    int final[MAX_SIZE];
    for(i=0;i<size;i++)
    {
        final[i] = 0;
    }
    
    for(i=0;i<size;i++)
    {
        if((*G)[i].in == 0 && !final[i])
        {
            deleteOutEdge(G,&(*G)[i]);
            final[i] = 1;
            printf("(%d)",i);
            
        }
    }
}