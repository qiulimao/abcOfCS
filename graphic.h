/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graphic.h
 * Author: zephyr
 *
 * Created on July 11, 2016, 7:35 PM
 */

#ifndef GRAPHIC_H
#define GRAPHIC_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* GRAPHIC_H */

#define MAX_SIZE 30
#define INFINITE 8080

typedef struct map{
	int vertex_num;
	int matric[MAX_SIZE][MAX_SIZE];
}map;

extern void get_random_graph(map *g);
extern void tranverse_graph(map *g);