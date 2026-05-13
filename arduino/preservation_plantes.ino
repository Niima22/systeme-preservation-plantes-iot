// ===============================
// Déclaration des pins
// ===============================

// Capteurs analogiques
int tempPin = A0;
int humidityPin = A1;
int airPin = A2;

// LEDs et buzzer
int greenLed = 8;
int yellowLed = 9;
int redLed = 10;
int buzzer = 11;


// ===============================
// Initialisation
// ===============================
void setup() {
  Serial.begin(9600); // Démarrer le moniteur série

  // Configuration des sorties
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
}


// ===============================
// Boucle principale
// ===============================
void loop() {

  // Lecture et conversion de la température
  int tempValue = analogRead(tempPin);
  float voltage = tempValue * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100;

  // Lecture et conversion de l’humidité
  int humidity = map(analogRead(humidityPin), 0, 1023, 0, 100);

  // Lecture et conversion de la qualité de l’air
  int airQuality = map(analogRead(airPin), 0, 1023, 0, 100);


  // ===============================
  // Calcul du score de risque
  // ===============================
  int score = 0;

  if (temperature > 30) score += 1;
  if (temperature > 35) score += 2;

  if (humidity > 70) score += 1;
  if (humidity > 85) score += 2;

  if (airQuality > 60) score += 1;
  if (airQuality > 80) score += 2;


  // ===============================
  // Affichage dans Serial Monitor
  // ===============================
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.print(" % | Air Quality Risk: ");
  Serial.print(airQuality);
  Serial.print(" % | Score: ");
  Serial.println(score);


  // ===============================
  // Décision automatique
  // ===============================
  if (score <= 2) {
    // Conditions normales
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    noTone(buzzer);
    Serial.println("NORMAL: Conditions stables.");
  }
  else if (score <= 4) {
    // Conditions à surveiller
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
    noTone(buzzer);
    Serial.println("ATTENTION: Surveillance recommandee.");
  }
  else {
    // Conditions dangereuses
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    tone(buzzer, 1000);
    Serial.println("DANGER: Alerte environnementale !");
  }

  delay(2000); // Attendre 2 secondes
}
