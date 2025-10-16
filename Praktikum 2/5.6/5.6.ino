// Nama    : Rifki Afriadi
// NIM     : 13223049
// Tanggal : 17/10/2025
// Mengukur Kecepatan Konversi DAC pada ESP32 Dengan Software


#include "driver/dac.h"
const int DAC_PIN = 25; 


unsigned long waktu_awal = 0;
unsigned long waktu_akhir = 0;
unsigned long interval = 0;
float rata_rata = 0;
int n = 10000; // jumlah pengukuran

void setup() {

    dac_output_enable(DAC_CHANNEL_1);

}

void loop() {
  interval = 0;
  waktu_awal = micros();


    for (int i = 0; i < n; i++) {
        // variasi 1   :
        dacWrite(DAC_PIN, 0);
        dacWrite(DAC_PIN, 255);

        // Variasi 2   :
        dac_output_voltage(DAC_CHANNEL_1, 0);
        dac_output_voltage(DAC_CHANNEL_1, 255);
    }
  

  waktu_akhir = micros();
    interval = waktu_akhir - waktu_awal;
    rata_rata = (float)interval / (2 * n); // karena ada 2 penulisan DAC tiap loop
    Serial.print("Waktu Konversi DAC (us): ");
    Serial.println(rata_rata);  
    delay(3000);

}
