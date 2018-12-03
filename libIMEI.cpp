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

#include "libIMEI.hpp"

void IMEIPlus::IMEI::SetRandom() const noexcept {
	raw_imei = Random();
}

IMEIPlus::IMEI &IMEIPlus::IMEI::operator=(const uint64_t __imei) noexcept {
	raw_imei = __imei;
}

bool IMEIPlus::IMEI::operator==(const IMEIPlus::IMEI &__rhs) const noexcept {
	return raw_imei == __rhs.raw_imei;
}

IMEIPlus::IMEI::operator std::string() const noexcept {
	auto ret = std::to_string(raw_imei);

	if (raw_imei / 100000000000000 == 0)
		ret.insert(0, "0");

	return ret;
}

IMEIPlus::IMEI::operator uint64_t() const noexcept {
	return raw_imei;
}

uint64_t IMEIPlus::IMEI::Random() noexcept {
	return IMEI_Generate_Random();
}

IMEIPlus::IMEI IMEIPlus::IMEI::GenerateRandom() noexcept {
	IMEI ret;
	ret.SetRandom();

	return ret;
}

bool IMEIPlus::IMEI::Verify(uint64_t __imei) noexcept {
	return IMEI_Verify(__imei) == 1;
}

bool IMEIPlus::IMEI::Verify(const std::string &__imei) noexcept {
	uint64_t buf = strtoull(__imei.c_str(), nullptr, 10);

	return Verify(buf);
}

bool IMEIPlus::IMEI::Verify(const IMEIPlus::IMEI &__imei) noexcept {
	return Verify(__imei.operator uint64_t());
}

