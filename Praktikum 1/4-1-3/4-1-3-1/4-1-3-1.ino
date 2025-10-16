#include "soc/gpio_struct.h"  
#include "driver/gpio.h"

# define pin_used 2

void setup () {
    Serial.begin(115200);
    Serial.println("Hello, ESP32!");
    pinMode(pin_used, OUTPUT);
    setCpuFrequencyMhz(240); 

}

void loop () {
    // create a square wave on pin 22
    delay(1000);
    GPIO.out_w1ts = (1 << pin_used);
    delay(1000);
    GPIO.out_w1tc = (1 << pin_used);
    
}


