#define echoPinFront 3  // Ön ultrasonik sensörün echo pini
#define trigPinFront 2  // Ön ultrasonik sensörün trig pini
#define echoPinRight 10  // Sağ ultrasonik sensörün echo pini
#define trigPinRight 9  // Sağ ultrasonik sensörün trig pini
#define echoPinLeft 12    // Sol ultrasonik sensörün echo pini
#define trigPinLeft 11    // Sol ultrasonik sensörün trig pini

#define MotorR1 5   // Sağ motor kontrol pinleri
#define MotorR2 6
#define MotorRE 4
#define MotorL1 7   // Sol motor kontrol pinleri
#define MotorL2 8
#define MotorLE 13
#define LDR_PIN A0   // Işık sensörü pini

long sureFront, uzaklikFront;  // Ön sensör mesafe ve süre değişkenleri
long sureRight, uzaklikRight;  // Sağ sensör mesafe ve süre değişkenleri
long sureLeft, uzaklikLeft;    // Sol sensör mesafe ve süre değişkenleri
int isik_siddeti;              // Işık sensörü değeri

void setup() {
  pinMode(echoPinFront, INPUT);  // Ön echo pini giriş olarak ayarlanır
  pinMode(trigPinFront, OUTPUT); // Ön trig pini çıkış olarak ayarlanır
  pinMode(echoPinRight, INPUT);  // Sağ echo pini giriş olarak ayarlanır
  pinMode(trigPinRight, OUTPUT); // Sağ trig pini çıkış olarak ayarlanır
  pinMode(echoPinLeft, INPUT);   // Sol echo pini giriş olarak ayarlanır
  pinMode(trigPinLeft, OUTPUT);  // Sol trig pini çıkış olarak ayarlanır

  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE, OUTPUT);
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Mesafe ölçümleri
  uzaklikFront = measureDistance(trigPinFront, echoPinFront);
  uzaklikRight = measureDistance(trigPinRight, echoPinRight);
  uzaklikLeft = measureDistance(trigPinLeft, echoPinLeft);

  // Işık şiddeti ölçümü
  isik_siddeti = analogRead(LDR_PIN);

  // Hareket kontrolü
  if (uzaklikFront > 10 && uzaklikRight > 10 && uzaklikLeft > 10) {  // Düz ilerleme
    ileri();
  } else if (uzaklikFront < 10) {  // Engel algılama
    geri();
    delay(500);

    if (uzaklikRight > 10) {  // Sağa dönüş
      sag();
      delay(500);
    } else if (uzaklikLeft > 10) {  // Sola dönüş
      sola();
      delay(500);
    } else {
      stopCar();  // Hareket edemeyecek durumda durdur
    }
  }

  // Tünelden geçiş
  if (uzaklikFront < 20 && isik_siddeti < 50) {  // 1. tünel (karanlık)
    stopCar();
    delay(5000);
  }

  // Yarışın bitişi
  if (uzaklikFront < 10 && uzaklikRight < 10 && uzaklikLeft < 10) {
    // Yarış tamamlandı
    Serial.println("Yarış tamamlandı!");
    stopCar();
    //while (1);
  }

  delay(100);
}

long measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) / 29.1 / 2;
}

void ileri() {
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  analogWrite(MotorRE, 150);
  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  analogWrite(MotorLE, 150);
}

void sag() {
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  analogWrite(MotorRE, 150);
  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  analogWrite(MotorLE, 150);
}

void sola() {
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  analogWrite(MotorRE, 150);
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  analogWrite(MotorLE, 150);
}

void geri() {
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  analogWrite(MotorRE, 150);
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  analogWrite(MotorLE, 150);
}

void stopCar() {
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  analogWrite(MotorRE, 0);
  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  analogWrite(MotorLE, 0);
}
