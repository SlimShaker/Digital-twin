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

RUN g++ cloud/main.cpp cloud/cloud.cpp cloud/cloudCallBack.cpp logger/reporter.cpp \
    -Icommon -Ilogger \
    -o cloud_app \
    -lpaho-mqttpp3 -lpaho-mqtt3as

CMD ["./cloud_app"]