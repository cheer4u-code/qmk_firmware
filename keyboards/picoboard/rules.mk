# This file intentionally left blank

CUSTOM_MATRIX = yes

SRC += matrix.c button.c

EXTRAINCDIRS += \
        $(PICOSDKROOT)/src/common/pico_stdlib/include \
        $(PICOSDKROOT)/src/rp2_common/pico_stdio/include \
        $(PICOSDKROOT)/src/common/pico_time/include \
        $(PICOSDKROOT)/src/rp2_common/hardware_uart/include
