const int trigPin = 9; // Pin Trigger sensor ultrasonik
const int echoPin = 10; // Pin Echo sensor ultrasonik

void setup() {
  Serial.begin(9600); // Inisialisasi komunikasi serial
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Mengirimkan pulsa ultrasonik
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Menerima waktu pantulan ultrasonik
  long duration = pulseIn(echoPin, HIGH);
  
  // Menghitung jarak dalam cm
  int distance = duration * 0.034 / 2;
  
  // Mengirimkan data jarak ke Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(1000); // Menunda pembacaan berikutnya untuk menghindari ledakan data
}
