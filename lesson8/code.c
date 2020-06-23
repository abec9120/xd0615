const int numReadings = 10;		//数组大小

int readings[numReadings];      // 定义readings数组
int readIndex = 0;              // 数组的第几个元素，初值为0
int total = 0;                  // 总值
int average = 0;                // 不是平均值，是要输出的值

int inputPin = A0;				//设一个变量保存模拟引脚A0输出的值

void setup() {
  Serial.begin(9600);			//设置串口
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;  //将数组readings所有初值设为0
  }
}

void loop() {
  total = total - readings[readIndex];//总值减去这次循环刚开始时的数组元素的值
  readings[readIndex] = analogRead(inputPin);//赋A0模拟引脚输出的值给这次循环的数组元素
  total = total + readings[readIndex];//总值加上这次循环刚开始时的数组元素的值
  readIndex = readIndex + 1;//数组到下一个元素
  if (readIndex >= numReadings)	 		//如果下标超过了9，则重回第一个元素，否则无法继续进行
  {
    readIndex = 0;//数组下标从0开始，所以赋0给readIndex
  }
  average = total / numReadings;//求要输出的值
  Serial.println(average);//将要输出的值显示到串口监视器上
  delay(1);        //等待一毫秒，使串口读值准确
  
  /*注：若不加total = total - readings[readIndex]一句，则total会一直增加；
    而加了之后，从第二次readIndex = 0开始average就会一直显示一个相同值，原因在于类似（x+y-y）的运算
}