-- phpMyAdmin SQL Dump
-- version 3.4.11.1deb2
-- http://www.phpmyadmin.net
--
-- 主机: localhost
-- 生成日期: 2014 年 07 月 20 日 21:17
-- 服务器版本: 5.5.37
-- PHP 版本: 5.4.4-14+deb7u10

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- 数据库: `Egg_HUM`
--
DROP DATABASE `Egg_HUM`;
CREATE DATABASE `Egg_HUM` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `Egg_HUM`;

-- --------------------------------------------------------

--
-- 表的结构 `EEF0`
--

DROP TABLE IF EXISTS `EEF0`;
CREATE TABLE IF NOT EXISTS `EEF0` (
  `Time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `Humidity` decimal(3,1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
--
-- 数据库: `Egg_MPU`
--
DROP DATABASE `Egg_MPU`;
CREATE DATABASE `Egg_MPU` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `Egg_MPU`;

-- --------------------------------------------------------

--
-- 表的结构 `EEF0`
--

DROP TABLE IF EXISTS `EEF0`;
CREATE TABLE IF NOT EXISTS `EEF0` (
  `Time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `Acc-x` decimal(3,1) NOT NULL,
  `Acc-y` decimal(3,1) NOT NULL,
  `Acc-z` decimal(3,1) NOT NULL,
  `Gyro-x` decimal(4,1) NOT NULL,
  `Gyro-y` decimal(4,1) NOT NULL,
  `Gyro-z` decimal(4,1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
--
-- 数据库: `Egg_TMP`
--
DROP DATABASE `Egg_TMP`;
CREATE DATABASE `Egg_TMP` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `Egg_TMP`;

-- --------------------------------------------------------

--
-- 表的结构 `EEF0`
--

DROP TABLE IF EXISTS `EEF0`;
CREATE TABLE IF NOT EXISTS `EEF0` (
  `Time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Temp-01` decimal(3,1) NOT NULL,
  `Temp-02` decimal(3,1) NOT NULL,
  `Temp-03` decimal(3,1) NOT NULL,
  `Temp-04` decimal(3,1) NOT NULL,
  `Temp-05` decimal(3,1) NOT NULL,
  `Temp-06` decimal(3,1) NOT NULL,
  `Temp-07` decimal(3,1) NOT NULL,
  `Temp-08` decimal(3,1) NOT NULL,
  `Temp-09` decimal(3,1) NOT NULL,
  `Temp-10` decimal(3,1) NOT NULL,
  `Temp-11` decimal(3,1) NOT NULL,
  `Temp-12` decimal(3,1) NOT NULL,
  `Temp-13` decimal(3,1) NOT NULL,
  `Temp-14` decimal(3,1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
