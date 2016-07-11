/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   flody.h
 * Author: zephyr
 *
 * Created on July 11, 2016, 8:30 PM
 */

#ifndef FLODY_H
#define FLODY_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* FLODY_H */

typedef int Pathmatric[MAX_SIZE][MAX_SIZE];
typedef int DistanceTable[MAX_SIZE][MAX_SIZE];

void find_shortest_path_by_floyd(map *g,Pathmatric *P,DistanceTable *D);
void show_shortest_path(Pathmatric *P,DistanceTable *D,int from ,int to);
void show_all_path(Pathmatric *P,DistanceTable *D,int size);