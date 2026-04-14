FROM gcc:12

WORKDIR /app

RUN apt-get update && apt-get install -y \
    cmake \
    git \
    libssl-dev \
    libpaho-mqtt-dev \
    libpaho-mqttpp-dev \
    nlohmann-json3-dev

COPY . .

RUN g++ edge/main.cpp edge/edge.cpp common/digital_human.cpp \
    -Icommon \
    -o edge_prog \
    -lpaho-mqttpp3 -lpaho-mqtt3as

CMD ["./edge_prog"]