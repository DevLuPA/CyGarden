
#include <Gyver433.h>
Gyver433_RX<2,20> rx;  // указали пин

// дешифрование по  ключу

void setup()
{
 
	Serial.begin(9600); // Скорость передачиданных
	Serial.println("Read 433mHz begin");

attachInterrupt(0, isr, CHANGE);  // прерывание пина радио по CHANGE

}
// спец. тикер вызывается в прерывании
void isr() {
  rx.tickISR();
}
void loop()
{
   if (rx.gotData()) {                   // если успешно принято больше 0
    Serial.write(rx.buffer, rx.size);   // выводим
    Serial.println();
        // ЧИТАЕМ. СПОСОБ 1
    // я знаю, что передатчик отправляет char[15]
    char data[15];
    
    // читаем принятые данные в data
    // если данные совпадают по размеру - ок
    if (rx.readData(data)) Serial.print(data);
    else Serial.print("Data error");
    // выведем также качество соединения
    Serial.print(", RSSI: ");
    Serial.println(rx.getRSSI());
    }

  

}