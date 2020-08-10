#include <LedControl.h>

// VECTOR PARA LAS FILAS CON SU NUMERO DE PIN
const byte row[8] = {22, 24, 26, 28, 30, 32, 34, 36};
// VECTOR PARA LAS COLUMNAS CON SU NUMERO DE PIN
const byte column[8] = {38, 40, 42, 44, 46, 48, 50, 52};

// LedControl(DATA, CLK, CS, NoDEVICE)
LedControl matrix = LedControl(2, 3, 4, 1);

// MODIFICAR MENSAJE
const byte orientation = 10;
const byte minSpeed = 11;
const byte maxSpeed = 12;

// BOTON CENTRAL
const byte start = 5;

// CONTROL IZQUIERDO
// const byte upA;
// const byte downA;

// CONTROL DERECHO
// const byte upB;
// const byte downB;

/* 
 *  1  2  3  4  5  6  7  8  9 10 11 13 14 15 16 17 18 19 20 21 22 24
 *  G  1  7  -  S  E  C  C  I  O  N  A  -  P  R  A  C  T  I  C  A  1 
 *  T  P  1  -  G  R  U  P  O  1  1  -  S  E  C  C  I  O  N  A
*/
const int letra_A[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 1, 1, 1, 1, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_U[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 1, 1, 1, 1, 1, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_C[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 1, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_E[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 1, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_G[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 0, 0, 1, 1, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
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
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 1, 0, 0, 0, 1, 0}, 
                                {0, 1, 0, 1, 0, 0, 1, 0}, 
                                {0, 1, 0, 0, 1, 0, 1, 0}, 
                                {0, 1, 0, 0, 0, 1, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_O[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_P[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 0, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 1, 1, 1, 1, 0, 0}, 
                                {0, 1, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int letra_R[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 1, 1, 1, 1, 0, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 1, 1, 1, 1, 0, 0}, 
                                {0, 1, 0, 1, 0, 0, 0, 0}, 
                                {0, 1, 0, 0, 1, 1, 0, 0}, 
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

const int letra_S[8][8] =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 1, 0}, 
                                {0, 1, 0, 0, 0, 0, 0, 0}, 
                                {0, 1, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 1, 1, 1, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 1, 0}, 
                                {0, 1, 1, 1, 1, 1, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0}
                            };

const int num_1[8][8]   =   {
                                {0, 0, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 1, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 0, 0, 0}, 
                                {0, 0, 1, 0, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 1, 0, 0, 0}, 
                                {0, 0, 0, 0, 1, 0, 0, 0}, 
                                {0, 0, 0, 1, 1, 1, 0, 0}, 
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

int modo = 1; // 0: PAUSA | 1: MENSAJE | 2: JUEGO 
int direccion = 0; // 0:HACIA ARRIBA | 1: HACIA ABAJO
int speedIntro = 50; // VELOCIDAD DE MENSAJE
int top = 0; // AREA A EXTRAER
int letra = 0; // LETRA ACTUAL

void setup() {
    Serial.begin(3600);

    // INICIALIZAR MATRIZ SIN DRIVER 
    for (int i = 0; i < 8; i++) {
        pinMode(row[i], OUTPUT);
        pinMode(column[i], OUTPUT);

        // HIGH (CATODO) | LOW (ANODO)
        digitalWrite(row[i], LOW);
        digitalWrite(column[i], HIGH);
    }

    // INIICALIZAR MATRIZ CON DRIVER 
    matrix.shutdown(0, false);
    matrix.setIntensity(0, 8);
    matrix.clearDisplay(0);

    // INICIALIZAR CONTROL DE MENSAJE 
    pinMode(orientation, INPUT);
    pinMode(minSpeed, INPUT);
    pinMode(maxSpeed, INPUT);

    // INICIALIZAR CONTROL JUEGO
    pinMode(start, INPUT);
}

void loop() {
    if (digitalRead(minSpeed) == HIGH) increaseSpeed();
    if (digitalRead(maxSpeed) == HIGH) decreaseSpeed();
    if (digitalRead(orientation) == HIGH) toggleOrientation();

    if (modo == 0) {
        // pausa();
    } else if (modo == 1) {
      mensaje();
    } else {
    //   juego();
    }
}

void increaseSpeed() {
    speedIntro = speedIntro > 20 ? speedIntro -= 10 : speedIntro;
}

void decreaseSpeed() {
    speedIntro = speedIntro < 190 ? speedIntro += 10 : speedIntro;
}

void toggleOrientation() {
    direccion = !direccion;
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
  for (int x = 0; x < speedIntro; x++) {
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
    int caracter_driver[8][8]          = {
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}
                                };

    int caracter[8][8]   = {
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}, 
                                    {0, 0, 0, 0, 0, 0, 0, 0}
                                };


    int row_aux = 0; // CONTADOR DE FILA DE SIGUIENTE LETRA
    
    for (int i = 0, row = top; i < 8; i++, row++) {
        for (int j = 0; j < 8; j++) {
                     switch (letra) {
                case 0: // LETRA T
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_T[j][row];
                        caracter[j][i] = letra_P[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_P[j][row_aux];
                        caracter[j][i] = num_1[j][row_aux];
                    }
                    break;
                }
                case 1: // LETRA P
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_P[j][row];
                        caracter[j][i] = num_1[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = num_1[j][row_aux];;
                        caracter[j][i] = guion[j][row_aux];
                    }
                    break;
                }
                case 2: // LETRA 1
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = num_1[j][row];
                        caracter[j][i] = guion[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = guion[j][row_aux];
                        caracter[j][i] = letra_G[j][row_aux];
                    }
                    break;
                }
                case 3: // -
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = guion[j][row];
                        caracter[j][i] = letra_G[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_G[j][row];
                        caracter[j][i] = letra_R[j][row];
                    }
                    break;
                }
                case 4: // LETRA G
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_G[j][row];
                        caracter[j][i] = letra_R[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_R[j][row_aux];
                        caracter[j][i] = letra_U[j][row_aux];
                    }
                    break;
                }
                case 5: // LETRA R
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_R[j][row];
                        caracter[j][i] = letra_U[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_U[j][row_aux];
                        caracter[j][i] = letra_P[j][row_aux];
                    }
                    break;
                }
                case 6: // LETRA U
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_U[j][row];
                        caracter[j][i] = letra_P[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_P[j][row_aux];
                        caracter[j][i] = letra_O[j][row_aux];
                    }
                    break;
                }
                case 7: // LETRA P
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_P[j][row];
                        caracter[j][i] = letra_O[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_O[j][row_aux];
                        caracter[j][i] = num_1[j][row_aux];
                    }
                    break;
                }
                case 8: // LETRA 0
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_O[j][row];
                        caracter[j][i] = num_1[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = num_1[j][row_aux];
                        caracter[j][i] = num_1[j][row_aux];
                    }
                    break;
                }
                case 9: // LETRA 1
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = num_1[j][row];
                        caracter[j][i] = num_1[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = num_1[j][row_aux];
                        caracter[j][i] = guion[j][row_aux];
                    }
                    break;
                }
                case 10: //  - 
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = num_1[j][row];
                        caracter[j][i] = guion[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = guion[j][row_aux];
                        caracter[j][i] = letra_S[j][row_aux];
                    }
                    break;
                }
                   
                case 11: // LETRA S
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_S[j][row];
                        caracter[j][i] = letra_E[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_E[j][row_aux];
                        caracter[j][i] = letra_C[j][row_aux];
                    }
                    break;
                }
                case 12: // LETRA E
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_E[j][row];
                        caracter[j][i] = letra_C[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_C[j][row_aux];
                        caracter[j][i] = letra_C[j][row_aux];
                    }
                    break;
                }
                case 13: // LETRA C
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_C[j][row];
                        caracter[j][i] = letra_C[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_C[j][row_aux];
                        caracter[j][i] = letra_I[j][row_aux];
                    }
                    break;
                }
                case 14: // LETRA C
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_C[j][row];
                        caracter[j][i] = letra_I[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_I[j][row_aux];
                        caracter[j][i] = letra_O[j][row_aux];
                    }
                    break;
                }
                case 15: // LETRA I
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_I[j][row];
                        caracter[j][i] = letra_O[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_O[j][row_aux];
                        caracter[j][i] = letra_N[j][row_aux];
                    }
                    break;
                }
                case 16: // LETRA O
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_O[j][row];
                        caracter[j][i] = letra_N[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_N[j][row_aux];
                        caracter[j][i] = espacio[j][row_aux];
                    }
                    break;
                }
                case 17: // LETRA N
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_N[j][row];
                        caracter[j][i] = letra_A[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_A[j][row_aux];
                        caracter[j][i] = letra_T[j][row_aux];
                    }
                    break;
                }
                case 18: // LETRA 
                {
                    if (row < 8) {
                        // LETRA ACTUAL
                        caracter_driver[j][i] = letra_A[j][row];
                        caracter[j][i] = letra_T[j][row];
                    }
                    else {
                        // SIGUIENTE LETRA
                        caracter_driver[j][i] = letra_T[j][row_aux];
                        caracter[j][i] = letra_P[j][row_aux];
                    }
                    break;
                }         
            }

        }
        if (row >= 8) {
            row_aux++;
        }
    }

    matrix.clearDisplay(0);
    clearMatrix();
    
    delay(speedIntro);

    caracter_conDriver(caracter_driver);
    caracter_aMano(caracter);
    
    if (direccion == 0) {
        // HACIA DERECHA
        top++;
        if (top > 7) {
            top = 0;
            if (letra == 18) letra = 0;
            else letra ++;
        }
    }
    else {
        // HACIA IZQUIERDA
        top--;
        if (top < 0) {
            top = 7;
            if (letra == 0) letra = 18;
            else letra--;
        }
    }
}
