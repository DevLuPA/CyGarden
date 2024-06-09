
#include <Gyver433.h>
Gyver433_RX<3,20> rx;  // указали пин 3

Gyver433_TX<2> tx;  // указали пин 2

char data[255];
void clearData(){
  for(int i=0;i<sizeof(data);i++)  data[i] =0;
}
// дешифрование по  ключу
void getData(){
  if (rx.gotData()){
    if(rx.readData(data)) sendData(data, sizeof(data));

}
}

void shifrate(){
}

void sendData(char *data, int size){
  tx.sendData(data);
}
void setup()
{
 
	Serial.begin(9600); // Скорость передачиданных

  attachInterrupt(0, isr, CHANGE);  // прерывание пина радио по CHANGE

}
// спец. тикер вызывается в прерывании
void isr() {
  rx.tickISR();
}

void loop()
{
  getData();
}

