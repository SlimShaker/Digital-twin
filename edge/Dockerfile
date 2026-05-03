FROM project-base

WORKDIR /app
COPY . .

RUN g++ edge/main.cpp edge/edge.cpp logger/reporter.cpp \
    -Ilogger \
    -o edge_app \
    -lpaho-mqttpp3 -lpaho-mqtt3as

CMD ["./edge_app"]