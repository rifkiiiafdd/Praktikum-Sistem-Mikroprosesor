// Nama    : Rifki Afriadi
// NIM     : 13223049
// Tanggal : 17/10/2025

int potPin = 34;   
int adcValue = 0;  
int resolusi = 12;

void setup() {
  Serial.begin(115200);       
  analogReadResolution(resolusi);  
  analogSetAttenuation(ADC_0db); 
//   analogSetAttenuation(ADC_11db); 

}

void loop() {
  adcValue = analogRead(potPin); 
  Serial.print("ADC Value: ");
  Serial.println(adcValue);      
  delay(500);                     
}
