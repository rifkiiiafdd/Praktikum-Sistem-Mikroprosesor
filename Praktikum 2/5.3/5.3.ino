// Nama    : Rifki Afriadi
// NIM     : 13223049
// Tanggal : 17/10/2025
// Mengukur Kecepatan Konversi ADC pada ESP32 Dengan Alat Ukur

// --- PIN DEFINITIONS ---
const int ADC_PIN = 34;    // Pin input ADC. 
const int TOGGLE_PIN = 2;  // Pin output osiloskop.
void setup() {
  // Inisialisasi pin output digital
    pinMode(TOGGLE_PIN, OUTPUT);

    // analogSetWidth(9); 
  // analogSetWidth(12);
  analogReadResolution(12);

}

void loop() {
  analogRead(ADC_PIN);

  REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) | (1 << TOGGLE_PIN));
  analogRead(ADC_PIN);
  REG_WRITE(GPIO_OUT_REG, REG_READ(GPIO_OUT_REG) & ~(1 << TOGGLE_PIN));

}
