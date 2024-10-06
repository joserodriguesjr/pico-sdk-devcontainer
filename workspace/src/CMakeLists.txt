add_executable(flappy)

target_compile_definitions(flappy PRIVATE
    PICO_DEFAULT_SPI_INSTANCE=spi0  # Default SPI instance if not defined elsewhere
)

target_sources(flappy PRIVATE main.cpp st7789.c)
target_link_libraries(flappy PRIVATE pico_stdlib pico_stdio hardware_spi hardware_gpio)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(flappy)

# add url via pico_set_program_url
# example_auto_set_url(flappy)