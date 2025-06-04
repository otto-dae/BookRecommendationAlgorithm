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
RUN  g++ src/BookList.cpp src/DBConn.cpp src/DBFunctions.cpp src/GeneralFunctions.cpp src/GenreList.cpp src/SubGenreList.cpp  main.cpp -o main -lpqxx -lpq

#Default command 
CMD ["./main"]