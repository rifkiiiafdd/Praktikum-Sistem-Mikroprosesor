// Nama    : Rifki Afriadi
// NIM     : 13223049
// Tanggal : 17/10/2025
// Mengukur Kecepatan Konversi DAC pada ESP32 Dengan Software


#include "driver/dac.h"
const int pinOutputDAC = 25;                 
const dac_channel_t kanalDAC = DAC_CHANNEL_1;


unsigned long waktu_awal = 0;
unsigned long waktu_akhir = 0;
unsigned long interval = 0;
float rata_rata = 0;
int n = 100000; // jumlah pengukuran

void setup() {
   Serial.begin(115200);
  delay(1000);
  dac_output_enable(kanalDAC);

    // dac_output_enable(DAC_CHANNEL_1);

}

void loop() {
  interval = 0;
  waktu_awal = micros();


    for (int i = 0; i < n; i++) {
        // variasi 1   :
        // dacWrite(pinOutputDAC, 0);    
        // dacWrite(pinOutputDAC, 255);

        //variasi 2
        dac_output_voltage(kanalDAC, 0);    
        dac_output_voltage(kanalDAC, 255); 
    }
  

  waktu_akhir = micros();
    interval = waktu_akhir - waktu_awal;
    rata_rata = (float)interval / (2 * n); // karena ada 2 penulisan DAC tiap loop
    Serial.print("Waktu Konversi DAC (us): ");
    Serial.println(rata_rata);  
    delay(500);

}
