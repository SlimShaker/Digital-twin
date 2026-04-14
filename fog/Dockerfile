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

RUN g++ fog/main.cpp fog/fog.cpp fog/fogCallBack.cpp common/digital_human.cpp \
    -Icommon \
    -o fog_prog \
    -lpaho-mqttpp3 -lpaho-mqtt3as

CMD ["./fog_prog"]