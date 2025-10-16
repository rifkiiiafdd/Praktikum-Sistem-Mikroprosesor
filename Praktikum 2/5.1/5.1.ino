// Nama    : Rifki Afriadi
// NIM     : 13223049
// Tanggal : 17/10/2025
// Fungsi transfer ADC pada ESP32

int pinADC1 = 34;   //adc 1
int pinADC2 = 27;   //adc 2
int adcValue = 0;  
int resolusi = 12;

void setup() {
  Serial.begin(115200);       
  analogReadResolution(resolusi);  
  analogSetAttenuation(ADC_0db); 
//   analogSetAttenuation(ADC_11db); 

}

void loop() {
  adcValue = analogRead(pinADC1); 
  Serial.print("ADC Value: ");
  Serial.println(adcValue);      
  delay(500);                     
}
