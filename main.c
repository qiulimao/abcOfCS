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
#include "graphic.h"
/*
 * 
 */
void main() {

    map g;
    g.vertex_num = 10;
    get_random_graph(&g);
    tranverse_graph(&g);
}

