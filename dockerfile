FROM gcc:13-bookworm

#Install pqxx, cmake nad make
RUN apt-get update && apt-get install -y \
    libpq-dev \
    libpqxx-dev \
    cmake \
    make \
    && rm -rf /var/lib/apt/lists/*

#Create app
WORKDIR /app

#Copy code
COPY . .

# Build on image make
RUN g++ src/*.cpp -Iheaders -lpqxx -lpq -o main

#Default command 
CMD ["./main"]