#define INPUT_PIN 15
#define OUTPUT_PIN 26

void setup() {
    pinMode(INPUT_PIN, INPUT_PULLUP);
    setCpuFrequencyMhz(240); 
    pinMode(OUTPUT_PIN, OUTPUT);
    Serial.begin(115200);
    Serial.println("Halo ESP32");
    
}

void loop() {
    int input1;
    input1 = digitalRead(INPUT_PIN);
    digitalWrite(OUTPUT_PIN, input1);
}