#include <iostream>
#include <portaudio.h>
#include <fstream>

static inline void checkErr(PaError err)
{
    if (err != paNoError)
    {
        std::cout << "ERROR: " << Pa_GetErrorText(err) << std::endl;
        exit(EXIT_FAILURE);
    }      
}

void writeToFile(std::ofstream &file, int value, int size)
{
    file.write(reinterpret_cast<const char*>(&value), size);
}

int select_device()
{
    int numDevices = Pa_GetDeviceCount();
    if (numDevices < 0)
    {
        std::cout << "ERROR OBTENIENDO DISPOSITIVOS\n";
        return 0;
    }else if (numDevices == 0)
    {
        std::cout << "NO HAY DISPOSITIVOS DISPONOBLES\n";
        return 0;;
    }

    const PaDeviceInfo* deviceInfo;

    for (int i = 0; i < numDevices; i++)
    {
        deviceInfo = Pa_GetDeviceInfo(i);
        std::cout << "      Device: " << i << "\n";
        std::cout << "        name: " << deviceInfo->name <<"\n";
        std::cout << "  maxInpChnl: " << deviceInfo->maxInputChannels <<"\n";
        std::cout << "  maxoutchnl: " << deviceInfo->maxOutputChannels <<"\n";
        std::cout << "defLowInpLat: " << deviceInfo->defaultLowInputLatency <<"\n";
        std::cout << "defLowOutLat: " << deviceInfo->defaultLowOutputLatency <<"\n";
        std::cout << " defHiInpLat: " << deviceInfo->defaultHighInputLatency <<"\n";
        std::cout << " defHiOutLat: " << deviceInfo->defaultHighOutputLatency <<"\n";
        std::cout << " defSampRate: " << deviceInfo->defaultSampleRate <<"\n";
        std::cout << "-------------------------------------------------------\n";
    }

    int device;
    std::cout << "SELECCIONE EL DISPOSITIVO: ";
    std::cin >> device;
    return device;
}
