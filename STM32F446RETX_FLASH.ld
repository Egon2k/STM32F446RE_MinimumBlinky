_estack = 0x20001000;

MEMORY
{
  RAM     (xrw)    : ORIGIN = 0x20000000,  LENGTH = 128K
  FLASH    (rx)    : ORIGIN = 0x08000000,  LENGTH = 512K
}