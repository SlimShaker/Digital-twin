FROM gcc:13

WORKDIR /app

RUN apt-get update && apt-get install -y \
    cmake \
    libssl-dev \
    libmosquitto-dev

RUN git clone https://github.com/eclipse/paho.mqtt.cpp.git && \
    cd paho.mqtt.cpp && \
    cmake -Bbuild -H. -DPAHO_WITH_SSL=ON && \
    cmake --build build/ --target install

COPY . .

RUN g++ -std=c++17 \
    main.cpp twin.cpp twinCallback.cpp \
    -o twin \
    -lpaho-mqttpp3 -lpaho-mqtt3as

CMD ["./twin"]