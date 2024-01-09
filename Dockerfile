FROM gcc:latest

WORKDIR /usr/src/pb8reg

COPY . .

RUN g++ -o pb8reg 8reg.cpp

CMD ["./pb8reg"]