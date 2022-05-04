/*******************************************************************************
Alumno 1: Leiro Arroyo, Guillermo       Alumno 2: de la Puente Rivera, Francisco
Grupo: 34                               Fecha: 29/11/2017
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAXPRODUCTOS 500

/***************************************

    ESTRUCTURA

    Explicacion flag: A la hora de gestionar los datos de los productos en nuestro programa hemos optado por esta variable la cual funciona como un boleean
                        indicandonos si los datos de esa estructura corresponden a un producto dado de alta o son basura y se pueden sobre escribir.
***************************************/
typedef struct{

    int flag;
    char codigo[6];
    char nombre[21];
    float precio_compra;
    float precio_venta;
    unsigned int stock_actual;
    unsigned int stock_min;
    unsigned int stock_max;
    unsigned int total_compradas;
    unsigned int total_vendidas;
    char ultima_compra[11];
    char ultima_venta[11];

}item;

/***************************************

    PROTOTIPOS

***************************************/

void MensajeError();

void MenuMantenimiento(item productos[],float matriz_compras[][MAXPRODUCTOS],float matriz_ventas[][MAXPRODUCTOS]);

void AltaProducto(item productos[],float matriz_compras[][MAXPRODUCTOS],float matriz_ventas[][MAXPRODUCTOS]);
void BajaProducto(item productos[]);
void ModificacionProducto(item productos[]);
void ConsultaProducto(const item productos[]);
void CompraProductos(item productos[],float matriz_compras[][MAXPRODUCTOS]);
void VentaProductos(item productos[],float matriz_ventas[][MAXPRODUCTOS]);
void CapitalizarNombreProductos(item productos[]);
int date_check(const char date[]);

void MenuInformes(float matriz_ventas[][MAXPRODUCTOS], item productos[], float matriz_compras[][MAXPRODUCTOS]);

void ListadoGeneral(item productos[]);
void ListadoGeneralSimplificado(item productos[]);
void ListadoProductosConStockMinimo(item productos[]);
void ListadoComprasMes(item productos[], float matriz_compras[][MAXPRODUCTOS]);
void ListadoVentasProducto(item productos[],float matriz_ventas[][MAXPRODUCTOS]);
void ProductoMasCompradoMes(item productos[], float matriz_compras[][MAXPRODUCTOS]);
void MesMenosVentas(float matriz_ventas[][MAXPRODUCTOS]);
void VentaTotalMes(float matriz_ventas[][MAXPRODUCTOS]);
void VentaTotalProducto(item productos[], float matriz_ventas[][MAXPRODUCTOS]);
void VentaTotalAnno(float matriz_ventas[][MAXPRODUCTOS]);
void ImporteMedioVentasMesesPares(float matriz_ventas[][MAXPRODUCTOS]);
void ContarProductosMesUltimaVenta(float matriz_ventas[][MAXPRODUCTOS], item productos[]);
/***************************************

    FUNCION PRINCIPAL

Tipo: Procedimiento

Objetivo: Declarar las variables que usaremos para almacenar los datos de la empresa a lo largo del programa.

***************************************/
int main(){

    item productos[MAXPRODUCTOS];

    int i;
    int opcion;
    int y,g;

    float matriz_compras[12][MAXPRODUCTOS];
    float matriz_ventas[12][MAXPRODUCTOS];

    setlocale(LC_CTYPE, "Spanish");

    /** INICIALIZACI�N VECTOR REGISTRO **/

    for(i=0;i<MAXPRODUCTOS;i++)
        productos[i].flag=0;


    for(g=0;g<12;g++){

        for(y=0;y<MAXPRODUCTOS;y++){

            matriz_compras[g][y]=g+1;
            matriz_ventas[g][y]=g+1;

        }

    }



    do{

        system("cls");

        printf("\n\tMEN� PRINCIPAL");
        printf("\n\n\t1 - Mantenimiento");
        printf("\n\t2 - Informes");
        printf("\n\n\t0 - Salir");
        printf("\n\t_____________________________________");
        printf("\n\n\tElija opci�n: ");
        fflush(stdin);
        scanf("%i", &opcion);

        switch(opcion){

            case 1:
                    MenuMantenimiento(productos,matriz_compras,matriz_ventas);
                    break;
            case 2:
                    MenuInformes(matriz_ventas, productos, matriz_compras);
                    break;
            case 0:
                    break;
            default:
                    MensajeError();
                    break;

        }

    }while(opcion != 0);

    system("cls");

    printf("\n\tGracias por utilizar la aplicaci�n.");
    printf("\n\n\tPulse Intro para finalizar.");
    fflush(stdin);
    getchar();

    return 0;

}

/***********************************************************************************
Subprograma: MensajeError      Tipo: Procedimiento
Prerrequisitos:
Objetivo: Mostrar un mensaje de error en caso de que se escoga una opci�n no valida.
***********************************************************************************/
void MensajeError(){

    system("cls");

    printf("\n\tIntroduzca una opci�n correcta.");
    printf("\n\n\tPulse Intro para continuar...");
    fflush(stdin);
    getchar();

}

/***************************************
Subprograma: Menu mantenimiento      Tipo: Procedimiento
Prerrequisitos: Precisas de ambas matrices tanto la de compra como la de ventas ademas de el vector de la estructura para almacenaje de productos.
Objetivo: Estructurar de mejor manera el codigo en y realizacion de su funcion principal; mostar y seleccionar cual sera el siguiente paso en el programa.
***************************************/
void MenuMantenimiento(item productos[],float matriz_compras[][MAXPRODUCTOS],float matriz_ventas[][MAXPRODUCTOS]){

    int opcion;

    do{

        system("cls");
        printf("\n\tMEN� MANTENIMIENTO");
        printf("\n\n\t1 - Alta de un producto.");
        printf("\n\t2 - Baja de un producto");
        printf("\n\t3 - Modificaci�n de los datos de un producto");
        printf("\n\t4 - Consulta de los datos de un producto");
        printf("\n\t5 - Compra de productos");
        printf("\n\t6 - Venta de productos");
        printf("\n\t7 - Capitalizar nombres de productos");
        printf("\n\n\t0 - Volver al Men� Principal");
        printf("\n\t___________________________________________________________");
        printf("\n\n\tElija opci�n: ");
        fflush(stdin);
        scanf("%i", &opcion);

        switch(opcion){

            case 1:
                AltaProducto(productos,matriz_compras,matriz_ventas);
                    break;
            case 2:
                BajaProducto(productos);
                    break;
            case 3:
                ModificacionProducto(productos);
                    break;
            case 4:
                ConsultaProducto(productos);
                    break;
            case 5:
                CompraProductos(productos,matriz_compras);
                    break;
            case 6:
                VentaProductos(productos,matriz_ventas);
                    break;
            case 7:
                CapitalizarNombreProductos(productos);
                    break;
            case 0:
                    break;
            default:
                    MensajeError();
                    break;

        }


    }while(opcion != 0);

}

/***************************************
Subprograma: Alta de producto      Tipo: Procedimiento
Prerrequisitos: Ambas matrices(compras y ventas) y vector estructura.
Objetivo: Ingresar un nuevo producto al programa: busca un espacio en el string que este vacio; lo rellena con los datos del producto; y a continuacion inicializa
            los espacios de las matrices correspondientes a este nuevo producto a cero.
***************************************/
void AltaProducto(item productos[],float matriz_compras[][MAXPRODUCTOS],float matriz_ventas[][MAXPRODUCTOS]){

    int f, i, copias;
    char save,exit;


     do{

        //espacio de almacenamiento libre
        for(f=0,i=1;(i==1)&&(f<=MAXPRODUCTOS);f++){

            i=productos[f].flag;

        }

        f--;

        if((f+1)>MAXPRODUCTOS){

            printf("\n\n\tNo hay espacio en el almacen, libere alguno de los %i productos registrados.\n\n\t",MAXPRODUCTOS);
            system("pause");

        }else{

            do{

                do{

                    system("cls");
                    printf("\n\n\t ALTA DE UN PRODUCTO");
                    printf("\n\n Introduzca el codigo del producto: ");

                    fflush(stdin);
                    productos[f].codigo[0]=toupper(getch());
                    printf("%c",productos[f].codigo[0]);
                    printf("-");
                    productos[f].codigo[1]='-';
                    fflush(stdin);
                    productos[f].codigo[2]=getch();
                    printf("%c",productos[f].codigo[2]);
                    fflush(stdin);
                    productos[f].codigo[3]=getch();
                    printf("%c",productos[f].codigo[3]);
                    fflush(stdin);
                    productos[f].codigo[4]=getch();
                    printf("%c",productos[f].codigo[4]);
                    productos[f].codigo[5]='\0';

                }while((65>productos[f].codigo[0]&&productos[f].codigo[0]<90)||(48>productos[f].codigo[2]||productos[f].codigo[2]>57)||(48>productos[f].codigo[3]||productos[f].codigo[3]>57)||(48>productos[f].codigo[4]||productos[f].codigo[4]>57));


               //comprovacion no copia de producto
                for(i=0,copias=0;(i<MAXPRODUCTOS)&&(copias==0);i++){

                    if((productos[i].flag==1)&&(strcmp(productos[f].codigo,productos[i].codigo)==0)){

                        copias++;
                        printf("\n\n\tEl producto introducido ya existe.\n\n");
                        system("pause");

                    }

                }

            }while(copias>0); //&& productos[i].flag==1

            printf("\n\n Introduzca el nombre del producto: ");
            fgets(productos[f].nombre,21,stdin);

            printf("\n Introduzca el precio de compra: ");
            scanf("%f",&productos[f].precio_compra);

            printf("\n Introduzca el precio de venta: ");
            scanf("%f",&productos[f].precio_venta);

            printf("\n Introduzca el stock actual: ");
            scanf("%i",&productos[f].stock_actual);

            printf("\n Introduzca el stock minimo: ");
            scanf("%i",&productos[f].stock_min);

            printf("\n Introduzca el stock maximo: ");
            scanf("%i",&productos[f].stock_max);

            printf("\n Introduzca el total de unidades compradas: ");
            scanf("%i",&productos[f].total_compradas);

            printf("\n Introduzca el total de unidades vendidas: ");
            scanf("%i",&productos[f].total_vendidas);

            //Introduccion de fechas
            printf("\n\n\tIntroduzaca la fecha con el siguiente formato DD/MM/AAAA\n\n");
            do{

                printf("\r Introduzca la fecha de la ultima venta: ");
                fflush(stdin);
                productos[f].ultima_venta[0]=getch();
                printf("%c",productos[f].ultima_venta[0]);
                fflush(stdin);
                productos[f].ultima_venta[1]=getch();
                printf("%c",productos[f].ultima_venta[1]);
                printf("/");
                productos[f].ultima_venta[2]='/';
                fflush(stdin);
                productos[f].ultima_venta[3]=getch();
                printf("%c",productos[f].ultima_venta[3]);
                fflush(stdin);
                productos[f].ultima_venta[4]=getch();
                printf("%c",productos[f].ultima_venta[4]);
                printf("/");
                productos[f].ultima_venta[5]='/';
                fflush(stdin);
                productos[f].ultima_venta[6]=getch();
                printf("%c",productos[f].ultima_venta[6]);
                fflush(stdin);
                productos[f].ultima_venta[7]=getch();
                printf("%c",productos[f].ultima_venta[7]);
                fflush(stdin);
                productos[f].ultima_venta[8]=getch();
                printf("%c",productos[f].ultima_venta[8]);
                fflush(stdin);
                productos[f].ultima_venta[9]=getch();
                printf("%c",productos[f].ultima_venta[9]);
                productos[f].ultima_venta[10]='\0';

                if(date_check(productos[f].ultima_venta)==0){

                    printf(" \r Fecha introducida no valida; presione cualquier tecla para continuar...  ");
                    getch();
                    printf("\r                                                                                 ");

                }

            }while(date_check(productos[f].ultima_venta)==0);

            printf("\n\n");

            do{

                printf("\r Introduzca la fecha de la ultima compra: ");
                fflush(stdin);
                productos[f].ultima_compra[0]=getch();
                printf("%c",productos[f].ultima_compra[0]);
                fflush(stdin);
                productos[f].ultima_compra[1]=getch();
                printf("%c",productos[f].ultima_compra[1]);
                printf("/");
                productos[f].ultima_compra[2]='/';
                fflush(stdin);
                productos[f].ultima_compra[3]=getch();
                printf("%c",productos[f].ultima_compra[3]);
                fflush(stdin);
                productos[f].ultima_compra[4]=getch();
                printf("%c",productos[f].ultima_compra[4]);
                printf("/");
                productos[f].ultima_compra[5]='/';
                fflush(stdin);
                productos[f].ultima_compra[6]=getch();
                printf("%c",productos[f].ultima_compra[6]);
                fflush(stdin);
                productos[f].ultima_compra[7]=getch();
                printf("%c",productos[f].ultima_compra[7]);
                fflush(stdin);
                productos[f].ultima_compra[8]=getch();
                printf("%c",productos[f].ultima_compra[8]);
                fflush(stdin);
                productos[f].ultima_compra[9]=getch();
                printf("%c",productos[f].ultima_compra[9]);
                productos[f].ultima_compra[10]='\0';

                if(date_check(productos[f].ultima_compra)==0){
                    printf(" \r Fecha introducida no valida; presione cualquier tecla para continuar...  ");
                    getch();
                    printf("\r                                                                                 ");
                }

                for(i=0;i<12;i++){
                    matriz_compras[i][f]=0;
                    matriz_ventas[i][f]=0;
                }

            }while(date_check(productos[f].ultima_compra)==0);


            //Guardar datos introducidos anteriormente
            do{
                printf("\n\n\tDesea almacenar los datos introducidos en un formulario de producto (S/N) ");
                fflush(stdin);
                save=toupper(getchar());

                if(save=='S'){

                    productos[f].flag=1;
                    for(i==0;i<12;i++){

                        matriz_compras[i][f]=0;
                        matriz_ventas[i][f]=0;

                    }

                }

            }while((save!='N')&&(save!='S'));

        }
            printf("\n\n\tDesea salir de ALTA DE UN PRODUCTO (S/N) ");
            fflush(stdin);
            exit=toupper(getchar());


    }while(exit=='N');

}

/***************************************
Subprograma: Baja de un producto     Tipo: Procedimiento
Prerrequisitos: Vector de productos.
Objetivo: Buscca un producto el cual este dado de alta en el programa y cambia su estado a dado de baja; de manera que el programa no lo tenga en cuenta en
            posteriores procedimientos.
***************************************/
void BajaProducto(item productos[]){

    char delete_item[]=" -   ", save;
    int i, redo;

    do{

        system("cls");
        printf("\n\n\t BAJA DE UN PRODUCTO");

        printf("\n\n Introduzca el codigo del producto: ");
        fflush(stdin);
        delete_item[0]=toupper(getch());
        printf("%c",delete_item[0]);
        printf("-");
        fflush(stdin);
        delete_item[2]=getch();
        printf("%c",delete_item[2]);
        fflush(stdin);
        delete_item[3]=getch();
        printf("%c",delete_item[3]);
        fflush(stdin);
        delete_item[4]=getch();
        printf("%c",delete_item[4]);


        for(i=0;((strcmp(delete_item,productos[i].codigo)!=0)||(productos[i].flag!=1))&&(i<MAXPRODUCTOS);i++){

        }
        //i--;

        if((strcmp(delete_item,productos[i].codigo)==0)&&(i<MAXPRODUCTOS)){

            do{

                printf("\n\n Esta seguro de que desea eliminar el producto %c-%c%c%c (S/N): ",delete_item[0],delete_item[2],delete_item[3],delete_item[4]);
                fflush(stdin);
                save=toupper(getchar());

                if(save=='S'){

                    productos[i].flag=0;
                    printf("\n\n\tEl producto %c-%c%c%c fue eliminado.\n\n",delete_item[0],delete_item[2],delete_item[3],delete_item[4]);
                    redo=0;

                }else{

                    if(save=='N'){

                        redo=0;

                    }else{

                        printf("\n\n\tEl valor introducido no es valido; prueba otra vez.\n\n");
                        redo=1;

                    }

                }

                system("pause");

            }while(redo==1);

            redo=0;

        }else{

            printf("\n\nNo existe el producto %c-%c%c%c en nuestra base de datos. \n",delete_item[0],delete_item[2],delete_item[3],delete_item[4]);
            system("pause");
            redo=1;

        }


    }while(redo==1);

}

/***************************************
Subprograma: Modificacion de un producto.      Tipo: Procedimiento
Prerrequisitos: Vector de productos.
Objetivo: Modificar los valores asignados a la estructura de un producto el cual este dado de ala.
***************************************/
void ModificacionProducto(item productos[]){

    char change_item[]=" -   \0", rescute, redo;
    int i, option, hay;// unsigned %u

    do{

        system("cls");
        printf("\n\n\t MODIFICACI�N DE UN PRODUCTO");
        printf("\n\n Introduzca el codigo del producto: ");

        fflush(stdin);
        change_item[0]=toupper(getch());
        printf("%c",change_item[0]);
        printf("-");
        fflush(stdin);
        change_item[2]=getch();
        printf("%c",change_item[2]);
        fflush(stdin);
        change_item[3]=getch();
        printf("%c",change_item[3]);
        fflush(stdin);
        change_item[4]=getch();
        printf("%c",change_item[4]);

        for(i=0,hay=0;(i<MAXPRODUCTOS)&&hay==0;i++){

            if(strcmp(change_item,productos[i].codigo)==0){

                hay=productos[i].flag;

            }

        }

        if(hay==1){

            redo='S';

        }else{

            printf("\n\n\tEl producto no se encuentra en nuestra base de datos; ");
            system("pause");
            printf("\n\n\tDesea salir (S/N): ");
            redo=toupper(getchar());

        }


    }while(redo=='N');

    i--;

    if(hay==1){

        do{

            system("cls");
            printf("\n\tMODIFICANDO PRODUCTO ");

            puts(change_item);
            printf("\n\n Selecciona el dato a modificar:\n");
            printf("\n\t1 Nombre: ");
            puts(productos[i].nombre);
            printf("\t2  Precio de compra: %.2f",productos[i].precio_compra);
            printf("\n\t3  Precio de venta: %.2f",productos[i].precio_venta);
            printf("\n\t4  Estock actual: %i",productos[i].stock_actual);
            printf("\n\t5  Estock m�nimo: %i",productos[i].stock_min);
            printf("\n\t6  Estock m�ximo: %i",productos[i].stock_max);
            printf("\n\t7  Unidades compradas: %i",productos[i].total_compradas);
            printf("\n\t8  Unidades vendidas: %i",productos[i].total_vendidas);
            printf("\n\t9  �ltima compra: ");
            puts(productos[i].ultima_compra);
            printf("\t10 �ltima venta: ");
            puts(productos[i].ultima_venta);
            printf("\n\t0 Guardar y salir.\n\n Opci�n -> ");

            fflush(stdin);
            scanf("%i",&option);

            printf(" Nuevo valor -> ");

            switch(option){

            case 1:
                fflush(stdin);
                fgets(productos[i].nombre,20,stdin);
                break;
            case 2:
                fflush(stdin);
                scanf("%f",&productos[i].precio_compra);
                break;
            case 3:
                fflush(stdin);
                scanf("%f",&productos[i].precio_venta);
                break;
            case 4:
                fflush(stdin);
                scanf("%i",&productos[i].stock_actual);
                break;
            case 5:
                fflush(stdin);
                scanf("%i",&productos[i].stock_min);
                break;
            case 6:
                fflush(stdin);
                scanf("%i",&productos[i].stock_max);
                break;
            case 7:
                fflush(stdin);
                scanf("%i",&productos[i].total_compradas);
                break;
            case 8:
                fflush(stdin);
                scanf("%i",&productos[i].total_vendidas);
                break;
            case 9:
                printf("\n\n\tIntroduzaca la fecha con el siguiente formato DD/MM/AAAA\n\n");
                do{

                    printf("\r Introduzca la fecha de la ultima venta: ");
                    fflush(stdin);
                    productos[i].ultima_venta[0]=getch();
                    printf("%c",productos[i].ultima_venta[0]);
                    fflush(stdin);
                    productos[i].ultima_venta[1]=getch();
                    printf("%c",productos[i].ultima_venta[1]);
                    printf("/");
                    productos[i].ultima_venta[2]='/';
                    fflush(stdin);
                    productos[i].ultima_venta[3]=getch();
                    printf("%c",productos[i].ultima_venta[3]);
                    fflush(stdin);
                    productos[i].ultima_venta[4]=getch();
                    printf("%c",productos[i].ultima_venta[4]);
                    printf("/");
                    productos[i].ultima_venta[5]='/';
                    fflush(stdin);
                    productos[i].ultima_venta[6]=getch();
                    printf("%c",productos[i].ultima_venta[6]);
                    fflush(stdin);
                    productos[i].ultima_venta[7]=getch();
                    printf("%c",productos[i].ultima_venta[7]);
                    fflush(stdin);
                    productos[i].ultima_venta[8]=getch();
                    printf("%c",productos[i].ultima_venta[8]);
                    fflush(stdin);
                    productos[i].ultima_venta[9]=getch();
                    printf("%c",productos[i].ultima_venta[9]);
                    productos[i].ultima_venta[10]='\0';

                    if(date_check(productos[i].ultima_venta)==0){

                        printf(" \r Fecha introducida no valida; presione cualquier tecla para continuar...  ");
                        getch();
                        printf("\r                                                                                 ");

                    }

                }while(date_check(productos[i].ultima_venta)==0);
                break;
            case 10:
                printf("\n\n\tIntroduzaca la fecha con el siguiente formato DD/MM/AAAA\n\n");
                do{

                    printf("\r Introduzca la fecha de la ultima compra: ");
                    fflush(stdin);
                    productos[i].ultima_compra[0]=getch();
                    printf("%c",productos[i].ultima_compra[0]);
                    fflush(stdin);
                    productos[i].ultima_compra[1]=getch();
                    printf("%c",productos[i].ultima_compra[1]);
                    printf("/");
                    productos[i].ultima_compra[2]='/';
                    fflush(stdin);
                    productos[i].ultima_compra[3]=getch();
                    printf("%c",productos[i].ultima_compra[3]);
                    fflush(stdin);
                    productos[i].ultima_compra[4]=getch();
                    printf("%c",productos[i].ultima_compra[4]);
                    printf("/");
                    productos[i].ultima_compra[5]='/';
                    fflush(stdin);
                    productos[i].ultima_compra[6]=getch();
                    printf("%c",productos[i].ultima_compra[6]);
                    fflush(stdin);
                    productos[i].ultima_compra[7]=getch();
                    printf("%c",productos[i].ultima_compra[7]);
                    fflush(stdin);
                    productos[i].ultima_compra[8]=getch();
                    printf("%c",productos[i].ultima_compra[8]);
                    fflush(stdin);
                    productos[i].ultima_compra[9]=getch();
                    printf("%c",productos[i].ultima_compra[9]);
                    productos[i].ultima_compra[10]='\0';

                    if(date_check(productos[i].ultima_compra)==0){

                        printf(" \r Fecha introducida no valida; presione cualquier tecla para continuar...  ");
                        getch();
                        printf("\r                                                                                 ");

                    }

                }while(date_check(productos[i].ultima_compra)==0);

                break;
            case 0://S
                break;

            }

        }while(option!=0);

    }

}

/***************************************
Subprograma: Consulta producto      Tipo: Procedimiento
Prerrequisitos: Vector productos.
Objetivo: Muestra todos los datos almacenados en la estructua de un producto dado de alta.
***************************************/
void ConsultaProducto(const item productos[]){

    char change_item[]=" -   \0", rescute, redo;
    int i, option, hay;// unsigned %u

    do{

        system("cls");
        printf("\n\n\t CONSULTA PRODUCTO");
        printf("\n\n Introduzca el codigo del producto: ");
        fflush(stdin);
        change_item[0]=toupper(getch());
        printf("%c",change_item[0]);
        printf("-");
        fflush(stdin);
        change_item[2]=getch();
        printf("%c",change_item[2]);
        fflush(stdin);
        change_item[3]=getch();
        printf("%c",change_item[3]);
        fflush(stdin);
        change_item[4]=getch();
        printf("%c",change_item[4]);

        for(i=0,hay=0;(i<MAXPRODUCTOS)&&hay==0;i++){

            if(strcmp(change_item,productos[i].codigo)==0){

                hay=productos[i].flag;

            }

        }

        if(hay==1){

            redo='S';

        }else{

            printf("\n\n\tEl producto no se encuentra en nuestra base de datos;");
            system("pause");
            printf("\n\n\tDesea salir (S/N): ");
            redo=toupper(getchar());

        }

    }while(redo=='N');

    i--;

    if(hay==1){

            system("cls");
            printf("\n\tPRODUCTO ");
            puts(change_item);
            printf("\n\tNombre: ");
            puts(productos[i].nombre);
            printf("\tPrecio de compra: %.2f",productos[i].precio_compra);
            printf("\n\tPrecio de venta: %.2f",productos[i].precio_venta);
            printf("\n\tEstock actual: %i",productos[i].stock_actual);
            printf("\n\tEstock m�nimo: %i",productos[i].stock_min);
            printf("\n\tEstock m�ximo: %i",productos[i].stock_max);
            printf("\n\tUnidades compradas: %i",productos[i].total_compradas);
            printf("\n\tUnidades vendidas: %i",productos[i].total_vendidas);
            printf("\n\t�ltima compra: ");
            puts(productos[i].ultima_compra);
            printf("\t�ltima venta: ");
            puts(productos[i].ultima_venta);

    }

    printf("\n\n\t");
    system("pause");

}

/***************************************
Subprograma: Compra de productos.     Tipo: Procedimiento
Prerrequisitos: Vector productos; matriz compras.
Objetivo: Modifica los valores relacionados con las compras de un cierto producto almacenado en la "base de datos".
***************************************/
void CompraProductos(item productos[],float matriz_compras[][MAXPRODUCTOS]){

    char change_item[]=" -   \0", rescute, redo ,mels[2];
    int i, io, f, option, hay, posible_compra, compra;// unsigned %u

    do{

        system("cls");
        printf("\n\n\t CONSULTA PRODUCTO");
        printf("\n\n Introduzca el codigo del producto: ");
        fflush(stdin);
        change_item[0]=toupper(getch());
        printf("%c",change_item[0]);
        printf("-");
        fflush(stdin);
        change_item[2]=getch();
        printf("%c",change_item[2]);
        fflush(stdin);
        change_item[3]=getch();
        printf("%c",change_item[3]);
        fflush(stdin);
        change_item[4]=getch();
        printf("%c",change_item[4]);

        for(i=0,hay=0;(i<MAXPRODUCTOS)&&hay==0;i++){

            if(strcmp(change_item,productos[i].codigo)==0){

                hay=productos[i].flag;

            }

        }

        if(hay==1){

             do{

                i--;
                system("cls");
                posible_compra=(productos[i].stock_max)-(productos[i].stock_actual);
                printf("\n\n Maxima cantidad de producto %s a comprar %i: ",productos[i].codigo,posible_compra);
                scanf("%i",&compra);

                if(compra>=0&&compra<=posible_compra){

                    productos[i].stock_actual+=compra;
                    productos[i].total_compradas+=compra;
                    printf("\n\n\tIntroduzaca la fecha con el siguiente formato DD/MM/AAAA\n\n");

                    do{

                        printf("\r Introduzca la fecha de la ultima compra: ");
                        fflush(stdin);
                        productos[i].ultima_compra[0]=getch();
                        printf("%c",productos[i].ultima_compra[0]);
                        fflush(stdin);
                        productos[i].ultima_compra[1]=getch();
                        printf("%c",productos[i].ultima_compra[1]);
                        printf("/");
                        productos[i].ultima_compra[2]='/';
                        fflush(stdin);
                        productos[i].ultima_compra[3]=getch();
                        printf("%c",productos[i].ultima_compra[3]);
                        fflush(stdin);
                        productos[i].ultima_compra[4]=getch();
                        printf("%c",productos[i].ultima_compra[4]);
                        printf("/");
                        productos[i].ultima_compra[5]='/';
                        fflush(stdin);
                        productos[i].ultima_compra[6]=getch();
                        printf("%c",productos[i].ultima_compra[6]);
                        fflush(stdin);
                        productos[i].ultima_compra[7]=getch();
                        printf("%c",productos[i].ultima_compra[7]);
                        fflush(stdin);
                        productos[i].ultima_compra[8]=getch();
                        printf("%c",productos[i].ultima_compra[8]);
                        fflush(stdin);
                        productos[i].ultima_compra[9]=getch();
                        printf("%c",productos[i].ultima_compra[9]);
                        productos[i].ultima_compra[10]='\0';

                        if(date_check(productos[i].ultima_compra)==0){

                            printf(" \r Fecha introducida no valida; presione cualquier tecla para continuar...  ");
                            getch();
                            printf("\r                                                                                 ");

                        }

                    }while(date_check(productos[i].ultima_compra)==0);

                    mels[0]=productos[i].ultima_compra[3];
                    mels[1]=productos[i].ultima_compra[4];

                    matriz_compras[(atoi(mels)-1)][i]+=compra;

                    printf("\n\n La operacion fue realizada.\n ");
                    system("pause");

                }else{

                    printf("\n\n\tLa cantidad que desea comprar no es posible.");
                    system("pause");

                }

            }while(compra<0&&compra>posible_compra);

        }else{

            printf("\n\n\tEl producto no se encuentra en nuestra base de datos;");
            system("pause");
            printf("\n\n\tDesea salir (S/N): ");
            redo=toupper(getchar());

        }

    }while(redo=='N');

}

/***************************************
Subprograma: Venta de productos.     Tipo: Procedimiento
Prerrequisitos: Vector productos; matriz ventas.
Objetivo: Modifica los valores relacionados con las ventas de un cierto producto almacenado en la "base de datos".
***************************************/
void VentaProductos(item productos[],float matriz_ventas[][MAXPRODUCTOS]){

    char change_item[]=" -   \0", rescute, redo ,mels[2];
    int i, io, f, option, hay, posible_venta, venta;// unsigned %u

    do{

        system("cls");
        printf("\n\n\t CONSULTA PRODUCTO");
        printf("\n\n Introduzca el codigo del producto: ");
        fflush(stdin);
        change_item[0]=toupper(getch());
        printf("%c",change_item[0]);
        printf("-");
        fflush(stdin);
        change_item[2]=getch();
        printf("%c",change_item[2]);
        fflush(stdin);
        change_item[3]=getch();
        printf("%c",change_item[3]);
        fflush(stdin);
        change_item[4]=getch();
        printf("%c",change_item[4]);

        for(i=0,hay=0;(i<MAXPRODUCTOS)&&hay==0;i++){

            if(strcmp(change_item,productos[i].codigo)==0){

                hay=productos[i].flag;

            }

        }

        if(hay==1){

             do{

                i--;
                system("cls");
                posible_venta=(productos[i].stock_actual)-(productos[i].stock_min);
                printf("\n\n Maxima cantidad de producto %s a vender %i: ",productos[i].codigo,posible_venta);
                scanf("%i",&venta);

                if(venta>=0&&venta<=posible_venta){

                    productos[i].stock_actual-=venta;
                    productos[i].total_vendidas+=venta;
                    printf("\n\n\tIntroduzaca la fecha con el siguiente formato DD/MM/AAAA\n\n");

                    do{

                        printf("\r Introduzca la fecha de la ultima venta: ");
                        fflush(stdin);
                        productos[i].ultima_venta[0]=getch();
                        printf("%c",productos[i].ultima_venta[0]);
                        fflush(stdin);
                        productos[i].ultima_venta[1]=getch();
                        printf("%c",productos[i].ultima_venta[1]);
                        printf("/");
                        productos[i].ultima_venta[2]='/';
                        fflush(stdin);
                        productos[i].ultima_venta[3]=getch();
                        printf("%c",productos[i].ultima_venta[3]);
                        fflush(stdin);
                        productos[i].ultima_venta[4]=getch();
                        printf("%c",productos[i].ultima_venta[4]);
                        printf("/");
                        productos[i].ultima_venta[5]='/';
                        fflush(stdin);
                        productos[i].ultima_venta[6]=getch();
                        printf("%c",productos[i].ultima_venta[6]);
                        fflush(stdin);
                        productos[i].ultima_venta[7]=getch();
                        printf("%c",productos[i].ultima_venta[7]);
                        fflush(stdin);
                        productos[i].ultima_venta[8]=getch();
                        printf("%c",productos[i].ultima_venta[8]);
                        fflush(stdin);
                        productos[i].ultima_venta[9]=getch();
                        printf("%c",productos[i].ultima_venta[9]);
                        productos[i].ultima_venta[10]='\0';

                        if(date_check(productos[i].ultima_venta)==0){

                            printf(" \r Fecha introducida no valida; presione cualquier tecla para continuar...  ");
                            getch();
                            printf("\r                                                                                 ");

                        }

                    }while(date_check(productos[i].ultima_venta)==0);

                    mels[0]=productos[i].ultima_venta[3];
                    mels[1]=productos[i].ultima_venta[4];

                    matriz_ventas[(atoi(mels)-1)][i]+=venta;

                    printf("\n\n La operacion fue realizada.\n ");
                    system("pause");

                }else{

                    printf("\n\n\tLa cantidad que desea vender no es posible.");
                    system("pause");
                }

            }while(venta<0&&venta>posible_venta);

        }else{

            printf("\n\n\tEl producto no se encuentra en nuestra base de datos;");
            system("pause");
            printf("\n\n\tDesea salir (S/N): ");
            redo=toupper(getchar());
        }

    }while(redo=='N');

}

/***************************************
Subprograma: Capitalizacion de productos.     Tipo: Procedimiento
Prerrequisitos: Vector productos.
Objetivo: estandariza los nombres de los productos de manera que la primera letra sea mayuscula y el resto minusculas.
***************************************/
void CapitalizarNombreProductos(item productos[]){

    int i,cont;

    for(i=0;i<MAXPRODUCTOS;i++){

        if(productos[i].flag==1){

            productos[i].nombre[0]=toupper(productos[i].nombre[0]);

            for(cont=1;cont<strlen(productos[i].nombre);cont++){

                productos[i].nombre[cont]=tolower(productos[i].nombre[cont]);

            }

        }

    }

}

/***************************************
Subprograma: Comprobador de fecha.     Tipo: Procedimiento
Prerrequisitos: String de fecha en el siguiente formato(DD/MM/AAAA).
Objetivo: Comprueva que los dias sean coherentes con el mes ademas de siel a�o es bisiesto o no.
***************************************/
int date_check(const char date[]){

    int day,mounth,year;
    char dias[3], meses[3], annos[5];

    dias[0]=date[0];
    dias[1]=date[1];

    meses[0]=date[3];
    meses[1]=date[4];

    annos[0]=date[6];
    annos[1]=date[7];
    annos[2]=date[8];
    annos[3]=date[9];

    day=atoi(dias);
    mounth=atoi(meses);
    year=atoi(annos);

    switch(mounth){

        case 1:

            if(day<=31){

                return 1;

            }else{

                return 0;

            }
            break;
        case 2:
            if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){

                if(day<=29){

                    return 1;

                }else{

                    return 0;

                }
            }else{

                if(day<=28){

                    return 1;

                }else{

                    return 0;
                }
            }

            break;
        case 3:
            if(day<=31){

                return 1;

            }else{

                return 0;

            }
            break;
        case 4:
            if(day<=30){

                return 1;

            }else{

                return 0;

            }
            break;
        case 5:
            if(day<=31){

                return 1;

            }else{

                return 0;

            }
            break;
        case 6:
            if(day<=30){

                return 1;

            }else{

                return 0;

            }
            break;
        case 7:
            if(day<=31){

                return 1;

            }else{

                return 0;

            }
            break;
        case 8:
            if(day<=31){

                return 1;

            }else{

                return 0;

            }
            break;
        case 9:
            if(day<=30){

                return 1;

            }else{

                return 0;

            }
            break;
        case 10:
            if(day<=31){

                return 1;

            }else{

                return 0;

            }
            break;
        case 11:
            if(day<=30){

                return 1;

            }else{

                return 0;

            }
            break;
        case 12:
            if(day<=31){

                return 1;

            }else{

                return 0;

            }
            break;
        default:
            return 0;
            break;

    }

}

/***************************************
Subprograma: Menu de informes.     Tipo: Procedimiento
Prerrequisitos: Vector productos; matriz compras y matriz ventas.
Objetivo: Al igual que que el menu anterior; muestra las opciones a escojer y ordena el codigo a la hora de encajar los diversos procedimientos.
***************************************/
void MenuInformes(float matriz_ventas[][MAXPRODUCTOS], item productos[], float matriz_compras[][MAXPRODUCTOS]){

    int opcion;

    do{

        system("cls");

        printf("\n\tMEN� INFORMES");
        printf("\n\n\t1 - Listado General");
        printf("\n\t2 - Listado General Simplificado");
        printf("\n\t3 - Listado de productos con stock m�nimo");
        printf("\n\t4 - Listado de compras registradas en un determinado mes");
        printf("\n\t5 - Listado de ventas registradas de un producto");
        printf("\n\n\t6 - Producto m�s comprado en un determinado mes");
        printf("\n\t7 - Mes que ha registrado menos ventas");
        printf("\n\n\t8 - Venta total registrada en un determinado mes");
        printf("\n\t9 - Venta total registrada de un determinado producto");
        printf("\n\t10 - Venta total registrada en el a�o");
        printf("\n\t11 - Importe medio de ventas (meses pares)");
        printf("\n\t12 - Contar productos (por mes de �ltima venta)");
        printf("\n\n\t0 - Volver al Men� Principal");
        printf("\n\t____________________________________________________________________________");
        printf("\n\n\tElija opci�n: ");
        fflush(stdin);
        scanf("%i", &opcion);

        switch(opcion){

            case 1:
                    ListadoGeneral(productos);
                    break;
            case 2:
                    ListadoGeneralSimplificado(productos);
                    break;
            case 3:
                    ListadoProductosConStockMinimo(productos);
                    break;
            case 4:
                    ListadoComprasMes(productos, matriz_compras);
                    break;
            case 5:
                    ListadoVentasProducto(productos,matriz_ventas);
                    break;
            case 6:
                    ProductoMasCompradoMes(productos,matriz_compras);
                    break;
            case 7:
                    MesMenosVentas(matriz_ventas);
                    break;
            case 8:
                    VentaTotalMes(matriz_ventas);
                    break;
            case 9:
                    VentaTotalProducto(productos, matriz_ventas);
                    break;
            case 10:
                    VentaTotalAnno(matriz_ventas);
                    break;
            case 11:
                    ImporteMedioVentasMesesPares(matriz_ventas);
                    break;
            case 12:
                ContarProductosMesUltimaVenta(matriz_ventas, productos);
                    break;
            case 0:
                    break;
            default:
                    MensajeError();
                    break;

        }

    }while(opcion != 0);

}

/***************************************
Subprograma: Listado general.     Tipo: Procedimiento
Prerrequisitos: Vector productos.
Objetivo: Muestra los datos asociados a cada producto; lo hace manera secuncial recorriendo todos los productos dados de alta.
***************************************/
void ListadoGeneral(item productos[]){

    int producto = 0, num_productos = 0;

    while(producto < MAXPRODUCTOS){

        if(productos[producto].flag == 1){

            system("cls");

            printf("\n\tLISTADO GENERAL DE PRODUCTOS\n\n");
            printf("\t\tPRODUCTO %i", num_productos + 1);
            printf("\n\t\t=============");

            printf("\n\n\t\tC�digo de producto\t: %s", productos[producto].codigo);
            printf("\n\t\tNombre del producto\t: %s", productos[producto].nombre);
            printf("\n\t\tPrecio de compra (euros): %.2f", productos[producto].precio_compra);
            printf("\n\t\tPrecio de venta (euros)\t: %.2f", productos[producto].precio_venta);
            printf("\n\t\tStock Actual (unidades)\t: %i", productos[producto].stock_actual);
            printf("\n\t\tStock M�nimo\t\t: %i", productos[producto].stock_min);
            printf("\n\t\tStock M�ximo\t\t: %i", productos[producto].stock_max);
            printf("\n\t\tUnidades compradas\t: %i", productos[producto].total_compradas);
            printf("\n\t\tUnidades vendidas\t: %i", productos[producto].total_vendidas);
            printf("\n\t\tFecha �ltima compra\t: %s", productos[producto].ultima_compra);
            printf("\n\t\tFecha �ltima venta\t: %s", productos[producto].ultima_venta);

            printf("\n\n\n\t\tPulse <Intro> para continuar...");

            fflush(stdin);
            getchar();

            num_productos++;

        }

        producto++;

    }

    if(num_productos == 0){

        system("cls");

        printf("\n\tNo hay ning�n producto registrado.");
        printf("\n\n\tPulse Intro para continuar...");
        fflush(stdin);
        getchar();

    }

}

/***************************************
Subprograma: Listado general simplificado.     Tipo: Procedimiento
Prerrequisitos: Vector productos.
Objetivo: Simplificacion del de arriva. Muestra todos los productos en una tabla con sus precios, codigo, nombre y stock asociados.
***************************************/
void ListadoGeneralSimplificado(item productos[]){

    int producto = 0, num_productos = 0, prod_pagina = 0;

    system("cls");
    printf("\n\t\t\t\tLISTADO GENERAL DE PRODUCTOS\n\n");
    printf("C�digo               Nombre  Precio de compra  Precio de venta  Stock actual  St. m�nimo  St. m�ximo");
    printf("\n----------------------------------------------------------------------------------------------------");

    while(producto < MAXPRODUCTOS){

        if(productos[producto].flag == 1){

            printf("\n%s  %20s\t%.2f\t\t%.2f\t\t%i\t\t%i\t\t%i",productos[producto].codigo, productos[producto].nombre, productos[producto].precio_compra, productos[producto].precio_venta, productos[producto].stock_actual, productos[producto].stock_min, productos[producto].stock_max);

            num_productos++;
            prod_pagina++;

        }

        producto++;

        if(prod_pagina == 15){

            printf("\n\n\t\tPulse <Intro> para continuar...");
            fflush(stdin);
            getchar();

            prod_pagina = 0;

            system("cls");
            printf("\n\t\t\t\tLISTADO GENERAL DE PRODUCTOS\n\n");
            printf("C�digo               Nombre  Precio de compra  Precio de venta  Stock actual  St. m�nimo  St. m�ximo");
            printf("\n----------------------------------------------------------------------------------------------------");

        }

    }

    if(num_productos == 0){

        system("cls");

        printf("\n\tNo hay ning�n producto registrado.");
        printf("\n\n\tPulse Intro para continuar...");
        fflush(stdin);
        getchar();

    }else{

        printf("\n.....");
        printf("\n\n\t\tPulse <Intro> para finalizar...");
        fflush(stdin);
        getchar();

    }

}

/***************************************
Subprograma: Listado productos con estock minimo.     Tipo: Procedimiento
Prerrequisitos: Vector productos.
Objetivo: Muestra por pantalla un listado de todos los productos del almac�n (c�digo, nombre y stock actual) que hayan registrado ventas por un importe mayor
al introducido por el usuario y cuyo stock actual sea el m�nimo posible para �l.
***************************************/
void ListadoProductosConStockMinimo(item productos[]){

    float importe;
    int producto = 0;
    char letra;

    system("cls");
    printf("\n\tLISTADO DE PRODUCTOS CON STOCK M�NIMO\n\n");
    printf("\t\tIntroduzca un importe: ");
    fflush(stdin);
    scanf("%f", &importe);
    printf("\n\t\tIntroduzca una letra: ");
    fflush(stdin);
    scanf("%c", &letra);
    if((letra <= 122) && (letra >= 97))
        letra -= 32;


    while(producto < MAXPRODUCTOS){

        if(productos[producto].flag == 1){

            if(productos[producto].codigo[0] == letra){

                if(productos[producto].precio_venta * productos[producto].total_vendidas > importe){

                    if(productos[producto].stock_actual <= productos[producto].stock_min){

                        system("cls");
                        printf("\n\tLISTADO DE PRODUCTOS CON STOCK M�NIMO");

                        printf("\n\n\t\tC�digo: %s \tNombre: %s", productos[producto].codigo, productos[producto].nombre);
                        printf("\n\t\tStock Actual: %i", productos[producto].stock_actual);

                        printf("Pulsa Intro para continuar...");
                        fflush(stdin);
                        getchar();

                    }

                }

            }

        }

        producto++;

    }

}

/***************************************
Subprograma: Listado de las compras del mes.     Tipo: Procedimiento
Prerrequisitos: Vector productos y matriz compras.
Objetivo: Se muestra la coantidad de euros en compras de cada producto por mes.
***************************************/
void ListadoComprasMes(item productos[], float matriz_compras[][MAXPRODUCTOS]){

    int num_mes, x, redo;
    char mes[11];

    do{

        system("cls");
        printf("\n\tLISTADO DE COMPRAS MENSUAL");
        printf("\n\n\t\tIntroduce un mes (1 - 12): ");
        scanf("%i", &num_mes);
        redo=0;

        switch(num_mes){

            case 1: strcpy(mes, "ENERO");
                    break;
            case 2: strcpy(mes, "FEBRERO");
                    break;
            case 3: strcpy(mes, "MARZO");
                    break;
            case 4: strcpy(mes, "ABRIL");
                    break;
            case 5: strcpy(mes, "MAYO");
                    break;
            case 6: strcpy(mes, "JUNIO");
                    break;
            case 7: strcpy(mes, "JULIO");
                    break;
            case 8: strcpy(mes, "AGOSTO");
                    break;
            case 9: strcpy(mes, "SEPTIEMBRE");
                    break;
            case 10: strcpy(mes, "OCTUBRE");
                    break;
            case 11: strcpy(mes, "NOVIEMBRE");
                    break;
            case 12: strcpy(mes, "DICIEMBRE");
                    break;
            default: printf("\n\n  Opcion no correcta intentelo de nuevo.\n\n\t");
                     system("pause");
                     redo=1;
                    break;

        }

    }while(redo==1);

    system("cls");
    printf("\n\tLISTADO DE COMPRAS MENSUAL (%s)\n\n", mes);
    printf("\n\tProducto\tImporte(euros)\n\n");

    for(x=0;x<MAXPRODUCTOS;x++){

        if(productos[x].flag==1){

            printf("\t %s\t|\t%.2f\n",productos[x].codigo,(matriz_compras[num_mes-1][x]*productos[x].precio_compra));

        }

    }

    printf("\n\n\n\t");
    system("pause");

}

/***************************************
Subprograma: Listado ventas productos.     Tipo: Procedimiento
Prerrequisitos: Vector productos y matriz ventas.
Objetivo: Muestra el importe de un producto antes introducido por el usuario cada mes del a�o.
***************************************/
void ListadoVentasProducto(item productos[],float matriz_ventas[][MAXPRODUCTOS]){

    char change_item[]=" -   \0", redo ,mes[11];
    int i,  f, hay;

    do{

        system("cls");
        printf("\n\n\t CONSULTA PRODUCTO");
        printf("\n\n Introduzca el codigo del producto: ");
        fflush(stdin);
        change_item[0]=toupper(getch());
        printf("%c",change_item[0]);
        printf("-");
        fflush(stdin);
        change_item[2]=getch();
        printf("%c",change_item[2]);
        fflush(stdin);
        change_item[3]=getch();
        printf("%c",change_item[3]);
        fflush(stdin);
        change_item[4]=getch();
        printf("%c",change_item[4]);

        for(i=0,hay=0;(i<MAXPRODUCTOS)&&hay==0;i++){

            if(strcmp(change_item,productos[i].codigo)==0){

                hay=productos[i].flag;

            }

        }

        if(hay==1){
            //i--;
            system("cls");
            printf("\n\tLISTADO DE VENTAS DEL PRODUCTO %s",change_item);
            printf("\n\n\tMes\t\tImporte(euros)\n");
            printf("\t__________________________________\n");

            for(f=0;f<12;f++){

                switch(f+1){

                    case 1: strcpy(mes, "ENERO     ");
                            break;
                    case 2: strcpy(mes, "FEBRERO   ");
                            break;
                    case 3: strcpy(mes, "MARZO     ");
                            break;
                    case 4: strcpy(mes, "ABRIL     ");
                            break;
                    case 5: strcpy(mes, "MAYO      ");
                            break;
                    case 6: strcpy(mes, "JUNIO     ");
                            break;
                    case 7: strcpy(mes, "JULIO     ");
                            break;
                    case 8: strcpy(mes, "AGOSTO    ");
                            break;
                    case 9: strcpy(mes, "SEPTIEMBRE");
                            break;
                    case 10: strcpy(mes, "OCTUBRE  ");
                            break;
                    case 11: strcpy(mes, "NOVIEMBRE");
                            break;
                    case 12: strcpy(mes, "DICIEMBRE");
                            break;
                    default:
                            break;

                }
                printf("\n\t%s\t%.2f\n",mes,matriz_ventas[f][i]*productos[i].precio_venta);

            }

            printf("\n\n\t");
            system("pause");

        }else{
            printf("\n\n\tEl producto no se encuentra en nuestra base de datos;");
            system("pause");
            printf("\n\n\tDesea salir (S/N): ");
            redo=toupper(getchar());
        }

    }while(redo=='N');

}

/***************************************
Subprograma: Producto mas comprado de un determinado mes.     Tipo: Procedimiento
Prerrequisitos: Vector productos, matriz compras.
Objetivo: El usuario introduce un mes y el programa muestra por pantalla el producto mas comprado en dicho mes con informacion adicional.
***************************************/
void ProductoMasCompradoMes(item productos[], float matriz_compras[][MAXPRODUCTOS]){

    int num_mes, pos_mascomprado, i, primero = 1;
    char mes[11];

    do{

        system("cls");
        printf("\n\tPRODUCTO M�S COMPRADO EN UN MES");
        printf("\n\n\t\tIntroduce un mes (1 - 12): ");
        fflush(stdin);
        scanf("%i", &num_mes);

        if(num_mes < 0 || num_mes > 12){

            printf("\n\t\tIntroduzca un n�mero de mes correcto.");
            printf("\n\t\tPulse Intro para continuar...");
            fflush(stdin);
            getchar();

        }

    }while(num_mes < 0 || num_mes > 12);

    switch(num_mes){

        case 1: strcpy(mes, "ENERO");
                break;
        case 2: strcpy(mes, "FEBRERO");
                break;
        case 3: strcpy(mes, "MARZO");
                break;
        case 4: strcpy(mes, "ABRIL");
                break;
        case 5: strcpy(mes, "MAYO");
                break;
        case 6: strcpy(mes, "JUNIO");
                break;
        case 7: strcpy(mes, "JULIO");
                break;
        case 8: strcpy(mes, "AGOSTO");
                break;
        case 9: strcpy(mes, "SEPTIEMBRE");
                break;
        case 10: strcpy(mes, "OCTUBRE");
                break;
        case 11: strcpy(mes, "NOVIEMBRE");
                break;
        case 12: strcpy(mes, "DICIEMBRE");
                break;
    }

    system("cls");
    printf("\n\tPRODUCTO M�S COMPRADO EN %s", mes);

    num_mes -= 1;

    for(i = 0; i < MAXPRODUCTOS; i++){

        if(productos[i].flag == 1){

            if(primero == 1){

                pos_mascomprado = i;
                primero = 0;

            }

            if(matriz_compras[num_mes][i] > matriz_compras[num_mes][pos_mascomprado]){

                pos_mascomprado = i;

            }

        }

    }

    printf("\n\n\t\tC�digo: %s", productos[pos_mascomprado].codigo);
    printf("\n\t\tNombre: %s", productos[pos_mascomprado].nombre);
    printf("\n\t\tImporte comprado: %.2f", matriz_compras[num_mes][pos_mascomprado]);

    printf("\n\n\t\tPulse Intro para continuar...");
    fflush(stdin);
    getchar();

}

/***************************************
Subprograma: Mes con menos ventas registradas.     Tipo: Procedimiento
Prerrequisitos: Matriz ventas.
Objetivo: Muestra en pantalla el mes con menos ventas registradas e informacion adicional.
***************************************/
void MesMenosVentas(float matriz_ventas[][MAXPRODUCTOS]){

    float min_ventas = 0, suma_ventas = 0;
    int num_mes;
    int i, j;
    char mes[11];

    for(i = 0; i <= 11; i++){

        suma_ventas = 0;

        for(j = 0; j <= (MAXPRODUCTOS - 1); j++){

            suma_ventas += matriz_ventas[i][j];

        }

        if(i == 0){

            min_ventas = suma_ventas;
            num_mes = 1;

        }

        if(suma_ventas < min_ventas){

            min_ventas = suma_ventas;
            num_mes = i + 1;

        }

    }

    switch(num_mes){

        case 1: strcpy(mes, "ENERO");
                break;
        case 2: strcpy(mes, "FEBRERO");
                break;
        case 3: strcpy(mes, "MARZO");
                break;
        case 4: strcpy(mes, "ABRIL");
                break;
        case 5: strcpy(mes, "MAYO");
                break;
        case 6: strcpy(mes, "JUNIO");
                break;
        case 7: strcpy(mes, "JULIO");
                break;
        case 8: strcpy(mes, "AGOSTO");
                break;
        case 9: strcpy(mes, "SEPTIEMBRE");
                break;
        case 10: strcpy(mes, "OCTUBRE");
                break;
        case 11: strcpy(mes, "NOVIEMBRE");
                break;
        case 12: strcpy(mes, "DICIEMBRE");
                break;
        default: strcpy(mes, "");
                break;

    }

    system("cls");
    printf("\n\tMES QUE HA REGISTRADO MENOS VENTAS");
    printf("\n\n\tEl mes que ha registrado menos ventas es %s\n\tcon un importe total de %.2f euros.", mes, min_ventas);
    printf("\n\n\tPulse Intro para continuar...");
    fflush(stdin);
    getchar();

}

/***************************************
Subprograma: Ventas totales en un mes.     Tipo: Procedimiento
Prerrequisitos: Matriz ventas.
Objetivo: Muentra la cantidad de euros de las ventas registradas en un determinado mes.
***************************************/
void VentaTotalMes(float matriz_ventas[][MAXPRODUCTOS]){

    int num_mes, i;
    char mes[11];
    float total = 0;

    do{

        system("cls");
        printf("\n\tVENTA TOTAL REGISTRADA DE UN MES");
        printf("\n\n\t\tIntroduce un mes (1 - 12): ");
        fflush(stdin);
        scanf("%i", &num_mes);

        if(num_mes < 0 || num_mes > 12){

            printf("\n\t\tIntroduzca un n�mero de mes correcto.");
            printf("\n\t\tPulse Intro para continuar...");
            fflush(stdin);
            getchar();

        }

    }while(num_mes < 0 || num_mes > 12);

    switch(num_mes){

        case 1: strcpy(mes, "ENERO");
                break;
        case 2: strcpy(mes, "FEBRERO");
                break;
        case 3: strcpy(mes, "MARZO");
                break;
        case 4: strcpy(mes, "ABRIL");
                break;
        case 5: strcpy(mes, "MAYO");
                break;
        case 6: strcpy(mes, "JUNIO");
                break;
        case 7: strcpy(mes, "JULIO");
                break;
        case 8: strcpy(mes, "AGOSTO");
                break;
        case 9: strcpy(mes, "SEPTIEMBRE");
                break;
        case 10: strcpy(mes, "OCTUBRE");
                break;
        case 11: strcpy(mes, "NOVIEMBRE");
                break;
        case 12: strcpy(mes, "DICIEMBRE");
                break;
    }

    num_mes -= 1;

    system("cls");
    printf("\n\tVENTA TOTAL REGISTRADA DE %s", mes);

    for(i=0; i < MAXPRODUCTOS; i++){

        total += matriz_ventas[num_mes][i];

    }

    printf("\n\n\t\tEl importe total registrado en el mes de %s ha sido %.2f euros.", mes, total);
    printf("\n\n\t\tPulse Intro para continuar...");
    fflush(stdin);
    getchar();

}

/***************************************
Subprograma: Ventas totales de productos.     Tipo: Procedimiento
Prerrequisitos: Vector productos, matriz ventas.
Objetivo: Muestra el importe de las ventas anuales de un producto introducido por el ususario.
***************************************/
void VentaTotalProducto(item productos[], float matriz_ventas[][MAXPRODUCTOS]){

    char codigop[5];
    int i, hay, j;
    float importeventas = 0;

    do{
        system("cls");
        printf("\n\tINFORME DE VENTAS TOTALES");
        printf("\n\n\t\tIntroduzca el codigo del producto: ");
        fflush(stdin);
        codigop[0]=toupper(getch());
        printf("%c",codigop[0]);
        printf("-");
        codigop[1]='-';
        fflush(stdin);
        codigop[2]=getch();
        printf("%c",codigop[2]);
        fflush(stdin);
        codigop[3]=getch();
        printf("%c",codigop[3]);
        fflush(stdin);
        codigop[4]=getch();
        printf("%c",codigop[4]);
        codigop[5]='\0';

        if((65>codigop[0]&&codigop[0]<90)||(48>codigop[2]||codigop[2]>57)||(48>codigop[3]||codigop[3]>57)||(48>codigop[4]||codigop[4]>57)){

            printf("\n\n\t\tC�digo no valido.");
            printf("\n\t\tPulse Intro para continuar...");
            fflush(stdin);
            getchar();

        }

    }while((65>codigop[0]&&codigop[0]<90)||(48>codigop[2]||codigop[2]>57)||(48>codigop[3]||codigop[3]>57)||(48>codigop[4]||codigop[4]>57));

    for(i=0,hay=0;(i<MAXPRODUCTOS)&&hay==0;i++){

            if(strcmp(codigop,productos[i].codigo)==0){

                hay = productos[i].flag;

            }

    }

    system("cls");
    printf("\n\tINFORME DE VENTAS TOTALES");

    if(hay == 1){

        for(j = 0; j < 12; j++){

            importeventas += matriz_ventas[j][i];

        }

        printf("\n\n\t\tC�digo del producto:\t%s", productos[i].codigo);
        printf("\n\t\tNombre:\t\t\t%s", productos[i].nombre);
        printf("\n\t\tUnidades vendidas:\t%i", productos[i].total_vendidas);
        printf("\n\t\tImporte Total Ventas:\t%.2f", importeventas);

        printf("\n\n\t\tPulse Intro para finalizar...");
        fflush(stdin);
        getchar();

    }else{

        printf("\n\n\t\tNo existe un producto con ese c�digo.");
        printf("\n\t\tPulse Intro para finalizar...");
        fflush(stdin);
        getchar();

    }

}

/***************************************
Subprograma: Ventas totales del a�o.     Tipo: Procedimiento
Prerrequisitos: Matriz ventas.
Objetivo: Muestra por pantalla el importe en euros de las ventas anuales de todos los productos dados de alta.
***************************************/
void VentaTotalAnno(float matriz_ventas[][MAXPRODUCTOS]){

    int i,j;
    float total = 0;

    for(i = 0;i <= 12; i++){

        for(j = 0; j < MAXPRODUCTOS; j++){

            total += matriz_ventas[i][j];

        }

    }

    system("cls");
    printf("\n\tVENTA TOTAL REGISTRADA EN EL A�O");
    printf("\n\n\t\tEl importe total registrado por las ventas ha sido %.2f euros.", total);
    printf("\n\n\t\tPulse Intro para continuar...");
    fflush(stdin);
    getchar();

}

/***************************************
Subprograma: Importe medio ventas meses pares.     Tipo: Procedimiento
Prerrequisitos: Matriz ventas.
Objetivo: Muestra en pantalla el importe medio de las ventas de los meses pares en euros.
***************************************/
void ImporteMedioVentasMesesPares(float matriz_ventas[][MAXPRODUCTOS]){

    int i,j;
    float total = 0;

    for(i = 0;i <= 12; i++){

        if(i % 2 == 0){

            for(j = 0; j < MAXPRODUCTOS; j++){

                total += matriz_ventas[i][j];

            }

        }

    }

    system("cls");
    printf("\n\tIMPORTE MEDIO REGISTRADO POR LAS VENTAS (MESES PARES)");
    printf("\n\n\t\tEl importe total registrado por las ventas en los meses pares ha sido %.2f euros.", total);
    printf("\n\n\t\tPulse Intro para continuar...");
    fflush(stdin);
    getchar();

}

/***************************************
Subprograma: Productos mes ultima venta.     Tipo: Procedimiento
Prerrequisitos: Vector productos; matriz ventas.
Objetivo: Muestra el numero de productos que han sido vendidos en el ultimo mes con actividad segun la matriz ventas.
***************************************/
void ContarProductosMesUltimaVenta(float matriz_ventas[][MAXPRODUCTOS],item productos[]){

    int num_mes, x, redo, p_ventas;
    char mes[11];

    do{
        system("cls");
        printf("\n\tLISTADO DE COMPRAS MENSUAL");
        printf("\n\n\t\tIntroduce un mes (1 - 12): ");
        scanf("%i", &num_mes);
        redo=0;

        switch(num_mes){

            case 1: strcpy(mes, "ENERO");
                    break;
            case 2: strcpy(mes, "FEBRERO");
                    break;
            case 3: strcpy(mes, "MARZO");
                    break;
            case 4: strcpy(mes, "ABRIL");
                    break;
            case 5: strcpy(mes, "MAYO");
                    break;
            case 6: strcpy(mes, "JUNIO");
                    break;
            case 7: strcpy(mes, "JULIO");
                    break;
            case 8: strcpy(mes, "AGOSTO");
                    break;
            case 9: strcpy(mes, "SEPTIEMBRE");
                    break;
            case 10: strcpy(mes, "OCTUBRE");
                    break;
            case 11: strcpy(mes, "NOVIEMBRE");
                    break;
            case 12: strcpy(mes, "DICIEMBRE");
                    break;
            default: printf("\n\n  Opcion no correcta intentelo de nuevo.\n\n\t");
                     system("pause");
                     redo=1;
                    break;

        }

    }while(redo==1);

    for(x=0,p_ventas=0;x<MAXPRODUCTOS;x++){

        if((productos[x].flag==1)&&(matriz_ventas[num_mes-1][x]!=0)){

            p_ventas+=1;

        }

    }

    system("cls");
    printf("\n\tHay %i productos que se vendieron por ultima vez en %s\n\n",p_ventas ,mes);
    printf("\n\n\n\t");
    system("pause");

}
