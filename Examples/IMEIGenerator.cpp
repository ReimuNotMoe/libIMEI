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

#include "../libIMEI.hpp"

#include <iostream>

using namespace IMEIPlus;

int main() {
	auto imei = IMEI::GenerateRandom();

	std::string imei_str = imei;
	uint64_t imei_int = imei;

	std::cout << imei_str << "\n";

	return 0;
}