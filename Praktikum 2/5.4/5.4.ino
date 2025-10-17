// Nama    : Rifki Afriadi
// NIM     : 13223049
// Tanggal : 17/10/2025
// Mengukur Kecepatan Konversi ADC pada ESP32 Dengan Software

// --- PIN DEFINITIONS ---
const int ADC_PIN = 34;    // Pin input ADC. 
const int TOGGLE_PIN = 2;  // Pin output osiloskop.

unsigned long waktu_awal = 0;
unsigned long waktu_akhir = 0;
unsigned long interval = 0;
float rata_rata = 0;

int n = 90000; // jumlah pengukuran

volatile int adc_result_local;

void setup() {
  // Inisialisasi pin output digital
    pinMode(TOGGLE_PIN, OUTPUT);

    // analogSetWidth(9); 
    analogReadResolution(12);
  // analogSetWidth(12);
  Serial.begin(115200);
  Serial.println("=== Mengukur Kecepatan ADC dengan software  ===");

}

void loop() {
  interval = 0;
  waktu_awal = micros();


    for (int i = 0; i < n; i++) {
        adc_result_local = analogRead(ADC_PIN);
    }
  

  waktu_akhir = micros();
    interval = waktu_akhir - waktu_awal;
    rata_rata = (float)interval / n;
    Serial.print("Waktu Konversi ADC (us): ");
    Serial.println(rata_rata);  
    delay(500);

}
