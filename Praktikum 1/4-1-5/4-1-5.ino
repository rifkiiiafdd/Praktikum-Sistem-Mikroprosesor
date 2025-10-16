#include "soc/gpio_struct.h"  
#include "driver/gpio.h"

#define INPUT_PIN   15  
#define OUTPUT_PIN  26  

void setup() {
    Serial.begin(115200);
    Serial.println("Halo ESP32");
    pinMode(INPUT_PIN, INPUT_PULLUP);   
    pinMode(OUTPUT_PIN, OUTPUT);
}

void loop() {
    int inputLevel = (REG_READ(GPIO_IN_REG) >> INPUT_PIN) & 0x1;

    if (inputLevel) {
        REG_WRITE(GPIO_OUT_W1TS_REG, (1 << OUTPUT_PIN)); 
    } else {
        REG_WRITE(GPIO_OUT_W1TC_REG, (1 << OUTPUT_PIN)); 
    }
}
