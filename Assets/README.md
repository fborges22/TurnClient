# To build the Container please do this:

```
docker build -t coturn-server .
docker run -p 3478:3478/udp -p 3478:3478/tcp -p 5349:5349/tcp -p 49152-65535:49152-65535/udp --name turn coturn-server
```