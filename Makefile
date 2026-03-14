CXX = g++
CXXFLAGS = -std=c++17 -I./
LDFLAGS =

SRC = main.cpp \
      include/logic/TarkaShastra.cpp \
      include/logic/NyayaSutras.cpp \
      include/DivineMaster.cpp \
      include/memory/YogaSutras.cpp \
      include/memory/ChittaBuffer.cpp \
      include/memory/Puranas.cpp \
      include/memory/GarudaShredder.cpp \
      include/memory/AkashicRecords.cpp \
      include/core/Samyama.cpp \
      include/core/SpandaKarikas.cpp \
      include/core/ShaktiPeethas.cpp \
      include/core/BinduSingularity.cpp \
      include/core/Antahkarana.cpp \
      include/core/Arthashastra.cpp \
      include/core/Hiranyagarbha.cpp \
      include/core/AgamaShastras.cpp \
      include/core/AntahkaranaEngine.cpp \
      include/core/VastuShastra.cpp \
      include/core/ShilpaShastras.cpp \
      include/core/TheYugas.cpp \
      include/core/MimamsaSutras.cpp \
      include/core/Rigveda.cpp \
      include/core/ShatDarshanas.cpp \
      include/core/Jyotisha.cpp \
      include/core/BhagavadGita.cpp \
      include/core/BrahmaShivaSutras.cpp \
      include/core/SamkhyaSutras.cpp \
      include/core/VarnaAshrama.cpp \
      include/core/MandukyaUpanishad.cpp \
      include/core/DivineKernel.cpp \
      include/core/MahaVakyas.cpp \
      include/core/PanchaMahabhuta.cpp \
      include/core/IndrasNet.cpp \
      include/core/SushrutaSamhita.cpp \
      include/core/MayaHypervisor.cpp \
      include/core/KalaChakra.cpp \
      include/core/Purusharthas.cpp \
      include/core/CharakaSamhita.cpp \
      include/core/GarbhaUpanishad.cpp \
      include/core/UpanishadBase.cpp \
      include/core/PranaNadis.cpp \
      include/core/Kundalini.cpp \
      include/core/MokshaProtocol.cpp \
      include/core/KashyapaSamhita.cpp \
      include/security/TantricYantras.cpp \
      include/security/PanchaKoshaKernel.cpp \
      include/security/DharmaIAM.cpp \
      include/security/Dhanurveda.cpp \
      include/security/Astras.cpp \
      include/io/PranaRouter.cpp \
      include/io/Pratishakhyas.cpp \
      include/io/GandharvaVeda.cpp \
      include/io/PaniniNLP.cpp \
      include/nlp/NatyaShastra.cpp \
      include/nlp/KamaSutra.cpp \
      include/nlp/Vak.cpp \
      include/nlp/VigyanBhairavTantra.cpp \
      include/nlp/PaniniAshtadhyayi.cpp \
      include/nlp/Shiksha.cpp \
      include/nlp/Nirukta.cpp \
      include/compute/SriYantraTensor.cpp \
      include/compute/SuryaSiddhanta.cpp \
      include/compute/ParavartyaLogic.cpp \
      include/compute/VedicMatrix.cpp \
      include/compute/NikhilamMath.cpp \
      include/compute/YogaAttention.cpp \
      include/compute/Ekadhikena.cpp \
      include/compute/BuddhiLogic.cpp \
      include/compute/VedicUpaSutras.cpp \
      include/compute/PingalaChandaSutras.cpp \
      include/compute/SulbaSutras.cpp \
      include/compute/ShunyamAnyat.cpp \
      src/batch1_reg.cpp \
      src/batch2_reg.cpp \
      src/batch3_reg.cpp \
      src/batch4_reg.cpp \
      src/batch5_reg.cpp \
      src/batch6_reg.cpp \
      src/global_reg.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = divine_kernel

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
