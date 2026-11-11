    #include <Arduino.h>
    #include <M5_Encoder.h>
    #include <MicroOscSlip.h>


    M5_Encoder monEncodeur;
    MicroOscSlip<128> monOsc(&Serial); 

    void setup() {
       
        Wire.begin();
        monEncodeur.begin();
        Serial.begin(115200);
        
    }
    void loop() {
        
        monEncodeur.update();
        
        if ( monEncodeur.wasPressed() ) {
            monOsc.sendInt("/enc/but", 1);
        }
        if ( monEncodeur.wasReleased() ) {
            monOsc.sendInt("/enc/but", 0);
        }
        
    }
