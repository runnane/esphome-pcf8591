import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import UNIT_EMPTY, ICON_EMPTY

pcf8591_ns = cg.esphome_ns.namespace("pcf8591")
PCF8591Sensor = pcf8591_ns.class_("PCF8591Sensor", cg.PollingComponent)

CONFIG_SCHEMA = sensor.sensor_schema(
    PCF8591Sensor,
    unit_of_measurement=UNIT_EMPTY,
    icon=ICON_EMPTY,
    accuracy_decimals=1,
).extend(cv.polling_component_schema("60s"))


async def to_code(config):
    var = await sensor.new_sensor(config)
    await cg.register_component(var, config)
