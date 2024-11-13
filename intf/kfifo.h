/**
 * OpenAUTOSAR - Open Source Automotive Open System Architect Labrary
 * Copyright (C) 2023 Althrone <mail>
 *
 * ref: 
 **/

/******************************************************************************
 * includes
 *****************************************************************************/

/******************************************************************************
 * pubilc types
 *****************************************************************************/

struct __kfifo
{
    unsigned int    in;
    unsigned int    out;
    unsigned int    mask;
    unsigned int    esize;
    void*           data;//void类型不支持灵活数组
};
