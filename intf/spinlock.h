/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: OpenAI
 **/

/******************************************************************************
 * includes
 *****************************************************************************/

#include <stdatomic.h>
// #include <threads.h>//多核增加，直接放进来会报错

/******************************************************************************
 * pubilc types
 *****************************************************************************/

typedef struct
{
    atomic_flag lock;
}spinlock_t;

/******************************************************************************
 * pubilc function declaration
 *****************************************************************************/

void spin_lock(spinlock_t* lock);
void spin_unlock(spinlock_t* lock);