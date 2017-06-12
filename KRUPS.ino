#include <stdio.h>


int Bomba = 2; //Salida para la bomba de agua
int Calentador = 3; // Salida para el calentador de agua
int Led = 7; //salida para el led
int BtnFrio = 5; //Entrada de slider Frio
int BtnCali = 6; //Entrada de Slider Caliente
int Temp=A0;   // Entrada Analogica de Temperatura

int VBtnFrio = 0;
int VBtnCali = 0;
float Vtemp=0.0; //Valor de la entrada de Temperatura

void setup() {
  //Configuracion del puerto serie (para debug)
  Serial.begin(9600);
  //Configuracion de los pines
  pinMode(Temp, INPUT);
  pinMode(BtnCali, INPUT_PULLUP);
  pinMode(BtnFrio, INPUT_PULLUP);
  pinMode(Led, OUTPUT);
  pinMode(Calentador, OUTPUT);
  pinMode(Bomba, OUTPUT);
  digitalWrite(Bomba, LOW);
  digitalWrite(Calentador, LOW);
  digitalWrite(Led, HIGH);
  delay(500);
  digitalWrite(Led, LOW);
  delay(500);
  digitalWrite(Led, HIGH);
  delay(500);
  digitalWrite(Led, LOW);
  delay(500);
}

void loop()
{

  Vtemp=analogRead(Temp);
VBtnFrio= !digitalRead(BtnFrio);
VBtnCali = !digitalRead(BtnCali);
  Serial.print(Vtemp);
  Serial.print(" - BTNCALI: ");
  Serial.print(VBtnCali);
 Serial.print(" - BTNFrio: ");
  Serial.print(VBtnFrio);
 Serial.print(" - Calentador: ");
 Serial.print(digitalRead(Calentador));
 Serial.print(" - Bomba: ");
 Serial.println(digitalRead(Bomba));
 
 
 if (Vtemp < 150)
 {
  digitalWrite(Calentador,HIGH); 
 delay(200);
 digitalWrite(Led, HIGH);
 delay(200);
  digitalWrite(Led, LOW);
  
 }

 if ((Vtemp > 200) && !VBtnCali)
 {
  digitalWrite(Calentador,LOW); 
 digitalWrite(Led, HIGH);
 }

if (VBtnCali && (Vtemp < 230))
{
  digitalWrite(Calentador,HIGH);
 digitalWrite(Led, HIGH);
 delay(200);
  digitalWrite(Led, LOW);
delay(200);
}

if (VBtnCali && (Vtemp >= 250))
{
  digitalWrite(Bomba,HIGH);
 digitalWrite(Led, HIGH);
}

if (!VBtnCali && !VBtnFrio )
{
  digitalWrite(Bomba,LOW);
}

if (VBtnFrio)
{
  digitalWrite(Bomba,HIGH);
  digitalWrite(Led, HIGH);
}
 
}
 
