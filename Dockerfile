# Pick the exact chip or IDF release you need (e.g., v5.3, v5.2)
FROM espressif/idf:v5.3

LABEL name="esp32-tests"

WORKDIR /usr/proj
COPY ./ ./

# Ready to compile immediately:
# idf.py build