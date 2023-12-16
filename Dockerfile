FROM ubuntu:22.04 as base

WORKDIR /workspace

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y \
# Install gcc and gdb for C++ developement
        build-essential gdb g++-12 \
# Install pip and latest cmake version for C++ developement
        pip && \
    pip install cmake --upgrade
    
COPY . .