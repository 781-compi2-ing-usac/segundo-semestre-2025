# Ejemplo de GTK3

## instalacion
https://docs.gtk.org/gtk3/building.html
ubuntu
~~~
sudo apt install pkg-config libgtk-3-dev
~~~

## Ejecución

~~~
gcc `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0`
~~~