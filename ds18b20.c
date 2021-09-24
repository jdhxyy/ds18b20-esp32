// Copyright 2020-2021 The jdh99 Authors. All rights reserved.
// DS18B20驱动模块
// Authors: jdh99 <jdh821@163.com>

#include "ds18b20.h"
#include "drvds18b20.h"
#include "bror.h"
#include "lagan.h"

#define TAG "ds18b20"

// 线程堆栈大小.单位:KByte
#define THREAD_STACK_SIZE 4

static float tempNow = 0;

static void ds18b20Thread(void* param);

// Ds18b20Load 模块载入
void Ds18b20Load(int pin) {
    ds18b20_init(pin);
    BrorThreadCreate(ds18b20Thread, "ds18b20Thread", BROR_THREAD_PRIORITY_MIDDLE, 
        THREAD_STACK_SIZE * 1024);
}

static void ds18b20Thread(void* param) {
    BrorDelayMS(1);

    while (1) {
        tempNow = ds18b20_get_temp();
        LD(TAG, "get temp:%f", tempNow);
        BrorDelay(1);
    }

    BrorThreadDeleteMe();
}

// Ds18b20Get 读取温度
float Ds18b20Get(void) {
    return tempNow;
}