#include <Arduino.h>

#include <M5_Encoder.h>
M5_Encoder monEncodeur; // instance du encoder

#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

void setup()
{
    Serial.begin(115200);
    Wire.begin();        // Active mon I2C qui est le connecteur blanc grove
    monEncodeur.begin(); // Démarre l'encodeur
}

void loop()
{
    monEncodeur.update();                                    // Mise à jour des valeurs de l’encodeur.
    int changementEncodeur = monEncodeur.getEncoderChange(); // Lecture du changement depuis la dernière lecture

    if (changementEncodeur != 0) // Si la valeur de l'encodeur n'est pas égale à 0
    {
        monOsc.sendInt("/enc/rot", changementEncodeur);
    }

    if (monEncodeur.wasPressed()) // Si le bouton a été appuyé
    {
        monOsc.sendInt("/enc/but", 1);
    }

    if (monEncodeur.wasReleased()) // Si le bouton a été relâché
    {
        monOsc.sendInt("/enc/but", 0);
    }
}
