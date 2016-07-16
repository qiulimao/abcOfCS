/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rank.h
 * Author: zephyr
 *
 * Created on July 15, 2016, 6:07 PM
 */

#ifndef RANK_H
#define RANK_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* RANK_H */

#define LIST_SIZE 100
#define RAND_NUM_FROM 1
#define RAND_NUM_TO   1000
#define ITEM_PER_NUM 20

typedef struct ArrayList
{
    int r[LIST_SIZE + 1];
    int length;
}ArrayList;

void swap(ArrayList *L,int i,int j);
void tranverse_arraylist(ArrayList *L);
void generate_random_list(ArrayList *L,int length);

void BubbleSort(ArrayList *L);
void SelectSort(ArrayList *L);
void StraightInsertSort(ArrayList *L);
void ShellSort(ArrayList *L);
void HeapSort(ArrayList *L);
void MergingSort(ArrayList *L);
void QuickSort(ArrayList *L);