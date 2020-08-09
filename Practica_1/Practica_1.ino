#include <LedControl.h>

/* PINES */
// FILAS MATRIZ SIN DRIVER
const byte row[8] = {22, 24, 26, 28, 30, 32, 34, 36};
// COLUMNAS MATRIZ SIN DRIVER
const byte column[8] = {38, 40, 42, 44, 46, 48, 50, 52};

// MATRIZ CON DRIVER 
// LedControl(DATA, CLK, CS, NoDEVICE)
LedControl matrix = LedControl(2, 3, 4, 1);

// BOTONES DE MENSAJE 
const byte toggle = 10;
const byte minSpeed = 11;
const byte maxSpeed = 12;

// BOTONES DE JUEGO 
const byte start = 5;
const byte upA = 6;
const byte downA = 7;
const byte upB = 8;
const byte downB = 9;

/* 
 *  1  2  3  4  5  6  7  8  9 10 11 13 14 15 16 17 18 19 20 21 22 24
 *  T  P  1  -  G  R  U  P  O     1 -  S  E  C  C  I  O  N     A 
 *  A C E G I N O P R S T U 
 *  0 1 2 3 4 5 6 7 8 9
 *  - */

const int letra_A[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 1, 1, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_C[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 1, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_E[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 0, 0}, 
                                {0, 1, 1, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 1, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_G[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 0, 1, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 0, 1, 1, 1, 1, 1, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_I[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 1, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 1, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_N[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 1, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 1, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_O[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_P[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 0, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 1, 1, 1, 0, 0}, 
                                {0, 1, 1, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_R[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 0, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 1, 1, 1, 0, 0}, 
                                {0, 1, 1, 1, 0, 0, 0, 0}, 
                                {0, 1, 1, 0, 1, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_S[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 1, 1, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_T[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 1, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_U[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 1, 1, 0, 0, 1, 1, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int num_0[8][8]   =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 1, 0, 0, 1, 0, 0}, 
                                {0, 0, 1, 0, 0, 1, 0, 0}, 
                                {0, 0, 1, 0, 0, 1, 0, 0}, 
                                {0, 0, 1, 0, 0, 1, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int num_1[8][8]   =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 1, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 1, 0, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 1, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int num_2[8][8]   =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 1, 0, 0}, 
                                {0, 0, 0, 0, 1, 1, 0, 0}, 
                                {0, 0, 1, 1, 0, 0, 0, 0}, 
                                {0, 0, 1, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int num_3[8][8]   =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 1, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 1, 0, 0}, 
                                {0, 0, 1, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int num_4[8][8]   =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 0, 0, 1, 0, 0}, 
                                {0, 0, 1, 0, 0, 1, 0, 0}, 
                                {0, 0, 1, 0, 0, 1, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int num_5[8][8]   =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 0, 1, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 1, 0, 0}, 
                                {0, 0, 1, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int num_6[8][8]   =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 1, 0, 0}, 
                                {0, 0, 1, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 0, 0, 0}, 
                                {0, 0, 1, 0, 0, 1, 0, 0}, 
                                {0, 0, 1, 0, 0, 1, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int num_7[8][8]   =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 1, 0, 0}, 
                                {0, 0, 0, 0, 1, 0, 0, 0}, 
                                {0, 0, 0, 1, 0, 0, 0, 0}, 
                                {0, 0, 1, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int num_8[8][8]   =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 1, 0, 0, 1, 0, 0}, 
                                {0, 0, 1, 0, 1, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 1, 0, 0}, 
                                {0, 0, 1, 0, 0, 1, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int num_9[8][8]   =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 1, 0, 0, 1, 0, 0}, 
                                {0, 0, 1, 0, 0, 1, 0, 0}, 
                                {0, 0, 0, 1, 1, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 1, 0, 0}, 
                                {0, 0, 1, 1, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int guion[8][8]   =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 1, 0}, 
                                {0, 1, 1, 1, 1, 1, 1, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int espacio[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

int orientation = 0; // 0:IZQUIERDA | 1: DERECHA 
int msgSpeed = 100; // VELOCIDAD DE MENSAJE
int leftPixel = 0; // AREA A EXTRAER
int currentLetter = 0; // LETRA ACTUAL

void setup() {
    Serial.begin(3600);

    // INICIALIZAR PINES DE MATRIZ COMO SALIDA
    for (int i = 0; i < 8; i++) {
        pinMode(row[i], OUTPUT);
        pinMode(column[i], OUTPUT);

        // HIGH (CATODO) | LOW (ANODO)
        digitalWrite(row[i], LOW);
        digitalWrite(column[i], HIGH);
    }

    matrix.shutdown(0, false);
    matrix.setIntensity(0, 8);
    matrix.clearDisplay(0);

    // BOTONES DE MENSAJE 
    pinMode(toggle, INPUT);
    pinMode(minSpeed, INPUT);
    pinMode(maxSpeed, INPUT);

    // BOTONES DE JUEGO 
    pinMode(start, INPUT);
    pinMode(upA, INPUT);
    pinMode(downA, INPUT);
    pinMode(upB, INPUT);
    pinMode(downB, INPUT);

    pinMode(5, INPUT); // TOGGLE
    pinMode(6, INPUT); // TOGGLE
    pinMode(A0, INPUT); // SPEED

    pinMode(7, INPUT); // PAUSE
    pinMode(8, INPUT); // RIGHT
    pinMode(9, INPUT); // LEFT
}

void loop() {
    if (digitalRead(minSpeed) == HIGH) increaseSpeed();
    if (digitalRead(maxSpeed) == HIGH) decreaseSpeed();
    delay(2);

    if (digitalRead(toggle) == HIGH) toggleMsgOrientation();
    
    mensaje();
}

/*
 * CONFIGURACIONES RECIBIDAS
 */
void increaseSpeed() {
    if (msgSpeed > 20) msgSpeed -= 20;
}

void decreaseSpeed() {
    if (msgSpeed <= 200) msgSpeed += 20;
}

void toggleMsgOrientation() {
    orientation = !orientation;
}

void clearMatrix() {
  for (int i = 0; i < 8; i++) {
      digitalWrite(row[i], LOW);
      digitalWrite(column[i], HIGH);
  }
}

/*
 * MOSTRAR CARACTER EN DISPLAY's
 */
void caracter_aMano(int caracter[][8]) {
  for (int x = 0; x < msgSpeed; x++) {
      for (int i = 0; i < 8; i++) {
          digitalWrite(row[i], HIGH);
          for (int j = 0; j < 8; j++) {
              if (caracter[j][i] == 1) {
                  digitalWrite(column[j], LOW); 
              }
          }
          delay(2);
          digitalWrite(row[i], LOW);
          for (int j = 0; j < 8; j++) {
              digitalWrite(column[j], HIGH);
          }
      }
  }
}

void caracter_conDriver(int caracter[][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (caracter[i][j] == 1) {
                // TODO: matrix.setLed(number, row, column, state);
                matrix.setLed(0, i, j, HIGH);
            }
        }
        delay(2);
    }
}
/*
 * IMPRIMIR MENSAJE
 * G17-SECCION A-PRACTICA 1
 */
void mensaje() {
    int caracter[8][8]          = {
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}
                                };

    int caracter_driver[8][8]   = {
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}
                                };

    for (int i = 0; i < 8; i++) {
        int nextColNum = 8 - leftPixel;
        for (int j = 0, colNum = leftPixel; j < 8; j++, colNum++) {
            switch (currentLetter) {
                case 0: // LETRA T
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_T[i][colNum];
                        caracter_driver[i][j] = letra_P[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_P[i][colNum - 1];
                        caracter_driver[i][nextColNum] = num_1[i][colNum - 1];
                    }
                    break;
                }
                case 1: // LETRA P
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_P[i][colNum];
                        caracter_driver[i][j] = num_1[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = num_1[i][colNum - 1];
                        caracter_driver[i][nextColNum] = guion[i][colNum - 1];
                    }
                    break;
                }
                case 2: // NUMERO 1
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = num_1[i][colNum];
                        caracter_driver[i][j] = guion[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = guion[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_G[i][colNum - 1];
                    }
                    break;
                }
                case 3: // GUION
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = guion[i][colNum];
                        caracter_driver[i][j] = letra_G[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_G[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_R[i][colNum - 1];
                    }
                    break;
                }
                case 4: // LETRA G
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_G[i][colNum];
                        caracter_driver[i][j] = letra_R[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_R[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_U[i][colNum - 1];
                    }
                    break;
                }
                case 5: // LETRA R
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_R[i][colNum];
                        caracter_driver[i][j] = letra_U[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_U[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_P[i][colNum - 1];
                    }
                    break;
                }
                case 6: // LETRA U
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_U[i][colNum];
                        caracter_driver[i][j] = letra_P[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_P[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_O[i][colNum - 1];
                    }
                    break;
                }
                case 7: // LETRA P
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_P[i][colNum];
                        caracter_driver[i][j] = letra_O[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_O[i][colNum - 1];
                        caracter_driver[i][nextColNum] = espacio[i][colNum - 1];
                    }
                    break;
                }
                case 8: // LETRA O
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_O[i][colNum];
                        caracter_driver[i][j] = espacio[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = espacio[i][colNum - 1];
                        caracter_driver[i][nextColNum] = num_1[i][colNum - 1];
                    }
                    break;
                }
                case 9: // ESPACIO
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = espacio[i][colNum];
                        caracter_driver[i][j] = num_1[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = num_1[i][colNum - 1];
                        caracter_driver[i][nextColNum] = guion[i][colNum - 1];
                    }
                    break;
                }
                case 10: // NUMERO 1
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = num_1[i][colNum];
                        caracter_driver[i][j] = guion[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = guion[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_S[i][colNum - 1];
                    }
                    break;
                }
                case 11: // GUION
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = guion[i][colNum];
                        caracter_driver[i][j] = letra_S[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_S[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_E[i][colNum - 1];
                    }
                    break;
                }
                case 12: // LETRA S
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_S[i][colNum];
                        caracter_driver[i][j] = letra_E[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_E[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_C[i][colNum - 1];
                    }
                    break;
                }
                case 13: // LETRA E
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_E[i][colNum];
                        caracter_driver[i][j] = letra_C[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_C[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_C[i][colNum - 1];
                    }
                    break;
                }
                case 14: // LETRA C
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_C[i][colNum];
                        caracter_driver[i][j] = letra_C[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_C[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_I[i][colNum - 1];
                    }
                    break;
                }
                case 15: // LETRA C
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_C[i][colNum];
                        caracter_driver[i][j] = letra_I[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_I[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_O[i][colNum - 1];
                    }
                    break;
                }
                case 16: // LETRA I
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_I[i][colNum];
                        caracter_driver[i][j] = letra_O[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_O[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_N[i][colNum - 1];
                    }
                    break;
                }
                case 17: // LETRA O
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_O[i][colNum];
                        caracter_driver[i][j] = letra_N[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_N[i][colNum - 1];
                        caracter_driver[i][nextColNum] = espacio[i][colNum - 1];
                    }
                    break;
                }
                case 18: // LETRA N
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_N[i][colNum];
                        caracter_driver[i][j] = espacio[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = espacio[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_A[i][colNum - 1];
                    }
                    break;
                }
                case 19: // ESPACIO
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = espacio[i][colNum];
                        caracter_driver[i][j] = letra_A[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_A[i][colNum - 1];
                        caracter_driver[i][nextColNum] = espacio[i][colNum - 1];
                    }
                    break;
                }
                case 20: // LETRA A
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = letra_A[i][colNum];
                        caracter_driver[i][j] = espacio[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = espacio[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_T[i][colNum - 1];
                    }
                    break;
                }
                case 21: // ESPACIO 
                {
                    if (colNum < 8) {
                        // LETRA ACTUAL
                        caracter[i][j] = espacio[i][colNum];
                        caracter_driver[i][j] = letra_T[i][colNum];
                    }

                    if (colNum > 0 && nextColNum < 8) {
                        caracter[i][nextColNum] = letra_T[i][colNum - 1];
                        caracter_driver[i][nextColNum] = letra_P[i][colNum - 1];
                    }
                    break;
                }
            }
            nextColNum++;
        }
    }

    matrix.clearDisplay(0);
    clearMatrix();
    caracter_conDriver(caracter_driver);
    caracter_aMano(caracter);
    
    if (orientation == 0) {
        // DERECHA 
        leftPixel++;
        if (leftPixel > 7) {
            leftPixel = 0;
            if (currentLetter == 21) currentLetter = 0;
            else currentLetter ++;
        }
    }
    else {
        // IZQUIERDA 
        leftPixel--;
        if (leftPixel < 0) {
            leftPixel = 7;
            if (currentLetter == 0) currentLetter = 21;
            else currentLetter--;
        }
    }
}
