// PINES
const int select = 8; // Selector

// CAMBIAR DE MODO
int mode = 0; //0: Mensaje | 1: Mensaje | 2: Juego | 3: Pausa
unsigned long tSignalBegin = 0;
unsigned long tSignalEnd = 0;
unsigned long tSignal = 0;

void setup() {
  Serial.begin(3600);
  
  pinMode(select, INPUT);
}

void loop() {
    mode = modeEvent(digitalRead(select));

    if (mode == 0)
    {
        // PAUSA
    }
    else if (mode == 1) 
    {
        // MENSAJE
    } else
    {
        // JUEGO
    }
}

int modeEvent(int signal) {
    if (signal) {
        tSignalBegin = tSignalBegin == 0 ? millis() / 1000 : tSignalBegin;
    }
    else {
        if (tSignalBegin == 0) return mode;
        tSignalEnd = millis() / 1000;

        tSignal = tSignalEnd - tSignalBegin;
        
        tSignalBegin = 0;
        tSignalEnd = 0;
        return tSignal;
    }
}
