#pragma once

#include <cstdint>
#include "main.h"

using std::uint8_t;

namespace SPI
{
    class FullDuplexClass{
    public:
        FullDuplexClass(SPI_TypeDef * const spi);
        uint8_t TxRx(const uint8_t data) const;

    private:
        SPI_TypeDef * const _spi;
    };
} // namespace  SPI
