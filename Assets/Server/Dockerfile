FROM ubuntu:22.04

# Install CoTURN
RUN apt-get update && apt-get install -y coturn && rm -rf /var/lib/apt/lists/*

# Copy configuration file
COPY turnserver.conf /etc/turnserver.conf

# Expose default STUN/TURN ports
EXPOSE 3478/udp
EXPOSE 3478/tcp
EXPOSE 5349/tcp
EXPOSE 49152-65535/udp

# Run coturn with specified configuration
CMD ["turnserver", "-c", "/etc/turnserver.conf", "--no-daemon"]
