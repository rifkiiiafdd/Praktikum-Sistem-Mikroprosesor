#define LED_PIN 22  // Lolin32 
#define INPUT_1 25 
#define INPUT_2 33 
#define OUTPUT_1 22 
#define OUTPUT_2 19 
void setup() { 
    pinMode(INPUT_1, INPUT_PULLUP); 
    pinMode(INPUT_2, INPUT_PULLUP); 
    pinMode(OUTPUT_1, OUTPUT); 
    pinMode(OUTPUT_2, OUTPUT); 
    Serial.begin(115200); 
    Serial.println("ESP32 Started"); 
} 
void loop() { 
    int input1, input2; 
    input1 = digitalRead(INPUT_1); 
    input2 = digitalRead(INPUT_2); 
    digitalWrite(OUTPUT_1, input1); 
    digitalWrite(OUTPUT_2, input2); 
    Serial.print(input1); 
    Serial.print(" "); 
    Serial.println(input2); 
    delay(1000); 
} 