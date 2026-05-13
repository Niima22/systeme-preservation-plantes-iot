# 🌿 Système Intelligent de Préservation des Plantes basé sur l’IoT

Ce projet est un système IoT simulé permettant de surveiller les conditions environnementales des plantes.

## 🎯 Objectifs

- Mesurer la température ambiante
- Mesurer le taux d’humidité
- Surveiller la qualité de l’air
- Générer des alertes automatiques
- Visualiser les données sur ThingSpeak
- Afficher les informations dans une interface web

## 🧰 Technologies utilisées

- Tinkercad
- Arduino Uno
- ThingSpeak
- HTML / CSS / JavaScript
- API HTTP

## 🧩 Architecture

Capteurs → Arduino → ThingSpeak → Dashboard Web

## 📸 Captures

### Circuit Tinkercad
<img width="1631" height="868" alt="image" src="https://github.com/user-attachments/assets/2f53adfc-108d-4864-9a4b-fea15c8fc512" />

### ThingSpeak
<img width="1095" height="766" alt="image" src="https://github.com/user-attachments/assets/347c97b4-7568-4532-9836-751279a9959e" />

### Interface Web
<img width="1919" height="966" alt="image" src="https://github.com/user-attachments/assets/9addfeae-efd4-456e-94b5-0754221ba318" />

## 🚀 Fonctionnement

Arduino lit les données des capteurs, calcule un score de risque, puis active les LEDs et le buzzer selon l’état détecté.

L’interface web récupère les dernières données depuis ThingSpeak et affiche l’état des plantes en temps réel.
