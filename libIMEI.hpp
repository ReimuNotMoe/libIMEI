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

#ifndef LIBIMEI_LIBIMEI_HPP
#define LIBIMEI_LIBIMEI_HPP

#include "libIMEI.h"

#include <string>

namespace IMEIPlus {
    class IMEI {
    private:
	mutable uint64_t raw_imei = 0;
    public:
	IMEI() = default;

	IMEI& operator= (uint64_t __imei) noexcept;
	inline bool operator== (const IMEI &__rhs) const noexcept;

	operator std::string() const noexcept;
	operator uint64_t() const noexcept;

	static uint64_t Random() noexcept;
	static IMEI GenerateRandom() noexcept;

	static bool Verify(uint64_t __imei) noexcept;
	static bool Verify(const std::string &__imei) noexcept;
	static bool Verify(const IMEI &__imei) noexcept;

	void SetRandom() const noexcept;
    };
}


#endif //LIBIMEI_LIBIMEI_HPP
