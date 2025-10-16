#include "soc/gpio_struct.h"  
#include "driver/gpio.h"

# define LED_PIN 26

void setup () {
    Serial.begin(115200);
    Serial.println("Hello, ESP32!");
    pinMode(LED_PIN, OUTPUT);
    setCpuFrequencyMhz(160); 
}

void loop () {
    // create a square wave on pin 22
    REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << LED_PIN)); 
    REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << LED_PIN)); 
}