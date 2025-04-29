#include "RGB_LED.hpp"

RGB_LED::RGB_LED(GPIO_TypeDef *port_r, uint16_t pin_r, GPIO_TypeDef *port_g, uint16_t pin_g, GPIO_TypeDef *port_b, uint16_t pin_b, bool low_active) : _port_r(port_r), _pin_r(pin_r), _port_g(port_g), _pin_g(pin_g), _port_b(port_b), _pin_b(pin_b)
{
    if (low_active)
    {
        _state_on = GPIO_PIN_RESET;
        _state_off = GPIO_PIN_SET;
    }
    else
    {
        _state_on = GPIO_PIN_SET;
        _state_off = GPIO_PIN_RESET;
    }

    off();
}

void RGB_LED::set_color(LED_COLOR color)
{
    off();

    if (static_cast<uint8_t>(color) & 0b100 && _port_r != nullptr)
    {
        HAL_GPIO_WritePin(_port_r, _pin_r, _state_on);
    }
    if (static_cast<uint8_t>(color) & 0b010 && _port_g != nullptr)
    {
        HAL_GPIO_WritePin(_port_g, _pin_g, _state_on);
    }
    if (static_cast<uint8_t>(color) & 0b001 && _port_b != nullptr)
    {
        HAL_GPIO_WritePin(_port_b, _pin_b, _state_on);
    }
}

void RGB_LED::off()
{
    if (_port_r != nullptr)
    {
        HAL_GPIO_WritePin(_port_r, _pin_r, _state_off);
    }
    if (_port_g != nullptr)
    {
        HAL_GPIO_WritePin(_port_g, _pin_g, _state_off);
    }
    if (_port_b != nullptr)
    {
        HAL_GPIO_WritePin(_port_b, _pin_b, _state_off);
    }
}