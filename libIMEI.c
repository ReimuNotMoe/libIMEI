/*
    libIMEI - Tiny IMEI generation and verification library

    This file is part of libIMEI.
    Copyright (C) 2016-2018  ReimuNotMoe

    This program is free software: you can redistribute it and/or modify
    it under the terms of the MIT License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#include "libIMEI.h"

static const uint8_t ReportingBodyIdentifierCodes[] = { 01, 10, 30, 33, 35, 44, 45, 49, 50, 51, 52, 53, 54, 86, 91, 98, 99 };

static inline void Random(size_t len, void *buf){
	int fd = open("/dev/urandom", O_RDONLY);
	read(fd, buf, len);
	close(fd);
}

static inline uint8_t RandomRBI(){
	uint8_t RBIPos = 0;
	Random(1,&RBIPos);
	RBIPos %= sizeof(ReportingBodyIdentifierCodes);
	return ReportingBodyIdentifierCodes[RBIPos];
}

static inline uint64_t RandPart(){
	uint64_t randpart;
	Random(8,&randpart);
	randpart %= 1000000000000;
	return randpart * 10;
}

static inline void Explode(uint64_t IMEI, uint8_t IMEI_Digits[15]){
	IMEI_Digits[0] = 0;
	int j = 14;

	while (IMEI) {
		IMEI_Digits[j] = IMEI % 10;
		IMEI /= 10;
		j--;
	}

}

static inline uint8_t LuhnAlgo(uint8_t IMEI_Digits[15]){
	int j, buf, sum = 0;

	for (j=0;j<=12;j+=2)
		sum += IMEI_Digits[j];


	for (j=1;j<=13;j+=2) {
		buf = IMEI_Digits[j] * 2;
		if (buf >= 10)
			buf = 1 + buf % 10;
		sum += buf;
	}

	int OwO = sum % 10;
	if (OwO)
		return 10 - OwO;
	else
		return 0;
}

static inline uint8_t CheckSum(uint64_t IMEI){
	uint8_t IMEI_Digits[15];
	Explode(IMEI, IMEI_Digits);
	return LuhnAlgo(IMEI_Digits);
}

int IMEI_Verify(uint64_t IMEI){
	uint8_t IMEI_Digits[15];
	Explode(IMEI, IMEI_Digits);
	return (LuhnAlgo(IMEI_Digits) == IMEI_Digits[14]);
}

uint64_t IMEI_Generate_Random(){
	uint64_t IMEI = (uint64_t)RandomRBI() * 10000000000000LLU;
	IMEI += RandPart();
	IMEI += CheckSum(IMEI);
	return IMEI;
}