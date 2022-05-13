//
// Created by miche on 03/04/2022.
//
#include <stdio.h>
# include "TD8.h"

int fibonacci_rec(int n) {
    int res;
    if (n == 0) {
        res = 0;
    } else {
        if (n == 1)
        {
            res = 1;
        }
        else
        {
            res = fibonacci_rec(n-1) + fibonacci_rec(n-2);
        }
    }
    return res;

}

int pgcd (int a, int b){

}







