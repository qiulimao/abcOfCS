/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: zephyr
 *
 * Created on July 11, 2016, 9:29 AM
 */


#include <stdio.h>
#include <stdlib.h>
/*

#include "graphic.h"
#include "flody.h"
#include "dijkstra.h"
#include "aov.h"
*/

#include "rank.h"
/*
 * 
 */



void main() {

//    map g;
//    AdjacentListMap G;
//    Pathmatric P;
//    DistanceTable  D;
//    init_graph(&g,10);
//    get_random_graph(&g,1,30);
//    
//    printf("the original random graph\n");
//    tranverse_graph(&g);
    
//    find_shortest_path_by_floyd(&g,&P,&D);
//    printf("the shorest path matric\n");
//    
//    tranverse_two_matric(&P,10);
//    printf("the distance matric\n");
//    tranverse_two_matric(&D,10);
//    show_shortest_path(&P,&D,1,8);
//    printf("I am executed...[%d]\n",adaptMatricMap2ListMap(&g,&G));
//    tranverseListMap(&G,g.vertex_num);
//    topo_rank(&G,g.vertex_num);
    
    ArrayList list,*l;
    l = &list;
    generate_random_list(l,10);
    tranverse_arraylist(l);
    SelectSort(l);
    printf("\n");
    tranverse_arraylist(l);
}

