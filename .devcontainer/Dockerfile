FROM ubuntu:22.04

# Install dependencies
RUN apt update && apt -y install \
    build-essential \
    cmake \
    gcc-arm-none-eabi \
    libnewlib-arm-none-eabi \
    libstdc++-arm-none-eabi-newlib \
    git \
    python3 \
    python3-pip \
    python3-venv \
    clangd \
    && apt -y install \
    libusb-1.0-0-dev \
    pkg-config \
    && rm -rf /var/lib/apt/lists/*

# Clone the Pico SDK and set up the environment
WORKDIR /opt
RUN git clone -b master https://github.com/raspberrypi/pico-sdk.git --recurse-submodules
ENV PICO_SDK_PATH=/opt/pico-sdk

# Install picotool from source
RUN git clone https://github.com/raspberrypi/picotool.git && \
    cd picotool && \
    mkdir build && cd build && \
    cmake .. && \
    make && \
    make install

# Default work directory for the user
WORKDIR /workspace

# Default command to keep the container running
CMD ["/bin/bash"]
