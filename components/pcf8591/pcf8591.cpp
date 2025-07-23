#include "esphome/core/log.h"
#include "pcf8591.h"
#include <Wire.h>

namespace esphome
{
    namespace pcf8591
    {

        static const char *TAG = "pcf8591.sensor";

        void PCF8591Component::setup()
        {
            ESP_LOGCONFIG(TAG, "Running setup");
            Wire.begin();
        }

        void PCF8591Component::update()
        {

            Wire.beginTransmission(PCF8591);
            Wire.write(0x04);
            Wire.endTransmission();
            Wire.requestFrom(PCF8591, 5);

            value0 = Wire.read();
            adc0->publish_state(value0);

            value1 = Wire.read();
            adc1->publish_state(value1);

            value2 = Wire.read();
            adc2->publish_state(value2);

            value3 = Wire.read();
            adc3->publish_state(value3);
        }

    } // namespace pcf8591
} // namespace esphome