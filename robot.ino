/*
 * Bel eksen servoları 3 numaralı dijital pindeki 
 * servo azalan derece si (90 dereceden) 4 numaralı 
 * dijital pine bağlı motorun artan derecesine eşit
 */

#include <Servo.h>

Servo servolar[7];

int pozisyon1[6][6]=
{
    {110,90,90,180,160,120}
  ,{110,140,90,90,160,120}
  ,{110,140,140,0,160,120}
  ,{45,90,90,0,0,40}
  ,{45,90,90,120,0,40}
  ,{110,90,90,180,160,120}
};

int bekleme=0,fark=0;

void setup() {
  servolar[0].attach(2);
  servolar[1].attach(3);
  servolar[2].attach(5);
  servolar[3].attach(6);
  servolar[4].attach(7);
  servolar[5].attach(8);
  servolar[6].attach(4);
  Serial.begin(9600);

  /*for(int i=0;i<6;i++)
  {
    servolar[i].write(pozisyon1[0][i]);
  }*/

}

void loop() {
   for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      if(i==0)
      { Serial.println("0. hareket"); Serial.println(pozisyon1[i][j]); Serial.println(pozisyon1[i+5][j]);
        if(pozisyon1[i][j]>pozisyon1[i+5][j])
        { Serial.println("Açı artımı");
          bekleme=20;
          for(int b=pozisyon1[i+5][j];b<=pozisyon1[i][j];b++)
          {
            Serial.println(b);
            if(j==1)
            {
              servolar[j].write(b);
              servolar[j+5].write(180-b);
            }
            else
            {
              servolar[j].write(b);
            }
            fark=pozisyon1[i][j]-b;
            if(fark<10){bekleme+=15;}
            else{if(bekleme>10){bekleme--;}}
            delay(bekleme); 
          }
        }
        else if(pozisyon1[i][j]<pozisyon1[i+5][j])
        { Serial.println("Açı azaltımı");
          bekleme=20;  
          for(int b=pozisyon1[i+5][j];b>=pozisyon1[i][j];b--)
          { Serial.println(b);
             if(j==1)
            {
              servolar[j].write(b);
              servolar[j+5].write(180-b);
            }
            else
            {
              servolar[j].write(b);
            }
            fark=b-pozisyon1[i][j];
            if(fark<10){bekleme+=15;}
            else{if(bekleme>10){bekleme--;}             
            }
            delay(bekleme); 
          }
        }
      }
      else if(i>0)      
      {
        Serial.println("1. veya 2. hareket");
        if(pozisyon1[i][j]>pozisyon1[i-1][j])
        { Serial.println("Açı artımı");Serial.println(pozisyon1[i-1][j]); Serial.println(pozisyon1[i][j]);
          bekleme=20;
          for(int b=pozisyon1[i-1][j];b<=pozisyon1[i][j];b++)
          {
            Serial.println(b);
             if(j==1)
            {
              servolar[j].write(b);
              servolar[j+5].write(180-b);
            }
            else
            {
              servolar[j].write(b);
            }
            fark=pozisyon1[i][j]-b;
            if(fark<10){bekleme+=15;}
            else{if(bekleme>10){bekleme--;}}
            delay(bekleme); 
          }
        }
        else if(pozisyon1[i][j]<pozisyon1[i-1][j])
        { Serial.println("Açı azaltımı");
          bekleme=20;  
          for(int b=pozisyon1[i-1][j];b>=pozisyon1[i][j];b--)
          { 
            Serial.println(b);
             if(j==1)
            {
              servolar[j].write(b);
              servolar[j+5].write(180-b);
            }
            else
            {
              servolar[j].write(b);
            }
            fark=b-pozisyon1[i][j];
            if(fark<10){bekleme+=15;}
            else{if(bekleme>10){bekleme--;}             
            }
            delay(bekleme); 
          }
        }
      }
      
   } 
  }
}
