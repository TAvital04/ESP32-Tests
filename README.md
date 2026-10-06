# ESP IDF Tests
A playground for testing the ESP IDF

## DEVS

### Enter the Docker Container (Linux)
```bash
docker build -t esp-idf .
docker run -it --rm \
    --device=/dev/[FLASHING PORT] \
    -v $(pwd):/app \
    -w /app \
    esp-idf:latest /bin/bash
```
There are no plans for switching to Docker Compose at the moment
