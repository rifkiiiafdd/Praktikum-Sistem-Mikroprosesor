// Nama    : Rifki Afriadi
// NIM     : 13223049
// Tanggal : 17/10/2025
// Mengukur Kecepatan Konversi DAC pada ESP32 Dengan Alat Ukur
#include "driver/dac.h"
const int DAC_PIN = 25; 

void setup() {
  // Inisialisasi DAC
  dac_output_enable(DAC_CHANNEL_1);
}

void loop() {
    
    dacWrite(DAC_PIN, 0);
    
    dacWrite(DAC_PIN, 255);

    // Variasi 2   :

    // dac_output_voltage(DAC_CHANNEL_1, 0);
    
    // dac_output_voltage(DAC_CHANNEL_1, 255);
    
}