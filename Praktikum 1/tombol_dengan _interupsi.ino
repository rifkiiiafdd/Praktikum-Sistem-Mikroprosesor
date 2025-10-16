volatile unsigned int hitung = 0;  // variabel harus volatile karena dipakai di ISR

void setup() {
  Serial.begin(9600);          
  pinMode(2, INPUT_PULLUP);   
  
  attachInterrupt(digitalPinToInterrupt(2), tombolDitekan, FALLING);
  
}

void loop() {
    
  Serial.print("Jumlah penekanan tombol: ");
  Serial.println(hitung);
  delay(500); 
}

void tombolDitekan() {
  hitung++; 
}
