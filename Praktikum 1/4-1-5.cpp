#define INPUT_PIN   25  
#define OUTPUT_PIN  22  

void setup() {
    Serial.begin(115200);
    Serial.println("Halo ESP32");

    pinMode(INPUT_PIN, INPUT_PULLUP);   
    
    pinMode(OUTPUT_PIN, OUTPUT);
}

void loop() {
    // GPIO_IN_REG berisi status semua pin GPIO (bit = 1 berarti HIGH)
    // REG_READ() membaca seluruh register, kemudian kita ambil bit untuk pin yang diinginkan
    int inputLevel = (REG_READ(GPIO_IN_REG) >> INPUT_PIN) & 0x1;


    if (inputLevel) {
        // Set HIGH
        REG_WRITE(GPIO_OUT_W1TS_REG, (1 << OUTPUT_PIN));  // Write-1-to-Set
    } else {
        // Set LOW
        REG_WRITE(GPIO_OUT_W1TC_REG, (1 << OUTPUT_PIN));  // Write-1-to-Clear
    }
}
