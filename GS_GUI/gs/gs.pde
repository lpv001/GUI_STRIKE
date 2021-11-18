import processing.serial.*;
Serial myPort;

char HEADER = 'H';

short LF = 10;

short portIndex;

int numReadings = 10;  
int readingCounter = 0;
Table table;
int currentIndex;
int flag;
int correctHeaderFlag;
int time;
int BMPOn;
int BMPOff;
int val;


byte[] tlmBuffer = new byte[128];
int value;
boolean tlmUpdateFlag = false;
int wait = 20;


PImage strike;

void setup() {
  //size(900, 500);
  size(2880, 1800);
  strike = loadImage("strike.jpg");

  surface.setTitle("STRIKE");
  String COM11 = Serial.list()[1];
  myPort = new Serial(this, COM11, 115200);
  guiInit();
  time = millis();

  table = new Table();
  table.addColumn("id");
  table.addColumn("AccX");
  table.addColumn("AccY");
  table.addColumn("AccZ");
  table.addColumn("GyroX");
  table.addColumn("GyroY");
  table.addColumn("GyroZ");
  table.addColumn("Yaw");
  table.addColumn("Pitch");
  table.addColumn("Roll");
  table.addColumn("Pressure");
  table.addColumn("Temperature");
  table.addColumn("Alttitude");

  myPort.bufferUntil('\n');
}

void draw() {

  background(0);
  image(strike, 0, 0);
  strike.resize(0, 250);
  //if (myPort.available() > 0)
  //{ 
  //  val = myPort.readStringUntil('\n');

  //  if (val!=null) {
  //    val = trim(val);
  //    val1 = float(val);
  //  }
   TableRow newRow = table.addRow();
  newRow.setInt("id", table.getRowCount() - 1);
  newRow.setFloat("AccX", acceX);
  newRow.setFloat("AccY", acceY);
  newRow.setFloat("AccZ", acceZ);
  newRow.setFloat("GyroX", gyroX);
  newRow.setFloat("GyroY", gyroY);
  newRow.setFloat("GyroZ", gyroZ);
  newRow.setFloat("Yaw", yaw);
  newRow.setFloat("Pitch", pitch);
  newRow.setFloat("Roll", roll);
  newRow.setFloat("Pressure", pressure);
  newRow.setFloat("Alttitude", alttitude);
  newRow.setFloat("Temperature", temperature);
  

  readingCounter++;

  if (readingCounter % numReadings ==0)
  {
    saveTable(table, "data/Avionics.csv");
  }

  layout();
  processSerialData();


  currentTime.setText(nf(hour(), 2)+":"+nf(minute(), 2)+":"+nf(second(), 2));
  currentDate.setText(nf(day(), 2)+"-"+nf(month(), 2)+"-"+year());

  if (millis() - time > wait)
  {
    time = millis();
    acceXText.setText(nf(acceX) + " x " + nf(acceY) + " y " + nf(acceZ) + " z "); 
    gyroText.setText(nf(gyroX) + " x " + nf(gyroY) + " y " + nf(gyroZ) + " z ");
    anguText.setText(nf(yaw) + " x " + nf(pitch) + " y " + nf(roll) + " z ");
    pressureText.setText(nf(pressure) + " Pascal");
    alttitudeText.setText(nf(alttitude) + " H");
    temperatureText.setText(nf(temperature) + "celcius");
    longitudeText.setText(nf(longitude));
    latitudeText.setText(nf(latitude));


    acceChart.push("acceVX", acceX);
    acceChart.push("acceVY", acceY);
    acceChart.push("acceVZ", acceZ);

    gyroChart.push("gyroVX", gyroX);
    gyroChart.push("gyroVY", gyroY);
    gyroChart.push("gyroVZ", gyroZ);

    anguChart.push("yaw", yaw);
    anguChart.push("pitch", pitch);
    anguChart.push("roll", roll);

    //PressureChart.push("pressure", pressure);
    //AlttiChart.push("alttitude", alttitude);
  }

  if (Value1==1) BMPOn();
  else if (Value1 ==0) BMPOff();
}
