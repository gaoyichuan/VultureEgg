**Code in Raspberry Pi**
#File List
```
mydb.h = MySQL API Library
mydb.cpp = MySQL API Library Source
rpi.cpp = Main Source File
```

#Requirements
*wiringPi Library & MySQL_Client Library*    
*How to install them*
```
MySQL_Client:http://dev.mysql.com/tech-resources/articles/building-mysql-connector-cpp.html
wiringPi:http://wiringpi.com/download-and-install/
```

#Source Code Building
```
g++ rpi.cpp mydb.cpp -orpi -lwiringPi -lmysqlclient
```
