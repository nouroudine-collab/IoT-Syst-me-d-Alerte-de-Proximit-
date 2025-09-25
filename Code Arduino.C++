//Declaration des variable 
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 11;
const int buzzerPin = 12;
const int seuil = 100; // seuil sécurité en cm

 // Configuration des broches en entrée ou sortie
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

// Envoi d'une impulsion ultrasonique pour mesurer la distance
void loop() {
  // Envoi de l’impulsion
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Mesure du temps d’écho
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

// Vérification si la distance est inférieure ou égale au seuil de sécurité
  if (distance <= seuil) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(200); // Pause de 200 ms avant la prochaine
}