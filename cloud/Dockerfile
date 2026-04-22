FROM project-base
WORKDIR /app
COPY . .
RUN g++ cloud/main.cpp cloud/cloud.cpp cloud/cloudCallBack.cpp logger/reporter.cpp \
    -Icommon -Ilogger \
    -o cloud_app \
    -lpaho-mqttpp3 -lpaho-mqtt3as

CMD ["./cloud_app"]