#define trigPin 7
#define echoPin 6

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  
  // Kirimkan pulsa trigger selama 10 mikrodetik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Baca waktu pantulan
  duration = pulseIn(echoPin, HIGH);
  
  // Hitung jarak dalam sentimeter
  distance = (duration / 2) / 29.1;

  if (distance >= 2 && distance <= 100) {
    // Jarak valid, tampilkan hasil
    Serial.print("Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");
  } else {
    // Jarak di luar jangkauan sensor
    Serial.println("Jarak di luar jangkauan sensor.");
  }
  
  delay(1000); // Tunggu 1 detik sebelum pengukuran berikutnya
}