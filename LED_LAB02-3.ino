// Lab02_3
// 使用陣列的跑馬燈程式 開關
// 每個 LED 正極接到 Pin 0 - 7, 負極接地
const byte LEDs[] = {2,3,4,5,8,9,10,11};
const byte total =sizeof(LEDs);
byte index = 0;
byte crll = 0;//閃燈控制
byte crl = 0;//左右控制變數
void setup(){
// 將每個 Pin 設定成輸出
for (byte i=0;i<total;i++) {
pinMode(LEDs[i], OUTPUT);
}
pinMode(6,INPUT);
}



void loop() {
//控制開關
if(digitalRead(6)==0)
{
  //左右判斷
if(crl==0)//右到左
{
// 所有 LED OFF
for (byte i=0;i<total;i++) {
digitalWrite(LEDs[i], LOW);
}
// 點亮 index 位置之 LED
digitalWrite(LEDs[index], HIGH);
// 如果點亮的腳位編號小於結束腳位, 則腳位編號+1
if (index+1 < total) {
index++;
} else {
  delay(200);
digitalWrite(LEDs[index], LOW);
crl = 1;
}
delay(200);
}
else{//左到右
  // 所有 LED OFF
for (byte i=0;i<total;i++) {
digitalWrite(LEDs[i], LOW);
}
// 點亮 index 位置之 LED
digitalWrite(LEDs[index], HIGH);
// 如果點亮的腳位編號大於結束腳位, 則腳位編號-1
if (index > 0) {
index--;
} else {
  delay(200);
  digitalWrite(LEDs[index], LOW);
index = 0;
crl = 0;
}
delay(200);
}
}else if(digitalRead(6)==1)//控制開關2
{
if(crll==0)
{
// 所有 LED OFF
for (byte i=0;i<total;i++) {
digitalWrite(LEDs[i], LOW);
}
delay(500);
//所有LED ON
for (byte i=0;i<total;i++) {
digitalWrite(LEDs[i], HIGH);
}
delay(500);
// 所有 LED OFF
for (byte i=0;i<total;i++) {
digitalWrite(LEDs[i], LOW);
}
delay(500);
//所有LED ON
for (byte i=0;i<total;i++) {
digitalWrite(LEDs[i], HIGH);
}
delay(500);
crll++;
}
//左右判斷
if(crl<8)//右到左
{
// 所有 LED OFF
for (byte i=0;i<total;i++) {
digitalWrite(LEDs[i], LOW);
}
// 點亮 index 位置之 LED
digitalWrite(LEDs[index], HIGH);
// 如果點亮的腳位編號小於結束腳位, 則腳位編號+1
if (index+1 < total) {
index++;
} else {
  delay(200);
digitalWrite(LEDs[index], LOW);
crl++;
if(crl<8)
{index = 0;
}else
{crll = 0;
}
}
delay(200);
}
else if(crl<16){//左到右
  // 所有 LED OFF
for (byte i=0;i<total;i++) {
digitalWrite(LEDs[i], LOW);
}
// 點亮 index 位置之 LED
digitalWrite(LEDs[index], HIGH);
// 如果點亮的腳位編號大於結束腳位, 則腳位編號-1
if (index > 0) {
index--;
} else {
  delay(200);
  digitalWrite(LEDs[index], LOW);
index = 7;
crl++;
}
delay(200);
}
  else
  {
    index = 0;
    crl = 0;
    crll = 0;
  }
}
}
