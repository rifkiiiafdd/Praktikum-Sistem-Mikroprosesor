/**
 * Metode Pengukuran Kecepatan ADC yang Akurat
 * Memisahkan proses pengukuran dari proses pelaporan.
 */

const int ADC_PIN = 34;
const int NUM_SAMPLES = 10000; // Ukur 10.000 sampel untuk hasil stabil
volatile int adc_result;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Atur resolusi ADC (9 atau 12 bit)
  analogSetWidth(9); 
  // analogSetWidth(12);

  Serial.println("Memulai pengukuran...");

  // 1. CATAT WAKTU MULAI
  unsigned long startTime = micros();

  // 2. LAKUKAN PENGUKURAN SECARA BERUNTUN TANPA GANGGUAN
  for (int i = 0; i < NUM_SAMPLES; i++) {
    adc_result = analogRead(ADC_PIN);
  }

  // 3. CATAT WAKTU SELESAI
  unsigned long endTime = micros();

  // 4. HITUNG DAN CETAK HASIL (HANYA SATU KALI)
  unsigned long totalTime = endTime - startTime;
  float timePerSample = (float)totalTime / NUM_SAMPLES;
  float samplesPerSecond = 1000000.0f / timePerSample;

  Serial.println("-------------------------------------------");
  Serial.print("Waktu Rata-rata per Sampel: ");
  Serial.print(timePerSample, 2);
  Serial.println(" us (mikrodetik)");
  Serial.print("Kecepatan Konversi: ");
  Serial.print(samplesPerSecond, 0);
  Serial.println(" SPS (Sampel per Detik)");
  Serial.println("-------------------------------------------");
}

void loop() {
  // Biarkan kosong agar pengukuran tidak diulang.
}