#include <stdint.h>
#include <string>

#ifndef SPA_CONFIG_H
#define SPA_CONFIG_H

namespace esphome {
namespace balboa_spa {
struct SpaConfig {
    public:
        uint8_t pump1 :1; //this could be 1=1 speed; 2=2 speeds
        uint8_t pump2 :1;
        uint8_t pump3 :1;
        uint8_t pump4 :1;
        uint8_t pump5 :1;
        uint8_t pump6 :1;
        uint8_t light1 :1;
        uint8_t light2 :1;
        uint8_t circ :1;
        uint8_t blower :1;
        uint8_t mister :1;
        uint8_t aux1 :1;
        uint8_t aux2 :1;
        uint8_t temp_scale :1; //1 -> Farenheit, 0-> Celcius
};

}  // namespace empty_uart_component
}  // namespace esphome

#endif