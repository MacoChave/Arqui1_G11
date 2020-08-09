// PINES
const int select = 8; // Selector
const int led_msg = 12; // LED MENSAJE
const int led_jgo = 13; // LED JUEGO

// CAMBIAR DE MODO
int mode = 0; //0: Mensaje | 1: Mensaje | 2: Juego | 3: Pausa
unsigned long tSignalBegin = 0;
unsigned long tSignalEnd = 0;
unsigned long tSignal = 0;

void setup() {
  Serial.begin(3600);
  
  pinMode(select, INPUT);
  pinMode(led_msg, OUTPUT);
  pinMode(led_jgo, OUTPUT);

  digitalWrite(led_msg, LOW);
  digitalWrite(led_jgo, LOW);
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
        digitalWrite(led_msg, HIGH);
        digitalWrite(led_jgo, LOW);   
    } else
    {
        // JUEGO
        digitalWrite(led_msg, LOW);
        digitalWrite(led_jgo, HIGH);
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
