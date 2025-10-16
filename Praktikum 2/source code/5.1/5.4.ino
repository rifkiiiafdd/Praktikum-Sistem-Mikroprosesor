// Nama    : Rifki Afriadi
// NIM     : 13223049
// Tanggal : 17/10/2025
// Mengukur Kecepatan Konversi ADC pada ESP32 Dengan Software

// --- PIN DEFINITIONS ---
const int ADC_PIN = 34;    // Pin input ADC. 
const int TOGGLE_PIN = 2;  // Pin output osiloskop.

int waktu_awal = 0;
int waktu_akhir = 0;
int interval = 0;
float rata_rata = 0;
int n = 10000; // jumlah pengukuran

volatile int adc_result_local;

void setup() {
  // Inisialisasi pin output digital
    pinMode(TOGGLE_PIN, OUTPUT);

    analogSetWidth(9); 
  // analogSetWidth(12);

}

void loop() {
  interval = 0;
  waktu_awal = micros();


    for (int i = 0; i < n; i++) {
        adc_result_local = analogRead(ADC_PIN);
    }
  

  waktu_akhir = micros();
    interval = waktu_akhir - waktu_awal;
    rata_rata = interval / n;
    Serial.print("Waktu Konversi ADC (us): ");
    Serial.println(rata_rata);  
    delay(3000);

}
