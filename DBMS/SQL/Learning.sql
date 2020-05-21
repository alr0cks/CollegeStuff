-- MariaDB dump 10.17  Distrib 10.4.7-MariaDB, for Linux (x86_64)
--
-- Host: localhost    Database: Learning
-- ------------------------------------------------------
-- Server version	10.4.7-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `EMP`
--

DROP TABLE IF EXISTS `EMP`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `EMP` (
  `ID` int(11) NOT NULL,
  `NAME` varchar(6) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `JOBID` int(11) DEFAULT NULL,
  `SALARY` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `JOBID` (`JOBID`),
  CONSTRAINT `EMP_ibfk_1` FOREIGN KEY (`JOBID`) REFERENCES `JOB` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `EMP`
--

LOCK TABLES `EMP` WRITE;
/*!40000 ALTER TABLE `EMP` DISABLE KEYS */;
INSERT INTO `EMP` VALUES (101,'FIRST',1,24000),(102,'SECOND',2,20000),(103,'THIRD',2,150000),(104,'FOURTH',3,60000);
/*!40000 ALTER TABLE `EMP` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,ERROR_FOR_DIVISION_BY_ZERO,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER EMPINSERT
BEFORE
INSERT ON EMP
FOR EACH ROW
BEGIN
INSERT INTO EMPLOG VALUES(NEW.ID, NEW.NAME, NEW.JOBID, NEW.SALARY, current_time());
end */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `EMPLOG`
--

DROP TABLE IF EXISTS `EMPLOG`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `EMPLOG` (
  `ID` int(11) NOT NULL,
  `NAME` varchar(6) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `JOBID` int(11) DEFAULT NULL,
  `SALARY` int(11) DEFAULT NULL,
  `timestamp` time DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `EMPLOG`
--

LOCK TABLES `EMPLOG` WRITE;
/*!40000 ALTER TABLE `EMPLOG` DISABLE KEYS */;
INSERT INTO `EMPLOG` VALUES (104,'FOURTH',3,60000,'15:37:06');
/*!40000 ALTER TABLE `EMPLOG` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `JOB`
--

DROP TABLE IF EXISTS `JOB`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `JOB` (
  `ID` int(11) NOT NULL,
  `MINSAL` int(11) DEFAULT NULL,
  `MAXSAL` int(11) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `JOB`
--

LOCK TABLES `JOB` WRITE;
/*!40000 ALTER TABLE `JOB` DISABLE KEYS */;
INSERT INTO `JOB` VALUES (1,10000,100000),(2,10000,50000),(3,25000,200000),(4,250000,300000);
/*!40000 ALTER TABLE `JOB` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `t`
--

DROP TABLE IF EXISTS `t`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `t` (
  `s1` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `t`
--

LOCK TABLES `t` WRITE;
/*!40000 ALTER TABLE `t` DISABLE KEYS */;
INSERT INTO `t` VALUES (1),(2),(3),(4),(5);
/*!40000 ALTER TABLE `t` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-09-18 14:40:10
