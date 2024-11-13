/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: OpenAI
 **/

/******************************************************************************
 * includes
 *****************************************************************************/

#include "spinlock.h"

#define SPINLOCK_INIT { ATOMIC_FLAG_INIT }

/******************************************************************************
 * private types
 *****************************************************************************/

/******************************************************************************
 * pubilc function definition
 *****************************************************************************/

void spin_lock(spinlock_t* lock)
{
    // while (atomic_flag_test_and_set(&lock->lock))
    while(atomic_flag_test_and_set_explicit(&lock->lock,memory_order_acquire))
    {
        /* spin */
    }
}

void spin_unlock(spinlock_t* lock)//写lock值为0，store操作，
{
    // atomic_flag_clear(&lock->lock);
    atomic_flag_clear_explicit(&lock->lock,memory_order_release);
}

/******************************************************************************
 * note
 *****************************************************************************/

/*

atomic_flag_test_and_set 和 atomic_flag_test_and_set_explicit 的区别：
    xxx_explicit 会指定内存序， atomic_flag_test_and_set 默认内存序为CTS，如果是
    多核来抢占， acquire 会等待锁，解锁情况下，已经持有锁了，所以他之前肯定没有写操作

*/