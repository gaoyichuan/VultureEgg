-- phpMyAdmin SQL Dump
-- version 3.4.11.1deb2
-- http://www.phpmyadmin.net
--
-- 主机: localhost
-- 生成日期: 2014 年 07 月 21 日 17:29
-- 服务器版本: 5.5.37
-- PHP 版本: 5.4.4-14+deb7u10

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- 数据库: `Weather`
--
CREATE DATABASE `Weather` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `Weather`;

-- --------------------------------------------------------

--
-- 表的结构 `EEF0`
--

DROP TABLE IF EXISTS `EEF0`;
CREATE TABLE IF NOT EXISTS `EEF0` (
  `Time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `Humidity` decimal(3,1) NOT NULL,
  `Light` decimal(5,1) NOT NULL,
  `Pressure` int(6) NOT NULL,
  `Temperature` decimal(3,1) NOT NULL
  
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
