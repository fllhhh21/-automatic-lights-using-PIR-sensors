// Lampu Otomatis dengan Sensor PIR dan Relay

const int pirPin = 4;
const int relayPin = 12;

unsigned long waktuTerakhirGerakan = 0;
const unsigned long jedaMati = 10000; // 10 detik

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, LOW); // Relay OFF (ubah ke HIGH jika relay Active LOW)

  Serial.begin(9600);
}

void loop() {
  int gerakan = digitalRead(pirPin);

  if (gerakan == HIGH) {
    waktuTerakhirGerakan = millis(); // Simpan waktu gerakan terakhir
    digitalWrite(relayPin, HIGH);    // Relay ON
    Serial.println("Gerakan Terdeteksi - Lampu ON");
  }

  // Lampu tetap menyala selama jedaMati
  if (millis() - waktuTerakhirGerakan < jedaMati) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
    Serial.println("Gerakan Tidak Terdeteksi - Lampu OFF");
  }

  delay(500);
}