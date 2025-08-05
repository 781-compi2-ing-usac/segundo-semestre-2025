// ------------------ Nodo Tipo B ------------------
typedef struct {
    NodoBase base;
    // Atributos específicos
    char mensaje[100];
} NodoTipoB;

void NodoTipoB_ejecutar(NodoBase* self) {
    NodoTipoB* nodo = (NodoTipoB*)self;
    printf("Ejecutando NodoTipoB: %s, mensaje='%s'\n", nodo->base.nombre, nodo->mensaje);
}

void NodoTipoB_init(NodoTipoB* nodo, const char* nombre, const char* mensaje) {
    NodoBase_init(&nodo->base, nombre, NodoTipoB_ejecutar);
    snprintf(nodo->mensaje, sizeof(nodo->mensaje), "%s", mensaje);
}