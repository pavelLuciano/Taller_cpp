#include <fstream>
#include <portaudio.h>
#include <cmath>

typedef struct
{
    std::ofstream* file;
    std::ofstream* binFile;
    float buff[512];
} CallbackData;

static inline float max(float a, float b) {
    return a > b ? a : b;
}

static int patestCallback(
    const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer,
    const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags,
    void* userData
) {
    float* in = (float*)inputBuffer;
    (void)outputBuffer;

    int dispSize = 100;
    printf("\r");

    float vol_l = 0;
    float vol_r = 0;

    for (unsigned long i = 0; i < framesPerBuffer * 2; i += 2) {
        vol_l = max(vol_l, std::abs(in[i]));
        vol_r = max(vol_r, std::abs(in[i+1]));
    }

    for (int i = 0; i < dispSize; i++) {
        float barProportion = i / (float)dispSize;
        if (barProportion <= vol_l && barProportion <= vol_r) {
            printf("█");
        } else if (barProportion <= vol_l) {
            printf("▀");
        } else if (barProportion <= vol_r) {
            printf("▄");
        } else {
            printf(" ");
        }
    }
    fflush(stdout);
    return paContinue;
}

/////////////////////

const double SAMPLE_RATE = 44100.0;
const double FREQUENCY = 880.0; // Frecuencia de la onda (La4)
const int BUFFER_SIZE = 512; // Tamaño del buffer cíclico

// Estructura para manejar el buffer cíclico
struct CyclicBuffer {
    std::vector<float> buffer; // Datos del buffer
    int index;                // Índice actual del buffer

    CyclicBuffer(int size, double frequency, double sampleRate)
        : buffer(size), index(0) {
        // Inicializa el buffer con una onda sinusoidal
        for (int i = 0; i < size; ++i) {
            buffer[i] = static_cast<float>(std::sin(2.0 * M_PI * frequency * i / sampleRate));
        }
    }

    // Obtiene el siguiente valor del buffer cíclico
    float getNextSample() {
        float sample = buffer[index];
        index = (index + 1) % buffer.size();
        return sample;
    }
};

// Callback de PortAudio
static int audioCallback(const void* inputBuffer, void* outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo* timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void* userData) {
    // Recuperar el buffer cíclico desde userData
    auto* cyclicBuffer = static_cast<CyclicBuffer*>(userData);
    float* out = static_cast<float*>(outputBuffer);

    // Generar salida desde el buffer cíclico
    for (unsigned long i = 0; i < framesPerBuffer; ++i) {
        *out++ = cyclicBuffer->getNextSample();
    }

    return paContinue; // Continuar la ejecución del stream
}

