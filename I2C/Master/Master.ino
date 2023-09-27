#include <Wire.h>

void setup() {
  Wire.begin(); // Inisialisasi I2C
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(0x3F); // Alamat I2C ESP32
  Wire.write("Hello, World!"); // Mengirim pesan ke ESP32
  Wire.endTransmission(); // Selesai mengirim

  delay(500); // Delay untuk memberi waktu pada ESP32 untuk memproses

  // Membaca balasan dari ESP32
  Wire.requestFrom(0x3F, 13); // Minta 13 byte data dari ESP32
  while (Wire.available()) {
    char c = Wire.read(); // Membaca karakter dari buffer I2C
    Serial.print(c); // Print karakter yang dibaca ke Serial Monitor
  }
  
  delay(2000); // Delay sebelum mengulangi proses
}
ter