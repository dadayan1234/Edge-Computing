#include <Wire.h>

void setup() {
  Wire.begin(9); // Inisialisasi I2C dengan alamat slave 9
  Wire.onReceive(receiveEvent); // Mengatur fungsi callback untuk menerima data
  Wire.onRequest(requestEvent); // Mengatur fungsi callback untuk membalas data
  Serial.begin(9600);
}

void receiveEvent() {
  while (Wire.available()) { // Loop selama ada data yang tersedia
    char c = Wire.read(); // Membaca karakter dari buffer I2C
    Serial.print(c); // Print karakter yang dibaca ke Serial Monitor
  }
}

void requestEvent() {
  Wire.write("Hello, Master!!"); // Mengirim balasan ke master
}

void loop() {
  // Loop kosong
}
