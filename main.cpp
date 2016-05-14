#include <iostream>
#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int codigo;
    char nombre[50];
    char numero_contacto[16];
    char direccion[50];
    char tipo_entrega[100];
    char material[40];
}Proveedor;

void menu();
void ListarProveedores();
void AltaProveedor();
void BajaProveedor();
void ModificarProveedor();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int opcion;
    do{
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
    printf("   1) Consulta Proveedores \n");
    printf("   2) Alta Proveedor \n");
    printf("   3) Baja Proveedor \n");
    printf("   4) Modificar Proovedor \n");
    printf("   5) Salir\n");
    printf("-------------------------------------------\n");
    printf("-------------------------------------------\n");
    scanf("%d",&opcion);
    getchar();
    system("clear");


    switch (opcion){
        case 1:
            ListarProveedores();
            break;
        case 2:
            AltaProveedor();
            break;
        case 3:
            BajaProveedor();
            break;
        case 4:
            ModificarProveedor();
            break;
        case 5:
            return;
            break;
    }
    }
    while(opcion!=5);
}

void ListarProveedores()
{
    FILE *CatalogoProveedores;
    Proveedor prove;
    CatalogoProveedores = fopen("CatProveedores.dat","rb");
    fread(&prove,sizeof(Proveedor),1,CatalogoProveedores);
    while(!feof(CatalogoProveedores)){
        printf("%d ; %s ; %s ; %s ; %s ; %s\n",prove.codigo, prove.nombre,prove.numero_contacto, prove.direccion,prove.tipo_entrega,prove.material);
        fread(&prove,sizeof(Proveedor),1,CatalogoProveedores);
    }
    fclose(CatalogoProveedores);

}

void AltaProveedor()
{
    FILE *CatalogoProveedores;
    Proveedor prove;
    CatalogoProveedores = fopen("CatProveedores.dat","ab");
    printf("     Ingrese codigo:\n");
    scanf("%d",&prove.codigo);
    printf("     Ingrese Nombre Proveedor: ");
    scanf("%s",prove.nombre);
    printf("     Ingrese Numero de Contacto: ");
    scanf("%s",prove.numero_contacto);
    printf("     Ingrese Direccion: ");
    scanf("%s",prove.direccion);
    printf("     Ingrese Tipo Entrega: ");
    scanf("%s",prove.tipo_entrega);
    printf("     Ingrese Material: ");
    scanf("%s",prove.material);
    fseek(CatalogoProveedores,0L,SEEK_END);
    fwrite(&prove,sizeof(Proveedor),1,CatalogoProveedores);
    fclose(CatalogoProveedores);
    printf("Se creo proveedor exitosamente!");
    getchar();
    system("clear");
    menu();
}

void BajaProveedor()
{
    FILE *CatalogoProveedores,*pfaux;
    Proveedor prove;
    int codigoaux;
    CatalogoProveedores = fopen("CatProveedores.dat","rb");
    pfaux = fopen("CatProveedoresaux.dat","ab");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&prove,sizeof(Proveedor),1,CatalogoProveedores);
        while (!feof(CatalogoProveedores)){
                if (prove.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prove,sizeof(Proveedor),1,pfaux);
                }
            fread(&prove,sizeof(Proveedor),1,CatalogoProveedores);
        }
    fclose(CatalogoProveedores);
    fclose(pfaux);
    remove("CatProveedores.dat");
    rename("CatProveedoresaux.dat","CatProveedores.dat");
    system("clear");
}

void ModificarProveedor()
{
    FILE *CatalogoProveedores,*pfaux;
    Proveedor prove;
    int codigoaux;
    CatalogoProveedores = fopen("CatProveedores.dat","rb");
    pfaux = fopen("CatProveedoresaux.dat","ab");
    printf("Ingrese Código\n");
    scanf("%i",&codigoaux);
    fread(&prove,sizeof(Proveedor),1,CatalogoProveedores);
        while (!feof(CatalogoProveedores)){
                if (prove.codigo != codigoaux){
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prove,sizeof(Proveedor),1,pfaux);
                }else{
//                    printf("     Ingrese codigo: ");
//    				scanf("%d",&prove.codigo);
    				printf("     Ingrese Nombre Proveedor: ");
    				scanf("%s",prove.nombre);
    				printf("     Ingrese Numero de Contacto: ");
    				scanf("%s",prove.numero_contacto);
				    printf("     Ingrese Direccion: ");
				    scanf("%s",prove.direccion);
				    printf("     Ingrese Tipo Entrega: ");
				    scanf("%s",prove.tipo_entrega);
				    printf("     Ingrese Material: ");
				    scanf("%s",prove.material);
                    fseek(pfaux,0l,SEEK_END);
                    fwrite(&prove,sizeof(Proveedor),1,pfaux);
                }
            fread(&prove,sizeof(Proveedor),1,CatalogoProveedores);
        }
    fclose(CatalogoProveedores);
    fclose(pfaux);
    remove("CatProveedores.dat");
    rename("CatProveedoresaux.dat","CatProveedores.dat");
    system("clear");
}
