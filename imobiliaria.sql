-- MySQL dump 10.13  Distrib 8.0.40, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: imobiliaria
-- ------------------------------------------------------
-- Server version	8.0.40

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `agencia`
--

DROP TABLE IF EXISTS `agencia`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `agencia` (
  `IDAgencia` int NOT NULL,
  `IDRede` int NOT NULL,
  `IDLocalizacao` int NOT NULL,
  `Nome` varchar(200) NOT NULL,
  `LicencaAMI` varchar(20) NOT NULL,
  PRIMARY KEY (`IDAgencia`),
  KEY `FKAgencia2_idx` (`IDLocalizacao`),
  KEY `FKAgencia1_idx` (`IDRede`),
  CONSTRAINT `FKAgencia1` FOREIGN KEY (`IDRede`) REFERENCES `rede_agencia` (`IDRede`),
  CONSTRAINT `FKAgencia2` FOREIGN KEY (`IDLocalizacao`) REFERENCES `localizacao` (`IDLocalizacao`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `agencia`
--

LOCK TABLES `agencia` WRITE;
/*!40000 ALTER TABLE `agencia` DISABLE KEYS */;
/*!40000 ALTER TABLE `agencia` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `angaria`
--

DROP TABLE IF EXISTS `angaria`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `angaria` (
  `NIFConsultor` int NOT NULL,
  `IDImovel` int NOT NULL,
  `DataEntrada` date NOT NULL,
  PRIMARY KEY (`NIFConsultor`, `IDImovel`),
  KEY `FKAngaria2_idx` (`IDImovel`),
  CONSTRAINT `FKAngaria1` FOREIGN KEY (`NIFConsultor`) REFERENCES `consultor` (`NIF`),
  CONSTRAINT `FKAngaria2` FOREIGN KEY (`IDImovel`) REFERENCES `imovel` (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `angaria`
--

LOCK TABLES `angaria` WRITE;
/*!40000 ALTER TABLE `angaria` DISABLE KEYS */;
/*!40000 ALTER TABLE `angaria` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `conjugue`
--

DROP TABLE IF EXISTS `conjugue`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `conjugue` (
  `NIF` int NOT NULL,
  `Nome` varchar(255) NOT NULL,
  `Telefone` varchar(15) DEFAULT NULL,
  `Email` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`NIF`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `conjugue`
--

LOCK TABLES `conjugue` WRITE;
/*!40000 ALTER TABLE `conjugue` DISABLE KEYS */;
/*!40000 ALTER TABLE `conjugue` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `consultor`
--

DROP TABLE IF EXISTS `consultor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `consultor` (
  `NIF` int NOT NULL,
  `IDAgencia` int NOT NULL,
  `Nome` varchar(255) NOT NULL,
  `Telefone` varchar(15) NOT NULL,
  `Email` varchar(255) NOT NULL,
  `LoadingPage` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`NIF`),
  KEY `FKConsultor1_idx` (`IDAgencia`),
  CONSTRAINT `FKConsultor1` FOREIGN KEY (`IDAgencia`) REFERENCES `agencia` (`IDAgencia`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `consultor`
--

LOCK TABLES `consultor` WRITE;
/*!40000 ALTER TABLE `consultor` DISABLE KEYS */;
/*!40000 ALTER TABLE `consultor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `imovel`
--

DROP TABLE IF EXISTS `imovel`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `imovel` (
  `ID` int NOT NULL,
  `NIFProprietario` int NOT NULL,
  `IDLocalizacao` int NOT NULL,
  PRIMARY KEY (`ID`),
  KEY `FK1_idx` (`NIFProprietario`),
  KEY `FKImovel2_idx` (`IDLocalizacao`),
  CONSTRAINT `FKImovel1` FOREIGN KEY (`NIFProprietario`) REFERENCES `proprietario` (`NIF`),
  CONSTRAINT `FKImovel2` FOREIGN KEY (`IDLocalizacao`) REFERENCES `localizacao` (`IDLocalizacao`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `imovel`
--

LOCK TABLES `imovel` WRITE;
/*!40000 ALTER TABLE `imovel` DISABLE KEYS */;
/*!40000 ALTER TABLE `imovel` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `localizacao`
--

DROP TABLE IF EXISTS `localizacao`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `localizacao` (
  `IDLocalizacao` int NOT NULL,
  `Rua` varchar(150) NOT NULL,
  `Numero` int NOT NULL,
  `Habitacao` varchar(45) DEFAULT NULL,
  `CEP` int NOT NULL,
  `Freguesia` varchar(80) NOT NULL,
  `Concelho` varchar(50) NOT NULL,
  `Distrito` varchar(50) NOT NULL,
  PRIMARY KEY (`IDLocalizacao`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `localizacao`
--

LOCK TABLES `localizacao` WRITE;
/*!40000 ALTER TABLE `localizacao` DISABLE KEYS */;
/*!40000 ALTER TABLE `localizacao` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `proprietario`
--

DROP TABLE IF EXISTS `proprietario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `proprietario` (
  `NIF` int NOT NULL,
  `NIFConjugue` int DEFAULT NULL,
  `Nome` varchar(255) NOT NULL,
  `Telefone` varchar(15) DEFAULT NULL,
  `Email` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`NIF`),
  KEY `FK1_idx` (`NIFConjugue`),
  CONSTRAINT `FKProprietario1` FOREIGN KEY (`NIFConjugue`) REFERENCES `conjugue` (`NIF`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `proprietario`
--

LOCK TABLES `proprietario` WRITE;
/*!40000 ALTER TABLE `proprietario` DISABLE KEYS */;
/*!40000 ALTER TABLE `proprietario` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `rede_agencia`
--

DROP TABLE IF EXISTS `rede_agencia`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `rede_agencia` (
  `IDRede` int NOT NULL,
  `DenominacaoSocial` varchar(100) NOT NULL,
  PRIMARY KEY (`IDRede`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rede_agencia`
--

LOCK TABLES `rede_agencia` WRITE;
/*!40000 ALTER TABLE `rede_agencia` DISABLE KEYS */;
/*!40000 ALTER TABLE `rede_agencia` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-12-27 11:50:50
