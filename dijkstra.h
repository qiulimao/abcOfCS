/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dijkstra.h
 * Author: zephyr
 *
 * Created on July 11, 2016, 8:29 PM
 */

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* DIJKSTRA_H */


typedef int Dijkstra_Pathmatric[MAX_SIZE];
typedef int Dijstra_Distancetable[MAX_SIZE];

void find_shortest_path_by_dijkstra(map *g,int v0,Dijkstra_Pathmatric *P,Dijstra_Distancetable *D);
int dijstra_show_shortest_path(Dijstra_Distancetable *Path,int size,int target,int start);