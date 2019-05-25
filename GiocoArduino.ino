#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13 );
int btn1 = 2;
int btn2 = 3;
int btn3 = 4;
int btn4 = 5;
int btn5 = 6;
int vita = 5;
int punteggio = 0; //punteggio che mi definisce il record
int posProx = 0;
int vitaM = 0;   //se premuto aumenta di uno la vita
int vitaP = 0;    //se premuto decrementa di uno la vita
int posPrec = 0;   //mi dice dove c'è appena stato un simbolo
int tempo = 2000;     //tempo tra un simbolo e un altro
int PosizioneLcd[] = {0,3,7,10,14};
String punto = "p";
String VitaP = "+";
String VitaM = "-";



void setup()
{
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
  pinMode(btn3,INPUT);
  pinMode(btn4,INPUT);
  pinMode(btn5,INPUT);
  lcd.begin(16, 2);
}

void loop()
{
  //se ho ancora vite continuo con un nuovo round
  int Pulsanti []= {btn1,btn2,btn3,btn4,btn5};
  if(vita>0)
  {
    while(posProx == posPrec)
    {
      posProx = random(1,6);
    }
    lcd.setCursor(PosizioneLcd[posProx],1);
    lcd.print("A");
    stampo(vita, punteggio);
    if(Gioco(posProx,Pulsanti,punto,tempo))
    {
      punteggio++;
    }
    else
    {
      punteggio--;
    }
    lcd.clear();
    posPrec = posProx;

    tempo-=10;
    while(posProx == posPrec)
    {
      posProx = random(1,6);
    }
    lcd.setCursor(PosizioneLcd[posProx],1);
    lcd.print("+");
    stampo(vita, punteggio);
    if(Gioco(posProx,Pulsanti,VitaP,tempo))
    {
      vita++;
    }
    lcd.clear();
    posPrec = posProx;

    tempo-=10;
    while(posProx == posPrec)
    {
      posProx = random(1,6);
    }
    lcd.setCursor(PosizioneLcd[posProx],1);
    lcd.print("-");
    stampo(vita, punteggio);
    if(Gioco(posProx,Pulsanti,VitaM,tempo))
    {
      vita--;
    }
    lcd.clear();
    posPrec = posProx;
  }
  else
  {
    //il gioco è finito
  }
}

void stampo(int vita, int punteggio)
{
    lcd.setCursor(0,0);
    lcd.print("vite: "+vita);
    lcd.setCursor(14,0);
    lcd.print(punteggio);
}

bool Gioco(int Posizione, int Pulsanti[] , String Testo, int Tempo)
{
  int cont = 0;
  while(cont<tempo)
  {
    if(digitalRead(Pulsanti[Posizione])==HIGH)
    {
      return true;
    }
    cont++;
    delay(1);
  }
  return false;
}
