# LCD-Playground
[![CircleCI](https://circleci.com/gh/jaybi/RADOM-WL-thermometre.svg?style=svg)](https://circleci.com/gh/jaybi/LCD-Playground)

Ce projet utilise un écran LCD 16x2 connecté via un module I2C (PCF8574), un encodeur rotatif, un bouton poussoir et une LED pour démontrer diverses fonctionnalités interactives avec une carte Arduino.

## Fonctionnalités

1. **Affichage sur l'écran LCD** :
   - Le texte "JB & PAUL" est affiché sur l'écran LCD.
   - Le texte peut être déplacé à gauche ou à droite en fonction de la rotation de l'encodeur rotatif.
   - Le texte rebondit sur les bords de l'écran comme une balle.

2. **Contrôle de la LED avec un bouton** :
   - Une LED connectée à la broche 7 s'allume lorsque le bouton poussoir (connecté à la broche 6) est pressé et s'éteint lorsqu'il est relâché.

3. **Encodeur rotatif** :
   - L'encodeur rotatif est utilisé pour déplacer le texte sur l'écran LCD.
   - Les broches CLK et DT de l'encodeur sont connectées respectivement aux broches 2 et 3 de l'Arduino.

## Matériel requis

- 1 x Arduino (Uno, Mega, ou compatible)
- 1 x Écran LCD 16x2 avec module I2C (PCF8574)
- 1 x Encodeur rotatif
- 1 x Bouton poussoir
- 1 x LED
- 1 x Résistance 220Ω (pour la LED)
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

### Bouton poussoir
| Broche Bouton | Connexion Arduino |
|---------------|-------------------|
| 1             | 6                 |
| 2             | GND               |

### LED
| Broche LED | Connexion Arduino |
|------------|-------------------|
| Anode (+)  | 7 (via une résistance de 220Ω) |
| Cathode (-) | GND               |

## Installation

1. **Cloner le projet** :
   ```bash
   git clone https://github.com/votre-utilisateur/LCD-Playground.git
   cd LCD-Playground
