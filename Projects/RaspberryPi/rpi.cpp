#include <iostream>
#include <wiringSerial.h>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include "mydb.h"

#define DEBUG 1
#define RX_BUF_SIZE 200

using namespace std;
char Package_Type[8],Egg_UUID[6],Timestamp[12],Egg_Acc_Data[30],Egg_Gyro_Data[30],Temp_Data[100],Humi_Data[10],Weather_Light_Data[15],Weather_Pressure_Data[15];

char* get_token(char* buf, const char deli) {
    if (buf == NULL) return NULL;
    size_t end = 0;
    while ((buf[end] != deli) && (buf[end] != 0)) end++;
    buf[end] = 0;
    return buf;
}

char* get_next_token(char* buf, const char deli) {
    if (buf == NULL) return NULL;
    size_t pos = (int)strlen(buf);
    pos++;
    size_t end = pos;
    while ((buf[end] != deli) && (buf[end] != 0)) end++;
    buf[end] = 0;
    return &buf[pos];
}

char* get_token_rest(char* buf) {
    if (buf == NULL) return NULL;
    size_t pos = (int)strlen(buf);
    pos++;
    return &buf[pos];
}

void Clear_String_Buffers()
{
	memset(Package_Type,0,sizeof(Package_Type));
	memset(Egg_UUID,0,sizeof(Egg_UUID));
	memset(Timestamp,0,sizeof(Timestamp));
	memset(Egg_Acc_Data,0,sizeof(Egg_Acc_Data));
	memset(Egg_Gyro_Data,0,sizeof(Egg_Gyro_Data));
	memset(Temp_Data,0,sizeof(Temp_Data));
	memset(Humi_Data,0,sizeof(Humi_Data));
	memset(Weather_Light_Data,0,sizeof(Weather_Light_Data));
	memset(Weather_Pressure_Data,0,sizeof(Weather_Pressure_Data));
}

void MySQL_Write(int type)
{
	CMyDB my;
	my.initDB("localhost" , "root", "root" , "" );
	ostringstream MySQL_Command;
	switch(type)
	{
		case 1:  //Egg MPU data
		MySQL_Command<<"INSERT INTO `Egg_MPU`.`"<<Egg_UUID<<"` (`Time`, `Acc-x`, `Acc-y`, `Acc-z`, `Gyro-x`, `Gyro-y`, `Gyro-z`) VALUES (FROM_UNIXTIME('"<<Timestamp<<"'),"<<Egg_Acc_Data<<","<<Egg_Gyro_Data<<");";
		break;
		
		case 2:  //Egg TMP data
		MySQL_Command<<"INSERT INTO `Egg_TMP`.`"<<Egg_UUID<<"` (`Time`, `Temp-01`, `Temp-02`, `Temp-03`, `Temp-04`, `Temp-05`, `Temp-06`, `Temp-07`, `Temp-08`, `Temp-09`, `Temp-10`, `Temp-11`, `Temp-12`, `Temp-13`, `Temp-14`) VALUES (FROM_UNIXTIME('"<<Timestamp<<"'),"<<Temp_Data<<");";
		break;
		
		case 3:  //Egg HUM data
		MySQL_Command<<"INSERT INTO `Egg_HUM`.`"<<Egg_UUID<<"` (`Time`, `Humidity`) VALUES (FROM_UNIXTIME('"<<Timestamp<<"'),"<<Humi_Data<<");";
		break;
		
		case 4:
		MySQL_Command<<"INSERT INTO `Weather`.`EEF0` (`Time`, `Humidity`, `Light`, `Pressure`, `Temperature`) VALUES (FROM_UNIXTIME('"<<Timestamp<<"'),"<<Humi_Data<<","<<Weather_Light_Data<<","<<Weather_Pressure_Data<<","<<Temp_Data<<");";
		break;
		
		default:
		cout<<"Invalid SQL_Type."<<endl;
		break;
	}
	cout << MySQL_Command.str()<<endl;
	my.executeSQL(MySQL_Command.str());
}

void Data_Parse(char* data)
{
	strcpy(Package_Type, (data = get_token(data, ';')));
	if(strcmp(Package_Type, "Egg") == 0)
	{
		cout<<"Data from egg detected."<<endl;
		strcpy(Egg_UUID, (data = get_next_token(data, ';')));
		strcpy(Timestamp, (data = get_next_token(data, ';')));
		strcpy(Egg_Acc_Data, (data = get_next_token(data, ';')));
		strcpy(Egg_Gyro_Data, (data = get_next_token(data, ';')));
		strcpy(Temp_Data, (data = get_next_token(data, ';')));
		strcpy(Humi_Data, (data = get_token_rest(data)));
		if((strlen(Egg_UUID) > 0) && (strlen(Timestamp) > 0))
		{
			if((strlen(Egg_Acc_Data) > 0) && (strlen(Egg_Gyro_Data) > 0)){
				cout<<"Egg_MPU data detected."<<endl;
				MySQL_Write(1);
			}
			if(strlen(Temp_Data) > 0){
				cout<<"Egg_TMP data detected."<<endl;
				MySQL_Write(2);
			}
			if(strlen(Humi_Data) > 0){
				cout<<"Egg_HUM data detected."<<endl;
				MySQL_Write(3);
			} 
		}
		else {
		cout<<"UUID or timestamp is empty!"<<endl;
		}
	}
	else if(strcmp(Package_Type, "Weather") == 0)
	{
		cout<<"Data from weather station detected."<<endl;
		strcpy(Timestamp, (data = get_next_token(data, ';')));
		strcpy(Temp_Data, (data = get_next_token(data, ';')));
		strcpy(Humi_Data, (data = get_next_token(data, ';')));
		strcpy(Weather_Light_Data, (data = get_next_token(data, ';')));
		strcpy(Weather_Pressure_Data, (data = get_token_rest(data)));
		if(strlen(Timestamp) > 0)
		{
			if((strlen(Temp_Data) > 0) && (strlen(Humi_Data) > 0) && (strlen(Weather_Light_Data) > 0) && (strlen(Weather_Pressure_Data) > 0))
			{
				MySQL_Write(4);
			}
			else {
				cout<<"Data format illegal."<<endl;
			}
		}
		else {
			cout<<"Timestamp is empty."<<endl;
		}
	}
	else {
		cout<<"Invalid package type."<<endl;
	}
	
	#if DEBUG
	cout<<"Package Type:"<<Package_Type<<endl;
	cout<<"UUID:"<<Egg_UUID<<endl;
	cout<<"Time Stamp:"<<Timestamp<<endl;
	cout<<"Acceleration Data:"<<Egg_Acc_Data<<endl;
	cout<<"Gyroscope Data:"<<Egg_Gyro_Data<<endl;
	cout<<"Temperature Data:"<<Temp_Data<<endl;
	cout<<"Humidity Data:"<<Humi_Data<<endl;
	#endif
	Clear_String_Buffers();
}

int main()
{
	cout<<"Open serial port."<<endl;
	int fd = serialOpen("/dev/ttyAMA0",115200);
	int datalength,dataflag,i;
	char gotdata;
	char buf[RX_BUF_SIZE];
	while(1)
	{
		cout<<"FD:"<<fd<<". "<<"Start waiting."<<endl;
		while((serialDataAvail(fd) == 0) || (serialDataAvail(fd) == -1));
		dataflag = 1;
		datalength = serialDataAvail(fd);
		cout<<"Dude! There's some data. "<<"Length:"<<datalength<<"."<<endl;
		while(dataflag)
		{
			gotdata = serialGetchar(fd);
			cout<<gotdata;
			buf[i] = gotdata;
			if(gotdata == 0x0A && buf[i-1] == 0x0D)
			{
				dataflag = 0;
				buf[i-1] = 0;
				buf[i] = 0;
			}
			if(serialDataAvail(fd) == 0) dataflag = 0;
			i++;
			usleep(80);
		}
		cout<<"Data:"<<buf<<endl;
		char *data = buf;
		Data_Parse(data);
		strcpy(data,"");
		gotdata = 0;
		i = 0;
		for (int byte = 0;byte < RX_BUF_SIZE;byte++)
		{
			buf[byte] = 0;
		}
		sleep(1);
	}
	serialClose(fd);
	return 0;
}
