FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libboost-system-dev \
    libturnclient-dev \
    && rm -rf /var/lib/apt/lists/*

# Create app directory
WORKDIR /app

# Copy source files
COPY . .

# Build the application
RUN mkdir build && cd build && \
    cmake .. && \
    make

# Default command (override with CMD as needed)
CMD ["/bin/bash"]
