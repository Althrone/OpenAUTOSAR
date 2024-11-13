/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

/******************************************************************************
 * includes
 *****************************************************************************/

#include "kfifo.h"
#include <stdbool.h>
#include <stddef.h>

/******************************************************************************
 * private types
 *****************************************************************************/

/******************************************************************************
 * private function declaration
 *****************************************************************************/

/******************************************************************************
 * pubilc function definition
 *****************************************************************************/

int __kfifo_init(struct __kfifo* fifo,void* buffer,
                 unsigned int size,size_t esize)
{
    size /= esize;

    if (!is_power_of_2(size))
        size = rounddown_pow_of_two(size);

    fifo->in = 0;
    fifo->out = 0;
    fifo->esize = esize;
    fifo->data = buffer;

    if (size < 2) {
        fifo->mask = 0;
        return -EINVAL;
    }
    fifo->mask = size - 1;

    return 0;
}

/******************************************************************************
 * private function definition
 *****************************************************************************/

static inline __attribute__((const))//暂时不知道__attribute__((const))干嘛用的
bool is_power_of_2(unsigned long n)
{
    return (n!=0&&((n&(n-1))==0));
}