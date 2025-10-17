#include "driver/dac.h"

// Pilih mode uji DAC di bawah ini:
// #define MODE_DACWRITE              
#define MODE_DACVOLT_OUTPUT      

const int pinOutputDAC = 25;                 
const dac_channel_t kanalDAC = DAC_CHANNEL_1;

void setup() {
  Serial.begin(115200);
  delay(1000);

#ifdef MODE_DACWRITE
  Serial.println("Mode Uji: Menggunakan fungsi dacWrite()");
#elif defined(MODE_DACVOLT_OUTPUT)
  Serial.println("Mode Uji: Menggunakan fungsi dac_output_voltage()");
  dac_output_enable(kanalDAC);
#endif
}

void loop() {
#ifdef MODE_DACWRITE
  dacWrite(pinOutputDAC, 0);    
  dacWrite(pinOutputDAC, 255);  

#elif defined(MODE_DACVOLT_OUTPUT)
  dac_output_voltage(kanalDAC, 0);    
  dac_output_voltage(kanalDAC, 255);  
#endif
}
