# define pin_used 22


void setup () {
    Serial.begin(115200);
    Serial.println("Hello, ESP32!");


    pinMode(pin_used, OUTPUT);
}

void loop () {
    // create a square wave on pin 22
    GPIO.out_w1ts = (1 << pin_used);
    GPIO.out_w1tc = (1 << pin_used);
    
}