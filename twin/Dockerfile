FROM project-base:latest

WORKDIR /app
COPY . .

RUN g++ twin/main.cpp twin/twin.cpp twin/twinCallback.cpp \
    -Itwin \
    -o cloud_app \
    -lpaho-mqttpp3 -lpaho-mqtt3as

CMD ["./cloud_app"]