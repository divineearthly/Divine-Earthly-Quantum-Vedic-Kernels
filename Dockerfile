FROM ubuntu:22.04

RUN apt-get update && apt-get install -y g++ make

WORKDIR /app

COPY . .

RUN make server

EXPOSE 8080

CMD ["./server"]
