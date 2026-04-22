FROM gcc:12

WORKDIR /app

RUN apt-get update && apt-get install -y \
    tzdata \
    cmake \
    git \
    libssl-dev \
    libpaho-mqtt-dev \
    libpaho-mqttpp-dev \
    nlohmann-json3-dev

    ENV TZ=Europe/Stockholm

COPY . .

RUN g++ fog/fog2/main.cpp fog/fog.cpp fog/fogCallBack.cpp common/digital_human.cpp logger/reporter.cpp \
    -Icommon \
    -o fog2 \
    -lpaho-mqttpp3 -lpaho-mqtt3as

CMD ["./fog2"]