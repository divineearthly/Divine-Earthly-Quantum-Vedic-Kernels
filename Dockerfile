FROM gcc:latest

# Set the working directory
WORKDIR /app

# Copy local code to the container
COPY . .

# Install dependencies and compile
RUN make clean && make

# Set default execution command
CMD ["./vedic_engine"]
