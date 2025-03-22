# LCD-Playground
[![CircleCI](https://circleci.com/gh/jaybi/RADOM-WL-thermometre.svg?style=svg)](https://circleci.com/gh/jaybi/LCD-Playground)

Ce projet utilise un écran LCD 16x2 connecté via un module I2C (PCF8574), un encodeur rotatif, un bouton poussoir et deux LEDs pour démontrer diverses fonctionnalités interactives avec une carte Arduino.

## Fonctionnalités

1. **Affichage sur l'écran LCD** :
   - Le texte "JB & PAUL" est affiché sur l'écran LCD.
   - Le texte peut être déplacé à gauche ou à droite en fonction de la rotation de l'encodeur rotatif.
   - Le texte rebondit sur les bords de l'écran comme une balle.

2. **Contrôle des LEDs avec des boutons** :
   - Une LED connectée à la broche 7 s'allume lorsque le bouton poussoir (connecté à la broche 6) est pressé et s'éteint lorsqu'il est relâché.
   - Une deuxième LED connectée à la broche 8 s'allume lorsque le bouton poussoir (connecté à la broche 5) est pressé et s'éteint lorsqu'il est relâché.

3. **Encodeur rotatif** :
   - L'encodeur rotatif est utilisé pour déplacer le texte sur l'écran LCD ou régler la vitesse de clignotement d'une LED.
   - Les broches CLK et DT de l'encodeur sont connectées respectivement aux broches 2 et 3 de l'Arduino.

## Matériel requis

- 1 x Arduino (Uno, Mega, ou compatible)
- 1 x Écran LCD 16x2 avec module I2C (PCF8574)
- 1 x Encodeur rotatif
- 2 x Boutons poussoirs
- 2 x LEDs
- 2 x Résistances 220Ω (pour les LEDs)
- Câbles de connexion

## Schéma de connexion

### Écran LCD (I2C)
| Broche LCD | Connexion Arduino |
|------------|-------------------|
| SDA        | A4 (Uno) ou 20 (Mega) |
| SCL        | A5 (Uno) ou 21 (Mega) |
| VCC        | 5V                |
| GND        | GND               |

### Encodeur rotatif
| Broche Encodeur | Connexion Arduino |
|-----------------|-------------------|
| CLK             | 2                 |
| DT              | 3                 |
| GND             | GND               |
| VCC             | 5V (si nécessaire) |

### Boutons poussoirs
| Broche Bouton | Connexion Arduino |
|---------------|-------------------|
| Bouton 1 - 1  | 6                 |
| Bouton 1 - 2  | GND               |
| Bouton 2 - 1  | 5                 |
| Bouton 2 - 2  | GND               |

### LEDs
| Broche LED | Connexion Arduino |
|------------|-------------------|
| LED 1 Anode (+)  | 7 (via une résistance de 220Ω) |
| LED 1 Cathode (-) | GND               |
| LED 2 Anode (+)  | 8 (via une résistance de 220Ω) |
| LED 2 Cathode (-) | GND               |

## Installation

1. **Cloner le projet** :
   ```bash
   git clone https://github.com/votre-utilisateur/LCD-Playground.git
   cd LCD-Playground
