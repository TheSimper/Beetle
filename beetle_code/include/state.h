#pragma once
#include <Arduino.h>
#include "tof.h"


#define GROUND_BORDER 500
#define DIST_BORDER 255

class state
{
    uint16_t distTab[4];    //indeks: 0 - PRAWY_BOK, 1 - PRAWY_PRZOD, 2 - LEWY_PRZOD, 3-LEWY_BOK
    bool groundTab[2];      //indeks: 0 - PRAWY, 1 -LEWY //bool: 1 = biala linia, 0 = brak bialej linii
    bool switchTab[2];  
    bool starterState;
public:
    
    

    state();
    ~state();
    
    void sensorsStateRead(tof tof_sensors);
    void readGround();  
    void readSwitch();
    bool readStarter();  
    void distSensorsTest();

    uint16_t GetD(int index){return distTab[index];};
    bool GetG(int index){return groundTab[index];};
    bool GetSW(int index){return groundTab[index];};
    bool GetST(int index){return starterState;};
};
