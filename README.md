# ds18b20-esp32

## 1. 介绍
esp32的ds18b20驱动。

## 2. API
```c
// Ds18b20Load 模块载入
void Ds18b20Load(int pin);

// Ds18b20Get 读取温度
float Ds18b20Get(void);
```

## 3. 参考资料
- 驱动使用库：https://github.com/feelfreelinux/ds18b20.git
