FROM arm64v8/ubuntu:latest AS builder
RUN apt-get update -y \
  && apt-get upgrade -y \
  && apt-get install -y \
    build-essential \
    python3-dev

# Set the working directory inside the container
WORKDIR /app

# Copy the CMake project files into the container
COPY . /app

RUN g++ -o main.exe main.cpp -I/usr/include/python3.10 -lpython3.10
CMD ["/app/main.exe multiply multiply 2 3"]