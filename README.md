# Taller básico de C++ para captura de audio
El Taller tiene como objetivo proporcionar una introducción a la captura de audio en C++ utilizando la biblioteca de PortAudio.

A continuación de detallan los pasos necesarios para preparar un entorno de trabajo de `c++` en **Windows** y **Linux** _(Recomendado)_.


### Windows

En caso de **Windows** vamos a utilizar _Windows Subsystem for Linux_


1. **Abrir una consola de comandos**:

     En el buscador de windows , escribe `cmd` o `PowerShell` y ejecuta como **administrador**.

2. **Instalar WSL**:

     En CMD o PowerShell, ejecuta el siguiente comando para instalar WSL:
    ```
    wsl --install
    ```
3. **Elegir la distribución de Linux**:

     Elige una distribución de Linux para instalar. Pueder listar las distribuciones disponibles con el siguiente comando:
    ```
    wsl --list --online
    ```
    Instala la distribución elegida con el siguiente comando:
    
    ```
    wsl --install -d <nombre_de_la_distribucion>
    ```
    Se recomienda instalar la version más nueva de **Ubuntu**.
    
    
    - **Nota**: 
        - Es posible que se te pida reinicar el equipo.
        - Si los comandos no funcionan, prueba reemplarar S`wsl` con `wsl.exe`.

4. **Configurar el entorno de trabajo**:

    Ahora desde la consola puedes iniciar tu sub-sistema escribiendo `wsl` en la consola de windows.

    Sigue las instrucciones correspondientes a la distribución de **Linux** que escogiste.

---

### Ubuntu / Debian

En el caso de las distribuciones basadas en **Debian** es probable que tengas un compilador y herramientas de desarrollo instaladas por defecto.

Prueba comprobar si tienes los recursos necesarios para el tallero con los siguietes comandos:
```bash
g++ --version
make --version
```
Si no los tienes instalados puedes eguir los siguientes pasos:

 1. **Actualizar Paquetes**:

    Actualiza los repositorios:

    ```bash
    sudo apt update
    sudo apt upgrade -y
    ```

 2. **Instalar las herramientas necesarias**:
    
    Instala el compilador `g++` y `make` :
    ```bash
    sudo apt install g++ -y
    sudo apt install make -y
    ```
Verifica nuevamente consultando la version de `g++` y `make`.



---

### Arch

Para sistemas basados en **Arch**, como **Manjaro** o **Arch Linux** puedes seguir los siguietes pasos:

 1. **Actualizar repositorios**:

    Actualiza los repositorios de tu sistema
    ```
    sudo pacman -Syu
    ```

2. **Instalar las herramientas**:

    Este comando instalará automaticamente las herramientas básica de desarrollo:
    ```
    sudo pacman -S base-devel
    ```
3. **Verifica la instalacion**:
    Puedes verificar la instalación escribiendo:
    ```bash
    g++ --version
    make --version
    ```

---

## Visual Studio Code

Para este taller se puede utilizar cualquier editor de texto, pero se recomienda utilizar **Visual Studio Code** (VS Code) debido a su ligereza y versatilidad.

Puedes descargar **Visual Studio Code** en su [aquí](https://code.visualstudio.com/Download).

Se recomienda instalar la extension **C/C++ Intelisense** para trabajar mas comodamente.



---
# Manos a la Obra

Ahora ya debería estar todo preparado para programar en C++.

Encontrarás en este mismo repositorio un archivo _"HolaMundo.cpp"_ y un archivo _"Makefile"_. Estos archivos contienen un ejemplo básico de un programa en C++ que imprime un mensaje en consola.
Puedes probar si todo está correctamente instalado escribiendo los siguientes comandos en tu consola:
```bash
make hola
./holamundo
```


## PortAudio

En este taller usaremos PortAudio como librería para gestionar la entrada y salida de audio. Puedes instalar PortAudio en tu sistema siguiendo mediante los siguientes comandos:

### Para WSL y Sistemas Debian (como Ubuntu) 
```
sudo apt install portaudio19-dev -y
```

Luego verifica con:
```
dpkg -s portaudio19-dev
```

### Para sistemas basados en Arch
```
sudo pacman -S portaudio
```
Y compruba la instalación con:
```
pacman -Qi portaudio
```

En este repositorio encintrarás un archivo _"portaudio_test.cpp"_ con el que puedes probar si PortAudio está
funcionando correctamente. Solo escribe en tu consola de comandos:
```
make portaudio
./pa_test
```

Ahora ya estás listo para participar en el **Taller**!! 
