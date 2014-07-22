#Egg_Data_Sample

##Egg_HUM
```
INSERT INTO `Egg_HUM`.`EEF0` (`Time`, `Humidity`) VALUES (FROM_UNIXTIME('1405094400'), '65.5');
```

##Egg_MPU
```
INSERT INTO `Egg_MPU`.`EEF0` (`Time`, `Acc-x`, `Acc-y`, `Acc-z`, `Gyro-x`, `Gyro-y`, `Gyro-z`) VALUES (FROM_UNIXTIME('1405094400'), '0.6', '0.2', '-0.7', '12.5', '-7.8', '13.9');
```

##Egg_TMP
```
INSERT INTO `Egg_TMP`.`EEF0` (`Time`, `Temp-01`, `Temp-02`, `Temp-03`, `Temp-04`, `Temp-05`, `Temp-06`, `Temp-07`, `Temp-08`, `Temp-09`, `Temp-10`, `Temp-11`, `Temp-12`, `Temp-13`, `Temp-14`) VALUES (FROM_UNIXTIME('1405094400'), '35.2', '33.1', '34.2', '28.9', '29.9', '32.9', '35.8', '33.8', '34.1', '28.7', '29.3', '32.8', '-5.5', '18.2');
```


#Weather_Data_Sample
```
INSERT INTO `Weather`.`EEF0` (`Time`, `Humidity`, `Light`, `Pressure`, `Temperature`) VALUES (FROM_UNIXTIME('1405094400'), '68.2', '684.4', '101325', '32.6');
```
