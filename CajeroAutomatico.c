#include <stdio.h>
#include<string.h>

/* LISTA DE CLAVES A UTILIZAR 
Pin de Dolores: 6879
Pin de Fernando: 7069
Pin de Jose: 7479
Pin de Manuel: 7765
Pin de Sara: 8365 */

struct transferencia // Realizada por Claudia Pagani
{	
	int ncuenta[10];
	char beneficiario[50];
	float importe;	
};

struct datos // Realizada por Ana Sánchez
{
	char nombre[10],apellido[10];
	float saldo;
	int acceso;
};

typedef struct // Realizada por Belén Espeso
{
	char numero[9];
	char company[15];
	int cantidad;
	
}Recarga;

int menu(void);
struct datos LecturaDatosUsuarios(int pin);

int main()
{
	// Definicion de variables (cada una ha creado las variables que necesitaba)
	int i=0,k=0,l=0, o=0, pin, opcion,cartilla[10],option,dineroI,dineroS;
	int j=0,num=0,incorrecto=0; //Variables para la recarga del movil
	int movimientos[3]={0,0,0}; //tranferencia, ingresar, retirar
	int *m=movimientos,consulta; // Variables para la opcion de consulta
	float CantidadRetirar=0.0, CantidadIngresar=0.0; //Variables para ingresar o retirar dinero
	char respuesta[3], answer[]="NO",resp[2],comprobante[2];
	struct transferencia trans[6];
	struct datos cliente;
	Recarga rmovil,*r;
	r=&rmovil;
	
	system("color F5"); // Ponemos el fondo del programa blanco y las letras moradas
	printf("Bienvenido al Cajero ETSIDI.\n");
	printf("Introduzca el PIN:\n");
	scanf("%d", &pin);
	cliente=LecturaDatosUsuarios(pin); //LLamamos a la funcion que lee los datos de los cliente

if(cliente.acceso==0) //Si el acceso es 0 el cliente no ha introducido la clave correcta y por tanto no puede acceder al menu de opciones
	printf("Clave Incorrecta, acceso denegado\n");
else
{
	printf("BIENVENIDO/A "); // Realizado por Ana Sánchez
	while(cliente.nombre[k] != '\0')
	{
		printf("%c",cliente.nombre[k]);
		k++;
	}
	printf(" ");
	while(cliente.apellido[l] != '\0')
	{
		printf("%c",cliente.apellido[l]);
		l++;
	}
	do
	{
		
		opcion=menu(); //LLamamos a la funcion que muestra en pantalla el menu de opciones
		switch(opcion)
		{				
			case 1: // El numero 1 corresponde a la opcion de consulta realizada por Ana Sánchez
				do
				{
					printf("Seleccione una de estas opciones\n");
					printf("1-Saldo\n");
					printf("2-Movimientos\n");
					scanf("%d", &consulta);
					if(consulta == 1) 
					{
						printf("Tu saldo actual es: \n");
						printf("%.2f\n",cliente.saldo);
						if(cliente.saldo<0)
							printf("Debe usted dinero al banco\n");
					}
					else if(consulta==2)
					{
						printf("Ha realizado %i transferencias\n",*m);
						printf("Ha ingresado dinero %i veces\n",*(m+1));
						printf("Ha retirado dinero %i veces\n",*(m+2));
					}
				
				} while(consulta !=1 && consulta !=2); //Si el usuario introduce un numero que no sea 1 o 2 vuelve a pedirle que seleccione la opcion
			break;
				
			case 2: // El numero 2 corresponde a la opcion de transferencias realizada por Claudia Pagani
				do
				{
					printf("Introduzca el numero de cuenta al que desea realizar la tranferencia\n");
					scanf("%d",&trans[o].ncuenta);
					printf("Introduzca el nombre del beneficiario\n");
					for(i=0; i<50;i++);
						scanf("%s", trans[o].beneficiario);
						do
						{
							printf("Introduzca la cantidad que desea abonar\n");
				        	scanf("%f", &trans[o].importe);
							if(trans[o].importe>cliente.saldo)
								printf("No es posible realizar la transferencia, no tiene ese saldo en la tarjeta.\n");
						}while(trans[o].importe>cliente.saldo);
					
						printf("Operacion realizada con exito\n");
						*m+=1; //Añade una unidad al vector movimientos en el elemento 1º, que corresponde a las trasferencias 
						printf("Desea realizar otra transferencia (SI|NO)?\n");
						scanf("%s", respuesta);
						cliente.saldo-=trans[o].importe;
						o++;
					
				
				} while((strcmp(answer,respuesta) !=0) && o<6); //Si la respuesta introducida por el usuario es No o el numero de transferencias es mayor que 6 el bucle se cierra
				
				printf("Has llegado al limite de transferencias diarias.\n\n");
			break;
			
			case 3: // El numero 3 corresponde a la opcion de la cartilla realizado por Claudia Pagani y Belén Espeso
				
				printf("Introduzca el numero de la cartilla: \n");
				scanf("%d",&cartilla);
				do
				{
					printf("Pulse 1 si desea ingresar dinero\nPulse 2 si desea retirar dinero\n");
					scanf("%d",&option);
					switch(option)
					{
						case 1:
							printf("Indique la cantidad de dinero que desea ingresar:\n");
  			    			scanf("%d", &dineroI);
  			    			printf("Desea comprobante de la operacion (SI|NO)? \n");
  			    			scanf("%s",&comprobante);
  			    			if(comprobante == "SI")
  			    				printf("Recoja el recibo.\n");
						break;
					
						case 2:
							do
							{
								printf("Indique la cantidad de dinero que desea sacar:\n");
  			    				scanf("%d", &dineroS);
  			    				if(dineroS>600)
									printf("No se permite sacar mas de 600 EUROS.\n");
							}while(dineroS>600);
						break;
					}
					printf("Desea realizar otra operacion (SI|NO)? \n");
					fflush(stdin);
					gets(resp);
				}while(resp == "SI");
			break;
				
			case 4: //El numero 4 corresponde a la opcion recarga de movil realizada por Belén Espeso
				
				printf("A que operadora pertenece el telefono al que desea realizar la recarga\n");
				scanf("%s",r->company);
				do
				{
					printf("Introduzca el numero de telefono al que desea recargar el saldo.\n");
					scanf("%s",r->numero);
					num=strlen(r->numero);
					if(num<9 || num>9)		
						printf("El numero introducido no es correcto.\n"); 
					while(r->numero[j] != '\0')
					{
						if(r->numero[j]<'0' || r->numero[j]>'9')
							incorrecto=1;
						j++;
					}
				if(incorrecto==1)
					printf("El numero introducido no es valido.\n");	
				}while(num<9 || num>9 || incorrecto==1);				
				printf("Seleccione la cantidad que desea recargar.\n");
				printf("5 EUROS.\n");
				printf("10 EUROS.\n");
				printf("20 EUROS.\n");
				scanf("%d",&r->cantidad);
				printf("Recarga de %d realizada correctamente\n",r->cantidad);
			
			break;
		
			case 5: // El numero 5 corresponde a la opcion de retirar dinero realizada por Marta Romero
					printf("Introduzca la cantidad a retirar\n");
					scanf("%f", &CantidadRetirar);
					printf("Operacion realizada con exito\n");
					*(m+2)+=1; //Añade una unidad al vector movimientos en el elemento 3º, que corresponde a la cantidad retirada
					cliente.saldo-=CantidadRetirar;	
			break;
		
			case 6: // El numero 6 corresponde a la opcion de ingresar dinero realizada por Marta Romero
				printf("Introduzca la cantidad a ingresar\n");
				scanf("%f", &CantidadIngresar);
				printf("Operacion realizada con exito\n");
				*(m+1)+=1; //Añade una unidad al vector movimientos en el elemento 2º, que corresponde a los ingresos
				cliente.saldo+=CantidadIngresar;
			break;
					
		} 
	
	} while(opcion != 7);

}
return 0;
}

struct datos LecturaDatosUsuarios(int pin) // Realizada por todas las integrantes del grupo
{	
	int i=0,clave;
	char fichero[6];
	struct datos cliente;
	FILE *pf,*rf;
	pf=fopen("CLAVES.txt","r");  // Abrimos el fichero que tiene las claves y los ficheros de datos de cada cliente.
	if(pf == NULL)
	{
		printf("Error al abrir el fichero de claves\n");

	}
	else
	{
		while (fscanf(pf, "%d;%s", &clave,fichero) != EOF && clave != pin); // Recorre el fichero de claves y ficheros
	fclose(pf);
		if(clave==pin) 
		{
			rf=fopen(fichero,"r"); //Cuando el pin introducido coincide con alguna de las claves abre el fichero correspondiente a esa clave.
			if(rf == NULL)
			{
				printf("Error al abrir el fichero\n");
			}
			else
			{
				// Almacenamos los datos del fichero en una estructura llamada cliente.
				fscanf(rf,"%s\n%s\n%f",cliente.nombre,cliente.apellido,&cliente.saldo);
				fclose(rf);
				cliente.acceso=1; // Si el acceso es 1 el cliente puede acceder al menu de opciones
			}
		}
		else
			cliente.acceso=0;
	}
	return cliente;

}


// Esta funcion que imprime en pantalla el menu de opciones la hemos realizado todas las integrantes del grupo
int menu(void)
{
	int opcion;
	struct datos cliente;
	
	printf("\nSeleccione una opcion\n");
	printf("1 - Consulta\n");
	printf("2 - Transferencia\n");
	printf("3 - Introducir cartilla\n");
	printf("4 - Recargar movil\n");
	printf("5 - Retirar dinero de la cuenta\n");
	printf("6 - Ingresar dinero en la cuenta\n");
	printf("7 - Finalizar operacion\n");
	printf ("Opcion: ");
	scanf("%d", &opcion);

	return opcion;
}
