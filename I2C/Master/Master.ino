#include <Wire.h>

void setup() {
  Wire.begin(); // Inisialisasi I2C
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(9); // Alamat slave adalah 9
  Wire.write("Hello, World!"); // Mengirim pesan ke slave
  Wire.endTransmission(); // Selesai mengirim

  delay(500); // Delay untuk memberi waktu pada slave untuk memproses

  // Membaca balasan dari slave
  Wire.requestFrom(9, 13); // Minta 13 byte data dari slave
  while (Wire.available()) {
    char c = Wire.read(); // Membaca karakter dari buffer I2C
    Serial.print(c); // Print karakter yang dibaca ke Serial Monitor
  }
  
  delay(2000); // Delay sebelum mengulangi proses
}
