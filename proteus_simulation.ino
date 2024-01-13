#include<time.h>
int hizmetID[4]={1,2,3,4};
char hizmetAd[4][30]={"köpükleme","yıkama","kurulama","cilalama"};
int hizmetKalan[4]={1,50,100,20};
int hizmetFiat[4]={15,10,5,50};


int ucret=0;
int para=0;

int TL100=10;
int TL50=10;
int TL20=10;
int TL10=10;
int TL5=10;
int toppara=TL5*5+TL10*10+TL20*20+TL50*50+TL100*100;

int x1=0,x2=0,x3=0,x4=0,x5=0,y1=0,y2=0,y3=0,y4=0,pres=0,hres=0;
int k1=0,k2=0,k3=0,k4=0,k5=0;

const int b1=13;
const int b2=10;
const int b3=9;
const int b4=8;
const int b5=7;
const int bson=6;
const int bres=16;


int b1_durum=0;
int b2_durum=0;
int b3_durum=0;
int b4_durum=0;
int b5_durum=0;
int bson_durum=0;
int bres_durum=0;

int bekle=0;
int bekle2=0;



const int yesil=14;
const int kirmizi=15;

 int rasgele;

///////////////////////////////////////////////////////////////////////////////////////////////  PARA

void paramiktar (){
  //Serial.print("para= ");
  //Serial.println(toppara);
  Serial.print("100Tl= "); Serial.print(TL100);Serial.print("    ");
  Serial.print("kopukleme= "); Serial.println(hizmetKalan[0]);  
  Serial.print("50Tl= ");  Serial.print(TL50);Serial.print("     ");
  Serial.print("yikama= "); Serial.println(hizmetKalan[1]);
  Serial.print("20Tl= ");  Serial.print(TL20);Serial.print("     ");
  Serial.print("kurulama= "); Serial.println(hizmetKalan[2]);  
  Serial.print("10Tl= ");  Serial.print(TL10);Serial.print("     ");
  Serial.print("cilalama= "); Serial.println(hizmetKalan[3]);  
  Serial.print("5Tl= ");   Serial.println(TL5);
  Serial.println("------------");
}




void buton1para(){
x1=x1+1;
  Serial.println("5 TL");
  delay(bekle);
  }

void buton2para(){
x2=x2+1;
Serial.println("10 TL");
delay(bekle);
  }


void buton3para(){
x3=x3+1;
Serial.println("20 TL");
delay(bekle);

  }


void buton4para(){
x4=x4+1;
Serial.println("50 TL");
delay(bekle);

  }



void buton5para(){
x5=x5+1;
Serial.println("100 TL");
delay(bekle);

  }


void butonsonpara(){
  para=x1*5+x2*10+x3*20+x4*50+x5*100;
  Serial.print("Yuklenen para= ");
  Serial.println(para);
  delay(bekle2*3);

  TL5=TL5+x1;
  TL10=TL10+x2;
  TL20=TL20+x3;
  TL50=TL50+x4;
  TL100=TL100+x5;
  toppara=TL5*5+TL10*10+TL20*20+TL50*50+TL100*100;
  paramiktar();
  }


void butonrespara(){
x1=0;
x2=0;
x3=0;
x4=0;
x5=0;
Serial.println("para sifilandi"); 
}



////////////////////////////////////////////////////////////////////////////////////////////////////  BUTON




void buton1hiz(){
  if(toppara>=15 && hizmetKalan[0]>0){
y1=y1+1;
toppara=toppara-15;
  Serial.println("kopukleme -15TL");
  delay(bekle);}

else{
  Serial.println("para 15 den az yada kopuk yok");
  }

  }

void buton2hiz(){
    if(toppara>=10 && hizmetKalan[1]>0){
y2=y2+1;
toppara=toppara-10;
Serial.println("yikama -10TL");
delay(bekle);}
else{
  Serial.println("para 10 den az yada su yok");
  }


  }


void buton3hiz(){
    if(toppara>=5 && hizmetKalan[2]>0){

y3=y3+1;
toppara=toppara-5;
Serial.println("kurulama -5TL");

delay(bekle);}
else{
  Serial.println("para 5 den az yada bez yok");
  }


  }


void buton4hiz(){
  //Serial.println(toppara);
    if(toppara>=50 && hizmetKalan[3]>0){

y4=y4+1;
toppara=toppara-50;
Serial.println("cilalama -50TL");
delay(bekle);}
else{
  Serial.println("para 50 den az yada cila yok");
  }


  }



void butonsonhiz(){
Serial.print("rasgele= ");
Serial.println(rasgele);
    if(rasgele==2){ 

      digitalWrite (kirmizi,HIGH);

  TL5=TL5-x1;
  TL10=TL10-x2;
  TL20=TL20-x3;
  TL50=TL50-x4;
  TL100=TL100-x5;
  toppara=TL5*5+TL10*10+TL20*20+TL50*50+TL100*100;    
paramiktar();      
      return;
      
      }
      
  

  digitalWrite (yesil,HIGH);

      

    ucret=y1*15+y2*10+y3*5+y4*50;
  Serial.print("Verilecek Ucret= ");
  Serial.println(ucret);
  delay(bekle2*3);


  hizmetKalan[0]=hizmetKalan[0]-y1;
  hizmetKalan[1]=hizmetKalan[1]-y2;
  hizmetKalan[2]=hizmetKalan[2]-y3;
  hizmetKalan[3]=hizmetKalan[3]-y4;
  
  
  
  paramiktar();
  delay(300);
  islem();
  }


void butonreshiz(){
y1=0;
y2=0;
y3=0;
y4=0;
Serial.println("buton sifirlandi");
}








void islem(){
  
  k1=0,k2=0,k3=0,k4=0,k5=0;

while(ucret!=0){
  
while(TL100!=0 && ucret>=100 ){
  TL100=TL100-1;
  k5=k5+1;
  //toppara=toppara-100;
  ucret=ucret-100;
}

while(TL50!=0 && ucret>=50 ){
  TL50=TL50-1;
  k4=k4+1;
  //toppara=toppara-50;
  ucret=ucret-50;
}  

while(TL20!=0 && ucret>=20 ){
  TL20=TL20-1;
  k3=k3+1;
  //toppara=toppara-20;
  ucret=ucret-20;
}  

while(TL10!=0 && ucret>=10 ){
  TL10=TL10-1;
  k2=k2+1;
  //toppara=toppara-10;
  ucret=ucret-10;
}  

while(TL5!=0 &&  ucret>=5 ){
  TL5=TL5-1;
  k1=k1+1;
  //toppara=toppara-5;
  ucret=ucret-5;
}



  
 Serial.println(ucret);
 paramiktar();

 if(ucret>0){
 Serial.println("para yetmedi");
 
  TL5=TL5+k1;
  TL10=TL10+k2;
  TL20=TL20+k3;
  TL50=TL50+k4;
  TL100=TL100+k5;

  hizmetKalan[0]=hizmetKalan[0]+y1;
  hizmetKalan[1]=hizmetKalan[1]+y2;
  hizmetKalan[2]=hizmetKalan[2]+y3;
  hizmetKalan[3]=hizmetKalan[3]+y4;
  paramiktar();
  
 break;
  }
  
  }

  }


   


///////////////////////////////////////////////////////////////////////////////////////////////  SETUP
void setup() {
  Serial.begin(9600);
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);
  pinMode(b5,INPUT);
  pinMode(bson,INPUT);  
  pinMode(bres,INPUT);
  pinMode(kirmizi,OUTPUT);  
  pinMode(yesil,OUTPUT);
  randomSeed(analogRead(A4));
  paramiktar();
}
//////////////////////////////////////////////////////////////////////
void loop() {

     





while(pres==0){
  
 int x =270;

b1_durum=digitalRead(b1);

if(b1_durum==1){
  delay(x);
buton1para();}

b2_durum=digitalRead(b2);

if(b2_durum==1){
  delay(x);
buton2para();}

b3_durum=digitalRead(b3);

if(b3_durum==1){
  delay(x);
buton3para();}

b4_durum=digitalRead(b4);

if(b4_durum==1){
  delay(x);
buton4para();}

b5_durum=digitalRead(b5);

if(b5_durum==1){
  delay(x);
buton5para();}


bson_durum=digitalRead(bson);
if(bson_durum==1){
  delay(x);
butonsonpara();
pres=1;
 hres=0;
}
 
 
bres_durum=digitalRead(bres);
if(bres_durum==1){
  delay(x);
butonrespara();
}
 
}


////////////////////////////////////////////////////////////////



while(hres==0){
   int x =270;
  rasgele=random(1,5);



b1_durum=digitalRead(b1);
if(b1_durum==1){
  delay(x);
buton1hiz();}

b2_durum=digitalRead(b2);
if(b2_durum==1){
  delay(x);
buton2hiz();}

b3_durum=digitalRead(b3);
if(b3_durum==1){
  delay(x);
buton3hiz();}

b4_durum=digitalRead(b4);
if(b4_durum==1){
  delay(x);
buton4hiz();}


bson_durum=digitalRead(bson);
if(bson_durum==1){
  delay(x);
butonsonhiz();
hres=1;
pres=0;

butonrespara();
butonreshiz();
ucret=0;
para=0;
      delay(1000);
      digitalWrite (yesil,LOW);
      digitalWrite (kirmizi,LOW);
}
 
 
bres_durum=digitalRead(bres);
if(bres_durum==1){
  delay(x);
butonreshiz();
}
 


 }


}
