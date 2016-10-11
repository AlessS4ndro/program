#include <stdio.h>

struct agenda {
	char nombre[20];
	char telefono[12];
	struct agenda *siguiente;
	};

struct agenda *primero ,*ultimo;

void mostrar_menu() {
	printf("\n\nMenu:\n=====\n\n");
	printf("1,- Bienvenido\n");
	printf("2.- Añadir elementos\n");
	printf("3.- Mostrar lista\n");
	printf("4.- Salir\n\n");
	printf("Escoge una opcion: ");fflush(stdout);
}

void anadir_elemento(){
	struct agenda *nuevo;

	nuevo=(struct agenda *) malloc (sizeof(struct agenda));
	if (nuevo == NULL) printf("No hay memoria disponible!\n");

	printf("\nNuevo elemento: \n"),
	printf("Nombre : ");fflush(stdout);
	gets(nuevo->nombre);
	printf("Telefono :");fflush(stdout);
	gets(nuevo->telefono);

	nuevo->siguiente=NULL;

	if(primero==NULL){
		printf("Primer elemento \n");
		primero=nuevo;
		ultimo=nuevo;
	}
	else{
		ultimo->siguiente=nuevo;
		ultimo=nuevo;

	}

}

void mostrar_lista(){
	struct agenda *auxiliar;
	int i;
	i=0;
	auxiliar =primero;
	printf("\nMostrando la lista completa:\n");
	while(auxiliar!=NULL){
		printf("Nombre: %s; Telefono: %s\n",auxiliar->nombre,auxiliar->telefono);
		auxiliar=auxiliar->siguiente;
		i++;
	}
	if(i==0) printf("\n La lista esta vacia!!\n");
}

int main()
{
	char opcion;

	primero=(struct agenda *)NULL;
	ultimo=(struct agenda *)NULL;
	do{
		mostrar_menu();
		opcion=getch();
			switch (opcion){
				case '2':anadir_elemento();
					break;
				case '3':mostrar_lista(primero);
					break;
				case '4': exit(1);
				default: printf("Opcion no valida\n");
					break;
			}
	}
	while(opcion!='4');
}
