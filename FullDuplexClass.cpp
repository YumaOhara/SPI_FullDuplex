#include <cstdint>
#include "FullDuplexClass.hpp"
using std::uint8_t;

SPI::FullDuplexClass::FullDuplexClass(SPI_TypeDef * const spi): _spi(spi){
    //初期化
}

//マスターからスレーブ、スレーブからマスターにデータを送る用
uint8_t SPI::FullDuplexClass::TxRx(const uint8_t data) const
{
	while(!(_spi->SR & SPI_SR_TXE)) ;
	_spi->DR = data;
	while(!(_spi->SR & SPI_SR_RXNE)) ;
    return _spi->DR;
}
