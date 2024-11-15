#include <iostream>
#include <portaudio.h>

int main() {
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        std::cerr << "ERROR AL INICIAR:\n" << Pa_GetErrorText(err) << std::endl;
        return 1;
    }

    std::cout << "PortAudio inicializado correctamente!\n";

    Pa_Terminate();
    return 0;
}
