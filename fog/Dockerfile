FROM gcc:12

WORKDIR /app

COPY . .

RUN g++ fog/main.cpp fog/fog.cpp common/digital_human.cpp -o fog

CMD ["./fog"]