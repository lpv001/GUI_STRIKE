#include "./telemetry.h"
#include "./AvionicsReceive.h"

byte strikeTlm[tlm_length];
//MPU6050
STRIKE_t accX;
STRIKE_t accY;
STRIKE_t accZ;

STRIKE_t gyroX;
STRIKE_t gyroY;
STRIKE_t gyroZ;

STRIKE_t roll;
STRIKE_t pitch;
STRIKE_t yaw;

//BMP180
STRIKE_t pres;
STRIKE_t alttitude;
STRIKE_t temp;

//GPS
STRIKE_t longitude;
STRIKE_t latitude;

void telemetryInitialise(void)
{
  for (int i = 0; i < tlm_length; i++)
  {
    strikeTlm[i] = 0x00;
  }
}

void telemetryUpdate(void) {

  accX.value = data.accelerometerX;
  accY.value = data.accelerometerY;
  accZ.value = data.accelerometerZ;

  gyroX.value = data.roll_rate;
  gyroY.value = data.pitch_rate;
  gyroZ.value = data.yaw_rate;

  roll.value = data.roll;
  pitch.value = data.pitch;
  yaw.value = data.yaw;

  pres.value = data.P;
  alttitude.value = data.H;
  temp.value = data.T;

  longitude.value = random(0, 20);
  latitude.value = random(0, 10);


  strikeTlm[tlm_h0] = 'H';
  strikeTlm[1] = cmdCounter;
  strikeTlm[2] = cmdBuffer[0];
  strikeTlm[3] = cmdBuffer[1];
  strikeTlm[4] = value1;
  strikeTlm[5] = 5;

  strikeTlm[6] = accX.bytes[3];
  strikeTlm[7] = accX.bytes[2];
  strikeTlm[8] = accX.bytes[1];
  strikeTlm[9] = accX.bytes[0];

  strikeTlm[10] = accY.bytes[3];
  strikeTlm[11] = accY.bytes[2];
  strikeTlm[12] = accY.bytes[1];
  strikeTlm[13] = accY.bytes[0];

  strikeTlm[14] = accZ.bytes[3];
  strikeTlm[15] = accZ.bytes[2];
  strikeTlm[16] = accZ.bytes[1];
  strikeTlm[17] = accZ.bytes[0];

  strikeTlm[18] = gyroX.bytes[3];
  strikeTlm[19] = gyroX.bytes[2];
  strikeTlm[20] = gyroX.bytes[1];
  strikeTlm[21] = gyroX.bytes[0];

  strikeTlm[22] = gyroY.bytes[3];
  strikeTlm[23] = gyroY.bytes[2];
  strikeTlm[24] = gyroY.bytes[1];
  strikeTlm[25] = gyroY.bytes[0];

  strikeTlm[26] = gyroZ.bytes[3];
  strikeTlm[27] = gyroZ.bytes[2];
  strikeTlm[28] = gyroZ.bytes[1];
  strikeTlm[29] = gyroZ.bytes[0];

  strikeTlm[30] = roll.bytes[3];
  strikeTlm[31] = roll.bytes[2];
  strikeTlm[32] = roll.bytes[1];
  strikeTlm[33] = roll.bytes[0];

  strikeTlm[34] = pitch.bytes[3];
  strikeTlm[35] = pitch.bytes[2];
  strikeTlm[36] = pitch.bytes[1];
  strikeTlm[37] = pitch.bytes[0];

  strikeTlm[38] = yaw.bytes[3];
  strikeTlm[39] = yaw.bytes[2];
  strikeTlm[40] = yaw.bytes[1];
  strikeTlm[41] = yaw.bytes[0];

  strikeTlm[42] = pres.bytes[3];
  strikeTlm[43] = pres.bytes[2];
  strikeTlm[44] = pres.bytes[1];
  strikeTlm[45] = pres.bytes[0];

  strikeTlm[46] = alttitude.bytes[3];
  strikeTlm[47] = alttitude.bytes[2];
  strikeTlm[48] = alttitude.bytes[1];
  strikeTlm[49] = alttitude.bytes[0];

  strikeTlm[50] = temp.bytes[3];
  strikeTlm[51] = temp.bytes[2];
  strikeTlm[52] = temp.bytes[1];
  strikeTlm[53] = temp.bytes[0];

  strikeTlm[54] = longitude.bytes[3];
  strikeTlm[55] = longitude.bytes[2];
  strikeTlm[56] = longitude.bytes[1];
  strikeTlm[57] = longitude.bytes[0];

  strikeTlm[58] = latitude.bytes[3];
  strikeTlm[59] = latitude.bytes[2];
  strikeTlm[60] = latitude.bytes[1];
  strikeTlm[61] = latitude.bytes[0];
}

void telemetryOutputSerial(void)
{
  for (int i = 0; i < tlm_length; i++)
  {
    Serial.write(strikeTlm[i]);
  }
}
