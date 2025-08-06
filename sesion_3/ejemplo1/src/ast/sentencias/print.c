// ------------------ Nodo Tipo A ------------------
typedef struct {
    NodoBase base;
    // Atributos específicos
    int valorA;
} NodoTipoA;

void NodoTipoA_ejecutar(NodoBase* self, ctx* contexto) {
    NodoTipoA* nodo = (NodoTipoA*)self;

    printf("Ejecutando NodoTipoA: %s, valorA=%d\n", nodo->base.nombre, nodo->valorA);
}

void NodoTipoA_init(NodoTipoA* nodo, const char* nombre, int valorA) {
    NodoBase_init(&nodo->base, nombre, NodoTipoA_ejecutar);
    nodo->valorA = valorA;
}