// Nama    : Rifki Afriadi
// NIM     : 13223049
// Tanggal : 17/10/2025
// Mengukur Fungsi Transfer DAC pada ESP32 

int dacPin = 25;  // gunakan DAC1 (GPIO25)

void setup() {
  Serial.begin(115200);
  Serial.println("=== Mengukur Fungsi Transfer DAC pada ESP32  ===");
}

void loop() {           
  for (int val = 0; val <= 255; val += 25) { // naik bertahap
    dacWrite(dacPin, val);  // tulis nilai ke DAC
    Serial.print("DAC Value: ");
    Serial.print(val);
    Serial.println();
    delay(5000);
  }
}
