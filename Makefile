all:
	g++ -o KrishiVeda Krishi-Veda-Module/KrishiVeda.cpp Krishi-Veda-Module/vedic_engine/vedic_engine.cpp Krishi-Veda-Module/vedic_engine/marketplace.cpp

server:
	g++ -pthread -o server server.cpp AIAgent.cpp Tokenizer.cpp

clean:
	rm KrishiVeda
