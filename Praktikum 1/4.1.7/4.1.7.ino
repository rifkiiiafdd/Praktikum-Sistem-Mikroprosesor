const int pin_input = 25;        
volatile unsigned long counter = 0; 

const unsigned long period_ms = 1000; // interval pengukuran

void IRAM_ATTR countPulse() {
  counter++;  // ISR: dipanggil setiap ada tepi sinyal
}

void setup() {
  Serial.begin(115200);

  pinMode(pin_input, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pin_input), countPulse, RISING);
}

void loop() {
  delay(period_ms);  
  
  noInterrupts();
  unsigned long pulses = counter;
  counter = 0;        
  interrupts();

  // frekuensi (Hz) 
  Serial.printf("Frekuensi: %lu Hz\n", pulses);
}
