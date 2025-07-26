#include "lights2_switch.h"

namespace esphome {
namespace balboa_spa {
void Lights2Switch::update(SpaState* spaState) {
    if(this->state != spaState->light2)
    {
        this->publish_state(spaState->light2);
    }
}

void Lights2Switch::set_parent(BalboaSpa *parent) {
    spa = parent;
    parent->register_listener([this](SpaState* spaState){ this->update(spaState); });
}

void Lights2Switch::write_state(bool state) {
    SpaState* spaState = spa->get_current_state();

    if(spaState->light2 != state){
        spa->toggle_light2();
    }
}

}  // namespace balboa_spa
}  // namespace esphome
