FROM project-base
WORKDIR /app
COPY . .
RUN g++ fog/main.cpp fog/fog.cpp fog/fogCallBack.cpp common/digital_human.cpp logger/reporter.cpp \
    -I../common -I../logger \
    -o fog_app \
    -lpaho-mqttpp3 -lpaho-mqtt3as

CMD ["./fog_app"]