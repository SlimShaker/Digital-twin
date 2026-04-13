FROM gcc:12

WORKDIR /app

COPY . .

RUN g++ edge/main.cpp edge/edge.cpp common/digital_human.cpp -o edge

CMD ["./edge"]