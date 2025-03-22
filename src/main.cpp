#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal_I2C lcd(0x38, 16, 2);

// Pins de l'encodeur rotatif
const int pinCLK = 2; // Broche CLK de l'encodeur
const int pinDT = 3;  // Broche DT de l'encodeur

// Pins pour le bouton et la LED
const int pinButton = 6; // Broche du bouton
const int pinLED = 7;    // Broche de la LED

int lastStateCLK; // Dernier état de la broche CLK
int position = 0; // Position actuelle du texte

void setup() {
  Serial.begin(9600);

  // Initialisation de l'écran LCD
  lcd.init();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("JB & PAUL");

  // Initialisation des broches de l'encodeur
  pinMode(pinCLK, INPUT);
  pinMode(pinDT, INPUT);

  // Initialisation des broches pour le bouton et la LED
  pinMode(pinButton, INPUT_PULLUP); // Bouton avec résistance pull-up interne
  pinMode(pinLED, OUTPUT);          // LED en sortie

  // Lire l'état initial de la broche CLK
  lastStateCLK = digitalRead(pinCLK);
}

void loop() {
  // Gestion du bouton et de la LED
  int buttonState = digitalRead(pinButton); // Lire l'état du bouton
  if (buttonState == HIGH) { // Bouton pressé (LOW car pull-up actif)
    digitalWrite(pinLED, HIGH); // Allumer la LED
  } else {
    digitalWrite(pinLED, LOW); // Éteindre la LED
  }

  // Lire l'état actuel de la broche CLK
  int currentStateCLK = digitalRead(pinCLK);

  // Si l'état de CLK a changé, l'encodeur a tourné
  if (currentStateCLK != lastStateCLK) {
    // Lire l'état de la broche DT pour déterminer la direction
    int currentStateDT = digitalRead(pinDT);

    if (currentStateCLK == LOW) {
      if (currentStateDT == HIGH) {
        // Rotation dans le sens horaire (droite)
        position++;
      } else {
        // Rotation dans le sens antihoraire (gauche)
        position--;
      }

      // Limiter la position pour qu'elle reste dans les limites de l'écran
      if (position < 0) {
        position = 0;
      } else if (position > 16 - 4) { // 16 colonnes - longueur du texte
        position = 16 - 4;
      }

      // Effacer l'écran et afficher le texte à la nouvelle position
      lcd.clear();
      lcd.setCursor(position, 0);
      lcd.print("PAUL");

      // Afficher la position dans le moniteur série (optionnel)
      Serial.println(position);
    }
  }

  // Mettre à jour l'état précédent de CLK
  lastStateCLK = currentStateCLK;
}

