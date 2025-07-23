#pragma once

#include "esphome/core/component.h"
#include <Wire.h>

namespace esphome {
namespace pcf8591 {

#define TIME_INTERVAL 1000
#define PCF8591 (0x90 >> 1) 

class PCF8591Component : public PollingComponent {
    public:
        PCF8591Component() : PollingComponent(TIME_INTERVAL) { }
        // ========== INTERNAL METHODS ==========
        // (In most use cases you won't need these)
        void setup() override;
        void dump_config() override;
        float get_setup_priority() const override;
        void update() override;      
          
    protected:
        sensor::Sensor *adc0;
        sensor::Sensor *adc1;
        sensor::Sensor *adc2;
        sensor::Sensor *adc3;
        byte value0, value1, value2, value3;
        
};

}  // namespace example_component
}  // namespace esphome


