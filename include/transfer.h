/*
** EPITECH PROJECT, 2018
** 107transfer.h
** File description:
** 107transfer.h
*/

#ifndef TRANSFER_H_
#define TRANSFER_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

#define USAGE ("README")
#define EXIT_SUCCESS 0
#define EXIT_ERROR 84

typedef struct numbers_s {
    double **nb1;
    double **nb2;
    int *occ1;
    int *occ2;
} numbers_t;

int transfer(int ac, char **av);
bool parser(int ac, char **av);
char *my_revstr(char *str);
int compute_simple(int ac, char **av);
char *my_revstr(char *str);


#endif /* TRANSFER_H_ */
