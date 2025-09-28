# define pin_number 22


void setup () {
    Serial.begin(115200);
    Serial.println("Hello, ESP32!");


    pinMode(pin_number, OUTPUT);
}

void loop () {
    // create a square wave on pin 22
    digitalWrite(pin_number, HIGH);
    
    digitalWrite(pin_number, LOW);
    
    
}