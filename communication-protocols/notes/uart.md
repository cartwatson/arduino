# Universal Asynchronos Receiver Transmitter

## basics

- serial communication
    - used in `serial.print()`
- device to device
- async serial communication
    - configurable transmission speed and data format
    - replaced by SPI and i2c
        - used in low speed low throughput applications
            - due to simplicity to develop & implement
- serial data transmits one bit at a time, parallel does more than one bit at a time
    - only requires two cables, one to receive and one to transmit
- sends start bit, data, parity (optional), end bit
- devices need a common ground, they can't determine high/low without it 
- necessary components: transmitter, receiver (duh), and a baud rate
    - baud rate (bits/second) determines transmission speed
        - this removes the need for shared clock speed
        - high baud rate is harder to sync but is faster
        - low baud rate is easy to sync and has higher data accuracy

## flow control

- used when devices have different operating speeds
    - receiver can tell transmitter to pause and resume transmission
- hardware vs software flow control
    - hardware flow control uses extra wires
    - software flow control uses special characters in data
        - Q: what are the odds the tx doesn't pause/resume when it should
            - Qcont: what fall backs exist for this

## UART Frame Format

- start bit
    - logic low ALWAYS
    - voltage is lower than rx's logic high
- data bits
    - can vary in amount sent, this is referred to as "character size"
    - character size
        - 8-bit is most common, 7bit and 6bit varients exist for particular use cases
        - needs to be synced between rx and tx
    - parity bit
        - part of data bits
        - not required
        - can be set to odd or even
            - if odd it will make the data bits equal to a logic 1
                - eg: for data bits 0110101 parity bit would be 1 as 1+1+1+1 + 1 = 1
                    - for the same situation in even the parity bit would be 0
- stop bit
    - usually 1 stop bit is sent, in cases where reliability is needed 2 can be sent
    - can be high or low based on config

## overview

Overall UART is an old standard for device to device async serial communication, while it's commonly replaced by SPI and I2C it has use cases in low throughput and low speed applications.
