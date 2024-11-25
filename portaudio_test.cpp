#include <iostream>
#include <portaudio.h>
#include <cstring>
#include "funciones.h"
#include "callbacks.h"

int main() {
    PaError err = Pa_Initialize();
    checkErr(err);

    int device = select_device();

    PaStreamParameters inputParameters;
    PaStreamParameters outputParameters;
    memset(&inputParameters, 0, sizeof(inputParameters));
    inputParameters.device = device;
    inputParameters.channelCount = 1;
    inputParameters.hostApiSpecificStreamInfo = NULL;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(device)->defaultLowInputLatency;
    
    memset(&outputParameters, 0, sizeof(outputParameters));
    outputParameters.device = device;
    outputParameters.channelCount = 4;
    outputParameters.hostApiSpecificStreamInfo = NULL;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(device)->defaultLowOutputLatency;


    err = Pa_Terminate();
    checkErr(err);
    return 0;
}
