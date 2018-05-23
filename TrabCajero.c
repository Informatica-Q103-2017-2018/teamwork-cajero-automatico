#include <stdio.h>
#include<string.h>

int menu(void);

struct datos LecturaDatosUsuarios(int pin);

struct datos
{
	char nombre[50], apellido[50], localidad[50];
	int edad;
	float saldo;
	int acceso;
	
};

int main()
{
	// Definicion de variables
	int i, o=0, pin, opcion, consulta,cartilla[10],option,dineroI,dineroS;

	char respuesta[3], answer[]="NO",resp[2];
	struct datos cliente;
	
	
	printf("Bienvenido al Cajero ETSIDI.\n");
	printf("Introduzca el PIN:\n");
	scanf("%d", &pin);
	cliente=LecturaDatosUsuarios(pin); 

if(cliente.acceso==0) 
	printf("Clave Incorrecta, acceso denegado\n");
else
{
	do
	{
		opcion=menu(); 
		switch(opcion)
		{				
			case 1:
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
					
				
				} while(consulta !=1 && consulta !=2); 
			break;
				
			case 2: 
			
			break;
			
			case 3: 
				
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
						break;
					
						case 2:
							printf("Indique la cantidad de dinero que desea sacar:\n");
  			    			scanf("%d", &dineroS);
						break;
					}
					printf("Desea realizar otra operacion (SI|NO)? \n");
					fflush(stdin);
					gets(resp);
				}while(resp == "SI");
				
				
				
			
			break;
		
			case 4: 
			
			break;
		
			case 5: 
			break;
					
		} 
	
	} while(opcion != 6 );

}
return 0;
}

struct datos LecturaDatosUsuarios(int pin)
{	
	int i=0,clave;
	char fichero[6];
	struct datos cliente;
	FILE *pf,*rf;
	pf=fopen("CLAVES.txt","r");  
	if(pf == NULL)
	{
		printf("Error al abrir el fichero de claves\n");

	}
	else
	{
		while (fscanf(pf, "%d;%s", &clave,fichero) != EOF && clave != pin); 
	fclose(pf);
		if(clave==pin) 
		{
			rf=fopen(fichero,"r"); 
			if(rf == NULL)
			{
				printf("Error al abrir el fichero\n");
		
			}
			else
			{
				
				fscanf(rf,"%s\n%s\n%d\n%s\n%f\n",cliente.nombre, cliente.apellido , &cliente.edad, cliente.localidad, &cliente.saldo);
				
				fclose(rf);
				cliente.acceso=1; 
			}
		}
		else
			cliente.acceso=0;
	}
	return cliente;

}



int menu(void)
{
	int opcion;
	struct datos cliente;
	
	printf("Seleccione una opcion\n");
	printf("1 - Consulta\n");
	printf("2 - Transferencia\n");
	printf("3 - Introducir cartilla\n");
	printf("4 - Retirar dinero\n");
	printf("5 - Ingresar dinero\n");
	printf("6 - Finalizar operacion\n");
	printf ("Opcion: ");
	scanf("%d", &opcion);
	system("cls");
	return opcion;
}
