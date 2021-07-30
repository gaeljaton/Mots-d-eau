//#include <avr/pgmspace.h>
#include <Debouncer.h>;
Debouncer bouncer10(10, 50);//50 ms
Debouncer bouncer11(11, 50);
#include "font8pixel.h"
bool flagHalfRound = 0;
bool flag0 = 0;
bool flagRead = 0;
byte frameChar = 0;
int phraseNow = 0;
uint16_t stepChar  = 0;
const int maxLen = 300;
const char string_0[maxLen] PROGMEM = ",";
const char string_1[maxLen] PROGMEM = "*";
const char string_2[maxLen] PROGMEM = "@";
const char string_3[maxLen] PROGMEM = ",";
const char string_4[maxLen] PROGMEM = "S 4";
const char string_5[maxLen] PROGMEM = "S 5";
const char string_6[maxLen] PROGMEM = "S 1";
const char string_7[maxLen] PROGMEM = "S2";
const char string_8[maxLen] PROGMEM = "S 3";
const char string_9[maxLen] PROGMEM = "S 4";
const char string_10[maxLen] PROGMEM = "S 5";
const char string_11[maxLen] PROGMEM = "S 1";
const char string_12[maxLen] PROGMEM = "S 2";
const char string_13[maxLen] PROGMEM = "S 3";
const char string_14[maxLen] PROGMEM = "S 4";
const char string_15[maxLen] PROGMEM = "*PORTEZ CE (VIEUX) WHISKY AU 'JUGE' BLOND QUI FUME!* J'AI: <1234[56]7890% = ?>.^_^ @#-+/,$";
const char *const string_table[] PROGMEM = {string_0, string_1, string_2, string_3, string_4, string_5, string_6, string_7, string_8, string_9, string_10, string_11, string_12, string_13, string_14, string_15};
char phrase[maxLen] = {0};

void setup() {
  pinMode(2, OUTPUT); pinMode(3, OUTPUT); pinMode(4, OUTPUT); pinMode(5, OUTPUT); pinMode(6, OUTPUT); pinMode(7, OUTPUT); pinMode(8, OUTPUT); pinMode(9, OUTPUT);
  pinMode(10, INPUT_PULLUP); pinMode(11, INPUT_PULLUP); pinMode(14, INPUT_PULLUP); pinMode(15, INPUT_PULLUP); pinMode(16, INPUT_PULLUP); pinMode(17, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(18, OUTPUT);
  strcpy_P(phrase, (char *)pgm_read_word(&(string_table[phraseNow])));

  Serial.println(phrase);
}
//void printframe() {
//  for (byte a = 0; a < 8; a++) {
//    digitalWrite(a + 2, bitRead (data[frameChar], a) );
//    if(bitRead (data[frameChar], 7-a))Serial.print("88");
//    else Serial.print("  ");
//  }
//Serial.println("");
//  frameChar++;
//  if (frameChar >= (sizeof(data) - 1)) frameChar = 0;
//}
void bip() {
  for (byte a = 0; a <= phraseNow % 4; a++) {
    if (phraseNow >= 12)tone(18, 3200);
    else if (phraseNow >= 8)tone(18, 1600);
    else if (phraseNow >= 4)tone(18, 800);
    else tone(18, 400);
    delay(400 / (1 + phraseNow % 4));
    noTone(18);
    delay(400 / (1 + phraseNow % 4));
  }
}
void bipBegin1() {
  tone(18, 400);
  delay(300);
  tone(18, 800);
  delay(300);
  tone(18, 1600);
  delay(300);
  noTone(18);
}
void bipBeginLoop() {
  tone(18, 400);
  delay(200);
  tone(18, 800);
  delay(200);
  tone(18, 1600);
  delay(200);
  tone(18, 400);
  delay(200);
  tone(18, 800);
  delay(200);
  tone(18, 1600);
  delay(200);
  noTone(18);
}
void bipEnd() {
  tone(18, 1600);
  delay(300);
  tone(18, 800);
  delay(300);
  tone(18, 400);
  delay(300);
  noTone(18);
}
void printframe() {
  byte charNow =   phrase[stepChar];
  byte pixCol = font[charNow][frameChar];
  if (pixCol == 0 && flag0 && frameChar >= 3) {
    flag0 = 0;
    frameChar = 0;
    stepChar++;
  }
  else {
    for (byte a = 0; a < 8; a++) {
      digitalWrite(a + 2, bitRead (pixCol, a) );
      if (bitRead (pixCol, 7 - a))Serial.print("88");
      else Serial.print("  ");
    }
    Serial.println();
    if (pixCol == 0) flag0 = 1;
    frameChar++;
    if (frameChar >= 8) {
//      if (!digitalRead(17)) {
//        bipEnd();
//        bipEnd();
//      }
      frameChar = 0;
      flag0 = 0;
      stepChar++;
    }
  }
  if (!phrase[stepChar]) {
    if (!digitalRead(17)) {
      bip();
      delay(500);
      bip();
    }
    stepChar = 0;
  }
}
void loop() {
  bouncer10.update(); bouncer11.update();
  if ( bouncer10.falling() && digitalRead(17) && digitalRead(16)) {     // Droite
    Serial.println("top 10");
    phraseNow++;
    phraseNow = phraseNow % 16;
    bip();
    strcpy_P(phrase, (char *)pgm_read_word(&(string_table[phraseNow])));
  }
  if ( bouncer11.falling() && digitalRead(17) && digitalRead(16)) {        // Gauche
    Serial.println("top 11");
    phraseNow--;
    if (phraseNow < 0) phraseNow = 15;
    bip();
    strcpy_P(phrase, (char *)pgm_read_word(&(string_table[phraseNow])));
  }
  if (!flagHalfRound && !digitalRead(14) && !flagRead ) { //&& !digitalRead(16)
    flagHalfRound = 1;
    printframe();
  }
  else if (flagHalfRound && !digitalRead(15) && !flagRead ) { //&&!digitalRead(16)
    flagHalfRound = 0;
    printframe();
  }
  if ( digitalRead(17) && digitalRead(16) && !flagRead) {// bouton 0 Reset et phrase selection
    for (byte i = 0; i < 8; i++) {
      digitalWrite(i + 2, 0);
    }
    flag0 = 0;
    frameChar = 0;
    stepChar = 0;
    flagRead = 1;
    bipEnd();
  }
  else if (!digitalRead(17)  && flagRead) { // bouton I
    flagRead = 0;
    bipBegin1();
  }
  else if (!digitalRead(16) && flagRead) { // bouton II
    flagRead = 0;
    bipBeginLoop();
  }

}
