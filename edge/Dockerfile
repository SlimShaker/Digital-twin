FROM 192.168.1.217:5000/project-base

WORKDIR /app
COPY . .

RUN g++ edge/main.cpp edge/edge.cpp edge/edgeCallback.cpp logger/reporter.cpp \
    -Ilogger \
    -o edge_app \
    -lpaho-mqttpp3 -lpaho-mqtt3as

CMD ["./edge_app"]