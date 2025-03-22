#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Broche du haut-parleur
const int speakerPin = A0;

// Broches de l'encodeur rotatif
const int pinCLK = 2; // Broche CLK de l'encodeur
const int pinDT = 3;  // Broche DT de l'encodeur

// Initialisation de l'écran LCD (adresse I2C 0x27 ou 0x38, 16 colonnes, 2 lignes)
LiquidCrystal_I2C lcd(0x38, 16, 2);

int lastStateCLK; // Dernier état de la broche CLK
int frequency = 440; // Fréquence initiale du son (La4)

void setup() {
  // Initialisation de l'écran LCD
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("Freq: ");
  lcd.setCursor(0, 1);
  lcd.print(frequency);
  lcd.print(" Hz");
  
  Serial.begin(9600);
  pinMode(pinCLK, INPUT);
  pinMode(pinDT, INPUT);

  // Lire l'état initial de la broche CLK
  lastStateCLK = digitalRead(pinCLK);
}

void loop() {
  // Lire l'état actuel de la broche CLK
  int currentStateCLK = digitalRead(pinCLK);

  // Si l'état de CLK a changé, l'encodeur a tourné
  if (currentStateCLK != lastStateCLK) {
    // Lire l'état de la broche DT pour déterminer la direction
    int currentStateDT = digitalRead(pinDT);

    Serial.print("CLK: ");
    Serial.print(currentStateCLK);
    Serial.print(" | DT: ");
    Serial.println(currentStateDT);

    if (currentStateCLK == LOW) {
      if (currentStateDT == HIGH) {
        // Rotation dans le sens horaire : augmenter la fréquence
        frequency += 10; // Augmenter la fréquence de 10 Hz
        if (frequency > 2000) frequency = 2000; // Limiter à 2000 Hz
      } else {
        // Rotation dans le sens antihoraire : diminuer la fréquence
        frequency -= 10; // Réduire la fréquence de 10 Hz
        if (frequency < 50) frequency = 50; // Limiter à 50 Hz
      }

      // Afficher la fréquence actuelle dans le moniteur série
      Serial.print("Frequency: ");
      Serial.println(frequency);

      // Mettre à jour l'écran LCD avec la nouvelle fréquence
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Freq: ");
      lcd.setCursor(0, 1);
      lcd.print(frequency);
      lcd.print(" Hz");
    }
  }

  // Mettre à jour l'état précédent de CLK
  lastStateCLK = currentStateCLK;

  // Générer un son avec la fréquence actuelle
  tone(speakerPin, frequency, 500); // Son de 500 ms
}