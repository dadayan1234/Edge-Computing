// Definisikan pin LED
const int LED1 = 4;
const int LED2 = 2;
const int LED3 = 15;

// Variabel untuk menyimpan waktu terakhir setiap LED menyala
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

// Interval penyalakan LED
const long interval1 = 1000; // 1 detik
const long interval2 = 2000; // 2 detik
const long interval3 = 3000; // 3 detik

void setup() {
  // Atur pin-pin LED sebagai OUTPUT
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // Dapatkan waktu sekarang
  unsigned long currentMillis = millis();

  // Periksa apakah sudah waktunya untuk menyalakan LED 1
  if (currentMillis - previousMillis1 >= interval1) {
    // Simpan waktu terakhir LED 1 menyala
    previousMillis1 = currentMillis;
    // Nyalakan LED 1
    digitalWrite(LED1, HIGH);
  } else {
    // Matikan LED 1 jika belum waktunya
    digitalWrite(LED1, LOW);
  }

  // Lakukan hal yang sama untuk LED 2 dan LED 3
  if (currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }

  if (currentMillis - previousMillis3 >= interval3) {
    previousMillis3 = currentMillis;
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }
}