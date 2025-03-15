#pragma once

// Use the following flags for compiling the right library, e.g.: -D STM32F1
#if defined(STM32F0)
#include "stm32f0xx_hal.h"
#elif defined(STM32F1)
#include "stm32f1xx_hal.h"
#elif defined(STM32F2)
#include "stm32f2xx_hal.h"
#elif defined(STM32F3)
#include "stm32f3xx_hal.h"
#elif defined(STM32F4)
#include "stm32f4xx_hal.h"
#elif defined(STM32F7)
#include "stm32f7xx_hal.h"
#elif defined(STM32H7)
#include "stm32h7xx_hal.h"
#else
#error "Unsupported STM32 microcontroller. Make sure you build with -D STM32F1 for example!"
#endif

#include <cstdint>

enum class LED_COLOR : uint8_t
{
    OFF = 0b000,
    RED = 0b100,
    GREEN = 0b010,
    BLUE = 0b001,
    YELLOW = 0b110,
    CYAN = 0b011,
    MAGENTA = 0b101,
    WHITE = 0b111,
};

class RGB_LED
{
public:
    RGB_LED(GPIO_TypeDef *port_r, uint16_t pin_r, GPIO_TypeDef *port_g, uint16_t pin_g, GPIO_TypeDef *port_b, uint16_t pin_b, bool low_active);

    void set_color(LED_COLOR color);
    void off();

private:
    GPIO_PinState _state_on, _state_off;

    GPIO_TypeDef *_port_r;
    GPIO_TypeDef *_port_g;
    GPIO_TypeDef *_port_b;
    uint16_t _pin_r, _pin_g, _pin_b;
};
