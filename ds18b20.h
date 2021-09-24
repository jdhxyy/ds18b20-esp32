// Copyright 2020-2021 The jdh99 Authors. All rights reserved.
// DS18B20驱动模块
// Authors: jdh99 <jdh821@163.com>

#ifndef DS18B20_H
#define DS18B20_H

#include <stdint.h>

// Ds18b20Load 模块载入
void Ds18b20Load(int pin);

// Ds18b20Get 读取温度
float Ds18b20Get(void);

#endif
