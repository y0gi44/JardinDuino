/*
 * myConfig.cpp
 *
 *  Created on: 27 mars 2018
 *      Author: yogi
 */

#include "myConfig.h"

myConfig::myConfig() {
	// TODO Auto-generated constructor stub

}

myConfig::~myConfig() {
	// TODO Auto-generated destructor stub
}

IPAddress myConfig::getIPAdress(int eeAddress){
  uint8_t bytes[4];
  EEPROM.get(eeAddress, bytes);
  return IPAddress(bytes);
}

void myConfig::putIPAdress(IPAddress ip, int eeAddress){
	uint8_t bytes[4];
	for (int i = 0 ; i < 4 ; i++ )
		bytes[i] = ip[i];

	EEPROM.put(eeAddress, bytes);
}

unsigned int myConfig::getPort(int eeAddress){
	unsigned int port = 0 ;
	EEPROM.get(eeAddress, port);
	return port;
}

void myConfig::putPort(int eeAddress,unsigned int port){
	EEPROM.put(eeAddress, port);
}
